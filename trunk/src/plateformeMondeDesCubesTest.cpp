#include "plateformeMondeDesCubesTest.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(plateformeMondeDesCubesTest);

void plateformeMondeDesCubesTest::setUp(void)
{
  //initialisation
  ea1 = new Cube();
  ea2 = new Cube();
  ea3 = new Cube();
  ea4 = new Cube();
  ea5 = new Cube();
  ea6 = new Cube();
  ea7 = new Cube();
  ea8 = new Cube();
  ea9 = new Cube();
  ea10 = new Cube();
  p = PlateformeMondeDesCubes::getInstance();
  p->addEcoAgent(*ea1);
  p->addEcoAgent(*ea2);
  p->addEcoAgent(*ea3);
  p->addEcoAgent(*ea4);
  p->addEcoAgent(*ea5);
  p->addEcoAgent(*ea6);
  p->addEcoAgent(*ea7);
  p->addEcoAgent(*ea8);
  p->addEcoAgent(*ea9);
  p->addEcoAgent(*ea10);
}


void plateformeMondeDesCubesTest::tearDown(void)
{
  //destructeur
  delete ea1;
  delete ea2;
  delete ea3;
  delete ea4;
  delete ea5;
  delete ea6;
  delete ea7;
  delete ea8;
  delete ea9;
  delete ea10;
  PlateformeMondeDesCubes::kill();
}


void plateformeMondeDesCubesTest::setTest(void)
{
  // Test des set et get nombre de cubes
  p->setNombreDeCubes(10);
  CPPUNIT_ASSERT_EQUAL(p->getNombreDeCubes(), 10);

  // Test des set et get nombre de cubes
  p->setNombreDeCubes(-10);
  CPPUNIT_ASSERT_EQUAL(p->getNombreDeCubes(), 0);

  // Test setTableIdentifiant et getTableID
  EcoAgentID *tid1 = new EcoAgentID(),
    *tid2 = p->getTableID();
  p->setTableIdentifiant(*tid1);
  CPPUNIT_ASSERT( tid1 == p->getTableID() && p->getTableID() != tid2);
	
  // Test setPositionFinale
  tid1 = ea1->getPositionFinale();
  tid2 = new EcoAgentID();
  p->setPositionFinale(*(ea1->getId()),*tid2);
  CPPUNIT_ASSERT(tid1 != tid2 && ea1->getPositionFinale() != tid1 && ea1->getPositionFinale() == tid2);

  // Test setPositionCourante
  tid1 = ea1->getPositionCourante();
  tid2 = new EcoAgentID();
  p->setPositionCourante(*(ea1->getId()),*tid2);
  CPPUNIT_ASSERT(tid1 != tid2 && ea1->getPositionCourante() != tid1 && ea1->getPositionCourante() == tid2);

  // Test setCubeID
  tid1 = ea1->getId();
  tid2 = new EcoAgentID();
  p->setCubeID(*ea1,*tid2);
  CPPUNIT_ASSERT(tid1 != tid2 && ea1->getId() != tid1 && ea1->getId() == tid2);
	
	
}


void plateformeMondeDesCubesTest::getTest(void)
{
  //test initialiser
  /*
   * ea1 : SATISFAIT
   * ea2 : RECHERCHESATISFACTION
   * ea3 : RECHERCHESATISFACTION
   * ea4 : SATISFACTION
   * table : SATISFAIT
   *
   */
  ea1->setPositionCourante(*(p->getTableID()));
  ea1->setPositionFinale(*(p->getTableID()));
  
  ea2->setPositionCourante(*(ea1->getId()));
  ea2->setPositionFinale(*(p->getTableID()));

  ea3->setPositionCourante(*(ea2->getId()));
  ea3->setPositionFinale(*(ea1->getId()));

  ea4->setPositionCourante(*(ea3->getId()));
  ea4->setPositionFinale(*(ea3->getId()));

  CPPUNIT_ASSERT(ea1->getEtat() == UNDEFINED && ea2->getEtat() == UNDEFINED && ea3->getEtat() == UNDEFINED && ea4->getEtat() == UNDEFINED);
  p->initialiser();
  CPPUNIT_ASSERT(ea1->getEtat() == SATISFAIT && ea2->getEtat() == RECHERCHESATISFACTION && ea3->getEtat() == RECHERCHESATISFACTION && ea4->getEtat() == SATISFAIT);

  //test distanceFinaleATable
  CPPUNIT_ASSERT(p->distanceFinaleATable(*(ea1->getId())) == 0);
  CPPUNIT_ASSERT(p->distanceFinaleATable(*(ea2->getId())) == 0); 
  CPPUNIT_ASSERT(p->distanceFinaleATable(*(ea3->getId())) == 1);
  CPPUNIT_ASSERT(p->distanceFinaleATable(*(ea4->getId())) == 2);

  //test obtenirGeneur
  CPPUNIT_ASSERT(p->obtenirGeneur(*ea1) == NULL);
  CPPUNIT_ASSERT(p->obtenirGeneur(*ea2) == ea3);
  CPPUNIT_ASSERT(p->obtenirGeneur(*ea3) == ea4);
  CPPUNIT_ASSERT(p->obtenirGeneur(*ea4) == NULL);


  //test resoudre
  //test obtenirCubePrioritaire

}

