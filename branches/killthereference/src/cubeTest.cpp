#include "cubeTest.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(cubeTest);

void cubeTest::setUp(void)
{
  //initialisation
  p = PlateformeMondeDesCubes::getInstance();
  c1= new Cube();
  c2= new Cube();
  c3= new Cube();
  c4= new Cube();
  p->addEcoAgent(*c1);
  p->addEcoAgent(*c2);
  p->addEcoAgent(*c3);
  p->addEcoAgent(*c4);

}


void cubeTest::tearDown(void)
{
  //destructeur
  delete c1;
  delete c2;
  delete c3;
  delete c4;
  PlateformeMondeDesCubes::kill();
}


void cubeTest::initEtatTest(void)
{
  // Initialisation de l'etat si la position finale et la position courante sont égales
  EcoAgentID *id1 = new EcoAgentID();
  c1->setPositionCourante(*id1);
  c1->setPositionFinale(*id1);
  c1->initialiser();
  CPPUNIT_ASSERT(c1->getEtat()==SATISFAIT);

  // Initialisation de l'etat si la position finale et la position courante sont differentes
  EcoAgentID *id2 = new EcoAgentID();
  c1->setPositionCourante(*id1);
  c1->setPositionFinale(*id2);
  c1->initialiser();
  CPPUNIT_ASSERT(c1->getEtat()==RECHERCHESATISFACTION);
}

void cubeTest::agressionTest(void)
{
  // Test methode estAgresse()
  c2->setEtat(SATISFAIT);
  c3->setEtat(RECHERCHESATISFACTION);
  c4->setEtat(RECHERCHEFUITE);
  c2->estAgresse();
  c3->estAgresse();
  c4->estAgresse();
  CPPUNIT_ASSERT(c2->getEtat()==RECHERCHEFUITE && c3->getEtat()==RECHERCHEFUITE && c4->getEtat()==RECHERCHEFUITE);

  // Test methode agresser
  c4->setEtat(RECHERCHEFUITE);
  c2->setEtat(SATISFAIT);
  c3->setEtat(RECHERCHESATISFACTION);
  c1->agresser(*c2);
  c1->agresser(*c3);
  c1->agresser(*c4);
  CPPUNIT_ASSERT(c2->getEtat()==RECHERCHEFUITE);
  CPPUNIT_ASSERT(c3->getEtat()==RECHERCHEFUITE);
  CPPUNIT_ASSERT(c4->getEtat()==RECHERCHEFUITE);
	

}

void cubeTest::RFTest(void)
{
	

  c1->setPositionCourante(*(p->getTableID()));
  c1->setPositionFinale(*(p->getTableID()));
  c1->setEtat(SATISFAIT);
  
  c2->setPositionCourante(*(c1->getId()));
  c2->setPositionFinale(*(p->getTableID()));
  c2->setEtat(RECHERCHESATISFACTION);

  c3->setPositionCourante(*(c2->getId()));
  c3->setPositionFinale(*(c1->getId()));
  c3->setEtat(RECHERCHESATISFACTION);

  c4->setPositionCourante(*(c3->getId()));
  c4->setPositionFinale(*(c3->getId()));
  c4->setEtat(SATISFAIT);

  //RF: c3 geneur de c2
  c2->rechercherFuite();
  CPPUNIT_ASSERT(c2->getPositionCourante()==c1->getId() && c3->getEtat()==RECHERCHEFUITE);

  //RF: c4 geneur de c3
  c3->rechercherFuite();
  CPPUNIT_ASSERT(c3->getPositionCourante()==c2->getId() && c4->getEtat()==RECHERCHEFUITE);

  //RF: c4 n'a aucun geneur
  c4->rechercherFuite();
  CPPUNIT_ASSERT(c4->getPositionCourante()==p->getTableID() && c4->getEtat()==RECHERCHESATISFACTION);

  //RF: c3 n'a aucun geneur
  c3->rechercherFuite();
  CPPUNIT_ASSERT(c3->getPositionCourante()==p->getTableID() && c3->getEtat()==RECHERCHESATISFACTION);

}

void cubeTest::RSTest(void)
{

  c1->setPositionCourante(*(p->getTableID()));
  c1->setPositionFinale(*(p->getTableID()));
  c1->setEtat(SATISFAIT);
  
  c2->setPositionCourante(*(p->getTableID()));
  c2->setPositionFinale(*(c1->getId()));
  c2->setEtat(RECHERCHESATISFACTION);

  c3->setPositionCourante(*(p->getTableID()));
  c3->setPositionFinale(*(c4->getId()));
  c3->setEtat(RECHERCHESATISFACTION);

  c4->setPositionCourante(*(c3->getId()));
  c4->setPositionFinale(*(p->getTableID()));
  c4->setEtat(RECHERCHESATISFACTION);

  //RS: c3 est gêné par c4
  c3->rechercherSatisfaction();
  CPPUNIT_ASSERT(c4->getEtat() == RECHERCHEFUITE);

  //RS: c4 peut se satisfaire
  c4->rechercherSatisfaction();
  CPPUNIT_ASSERT(c4->getPositionCourante()==c4->getPositionFinale() && c4->getEtat() == SATISFAIT);

  //RS: c3 peut se satisfaire
  c3->rechercherSatisfaction();
  CPPUNIT_ASSERT(c3->getPositionCourante()==c3->getPositionFinale() && c3->getEtat() == SATISFAIT);

  //RS: c2 peut se satisfaire
  c2->rechercherSatisfaction();
  CPPUNIT_ASSERT(c2->getPositionCourante()==c2->getPositionFinale() && c2->getEtat() == SATISFAIT);
		
}

void cubeTest::fuiteTest(void)
{
  // Exemple c6 SATISFAIT
  EcoAgentID *id4 = new EcoAgentID();
  EcoAgentID *id5 = new EcoAgentID();
  id5=p->getTableID();
  c4->setPositionCourante(*id4);
  c4->setPositionFinale(*id4);
  c4->setEtat(SATISFAIT);
  c4->faireFuite();
  CPPUNIT_ASSERT(c4->getPositionCourante()==id5 && c4->getEtat()==RECHERCHESATISFACTION);
	
}

void cubeTest::satisfactionTest(void)
{
  // Exemple c7 en RECHERCHESATISFACTION
  EcoAgentID *id4 = new EcoAgentID();
  EcoAgentID *id5 = new EcoAgentID();
  c1->setPositionCourante(*id4);
  c1->setPositionFinale(*id5);
  c1->setEtat(RECHERCHESATISFACTION);
  c1->faireSatisfaction();
  CPPUNIT_ASSERT(c1->getPositionCourante()==id5 && c1->getEtat()==SATISFAIT);
	
	
}

void cubeTest::agirTest(void)
{
	
}



