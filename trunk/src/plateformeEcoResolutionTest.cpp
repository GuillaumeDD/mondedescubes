#include "plateformeEcoResolutionTest.hpp"
#include "reliesATable.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(plateformeEcoResolutionTest);

void plateformeEcoResolutionTest::setUp(void)
{
  //initialisation
  ea1 = new Cube();
  ea2 = new Cube();
  ea3 = new Cube();
  r = new ReliesATable();
  p = PlateformeMondeDesCubes::getInstance();
  p->addEcoAgent(*ea2);
}


void plateformeEcoResolutionTest::tearDown(void)
{
  //destructeur
  delete ea1;
  delete ea2;
  delete ea3;
  PlateformeMondeDesCubes::kill();
}


void plateformeEcoResolutionTest::addEcoAgentTest(void)
{
  // Ajout d'un EcoAgent deja enregistre dans la plateforme
  CPPUNIT_ASSERT_THROW (p->addEcoAgent(*ea2), ExceptionEcoAgentDejaEnregistre);

  // Ajout d'un EcoAgent non enregistre dans la plateforme
  unsigned int temp1=0;
  temp1 = (p->getEcoAgents()).size();
  p->addEcoAgent(*ea3);
  CPPUNIT_ASSERT(temp1+1 == (p->getEcoAgents()).size());
  CPPUNIT_ASSERT_THROW (p->addEcoAgent(*ea3), ExceptionEcoAgentDejaEnregistre);
}

void plateformeEcoResolutionTest::addRegleTest(void){
  // Ajout d'une regle
  unsigned int temp1=0;
  temp1 = (p->getRegles()).size();
  p->addRegle(*r);
  CPPUNIT_ASSERT(temp1+1 == (p->getRegles()).size());
}

void plateformeEcoResolutionTest::getEcoAgentTest(void)
{
  // Recherche d'un EcoAgent inexistant dans la plateforme
  CPPUNIT_ASSERT(p->getEcoAgent(*(ea1->getId())) == NULL);
	
  //Recherche d'un EcoAgent existant dans la plateforme
  CPPUNIT_ASSERT(p->getEcoAgent(*(ea2->getId())) == ea2);
}


void plateformeEcoResolutionTest::sontSatisfaitsTest(void)
{
  //Test de satisfaction globale
  p->addEcoAgent(*ea1);
  // ea2 fait deja parti de la plateforme dans l'initialisation
  p->addEcoAgent(*ea3);
  ea1->setEtat(SATISFAIT);
  ea2->setEtat(SATISFAIT);
  ea3->setEtat(SATISFAIT);
  // Les 3 EcoAgents sont satisfaits
  CPPUNIT_ASSERT(p->sontSatisfaits() == true);

  //Test d'insatisfaction globale
  ea1->setEtat(RECHERCHESATISFACTION);
  /*
   * 2 EcoAgents sont SATISFAIT
   * 1 EcoAgent est RECHERCHESATISFACTION
   */
  CPPUNIT_ASSERT(p->sontSatisfaits() == false);
}

void plateformeEcoResolutionTest::getEcoAgentAuDessusTest(void){
  p->addEcoAgent(*ea1);
  // ea2 fait deja parti de la plateforme dans l'initialisation
  p->addEcoAgent(*ea3);

  // Test d'obtention de l'EcoAgent au dessus
  ea1->setPositionCourante(*(((PlateformeMondeDesCubes*)p)->getTableID()));
  ea2->setPositionCourante(*(((PlateformeMondeDesCubes*)p)->getTableID()));
  ea3->setPositionCourante(*(ea1->getId()));

  CPPUNIT_ASSERT(p->getEcoAgentAuDessus(*(ea1->getId())) == ea3->getId());

  CPPUNIT_ASSERT(p->getEcoAgentAuDessus(*(ea2->getId())) == NULL);
  CPPUNIT_ASSERT(p->getEcoAgentAuDessus(*(ea3->getId())) == NULL);
}

void plateformeEcoResolutionTest::nombreEcoAgentAuDessusTest(void){
  p->addEcoAgent(*ea1);
  // ea2 fait deja parti de la plateforme dans l'initialisation
  p->addEcoAgent(*ea3);
  ea1->setPositionCourante(*(((PlateformeMondeDesCubes*)p)->getTableID()));
  ea2->setPositionCourante(*(((PlateformeMondeDesCubes*)p)->getTableID()));
  ea3->setPositionCourante(*(ea1->getId()));

  // Test d'obtention du nombre d'EcoAgent au dessus
  CPPUNIT_ASSERT(p->nombreEcoAgentAuDessus(*(ea3->getId())) == 0);
  CPPUNIT_ASSERT(p->nombreEcoAgentAuDessus(*(ea1->getId())) == 1);
	
  EcoAgent* ea4 = new Cube();
  ea4->setEtat(SATISFAIT);
  p->addEcoAgent(*ea4);
  ea4->setPositionCourante(*(ea3->getId()));
  CPPUNIT_ASSERT(p->nombreEcoAgentAuDessus(*(ea1->getId())) == 2);
}

void plateformeEcoResolutionTest::getEcoAgentsEtatTest(void){
  p->addEcoAgent(*ea1);
  // ea2 fait deja parti de la plateforme dans l'initialisation
  p->addEcoAgent(*ea3);

  ea2->setEtat(SATISFAIT);
  ea3->setEtat(SATISFAIT);
  ea1->setEtat(RECHERCHESATISFACTION);

  EcoAgent* ea4 = new Cube();
  ea4->setEtat(SATISFAIT);
  p->addEcoAgent(*ea4);
  ea4->setPositionCourante(*(ea3->getId()));

  // Test d'obtention des agents ayant un Etat determine
  /*
   * Etat des choses :
   * 3 EcoAgents sont SATISFAIT
   * 1 EcoAgent est RECHERCHESATISFACTION
   */
  CPPUNIT_ASSERT(p->getEcoAgents(RECHERCHESATISFACTION).size() == 1);
  CPPUNIT_ASSERT(p->getEcoAgents(SATISFAIT).size() == 3);
  CPPUNIT_ASSERT(p->getEcoAgents(RECHERCHEFUITE).size() == 0);

  // Test d'obtention de l'ensemble des EcoAgents
  CPPUNIT_ASSERT(p->getEcoAgents().size() == 4);
	
}


void plateformeEcoResolutionTest::verificationRegleTest(void)
{
  unsigned int temp;	
  PlateformeMondeDesCubes::kill();
  p = PlateformeMondeDesCubes::getInstance();
	
  temp = p->getRegles().size();
  //verification des regles quand il n'y en a que 2 : aucuneSurcharge et reliesATable
  CPPUNIT_ASSERT(p->verifierCoherence() && temp == 2);
	
  //verification des regles
  p->addRegle(*(new Regletrue()));
  p->addRegle(*(new Regletrue()));
  p->addRegle(*(new Regletrue()));
  temp = p->getRegles().size();
  CPPUNIT_ASSERT(p->verifierCoherence() && temp > 0);
	
  //Verification des regles avec une regle non verifiee
  p->addRegle(*(new Reglefalse()));
  temp = p->getRegles().size();
  CPPUNIT_ASSERT(!p->verifierCoherence() && temp > 0);
	
}
