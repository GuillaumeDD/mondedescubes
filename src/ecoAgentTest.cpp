#include "ecoAgentTest.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(ecoAgentTest);

void ecoAgentTest::setUp(void)
{
  //initialisation
  ea1=new Cube();
  ea2=new Cube();
  ea3=new Cube();
  ea4=new Cube();
  ea5=new Cube();
	
}


void ecoAgentTest::tearDown(void)
{
  //destructeur
  delete ea1;
  delete ea2;
  delete ea3;
  delete ea4;
  delete ea5;

}


void ecoAgentTest::doTest(void)
{
  // Tests des fonctions non virtuelles pures de la classe : Les getteurs et les setteurs

  // setId et getID
  EcoAgentID *id1= new EcoAgentID();
  EcoAgentID *id2 = new EcoAgentID();
  id2=ea1->getId();
  ea1->setId(*id1);
  CPPUNIT_ASSERT(ea1->getId()==id1 && ea1->getId()!=id2);


  // setEtat et getEtat
  // 1) etat indetermine
  CPPUNIT_ASSERT(ea3->getEtat()==UNDEFINED);
  // 2) etat determine
  ea2->setEtat(SATISFAIT);
  CPPUNIT_ASSERT(ea2->getEtat()==SATISFAIT);

  //setPositionCourante et getPositionCourante
  EcoAgentID *id3 = new EcoAgentID();
  EcoAgentID *id4 = new EcoAgentID();
  id4=ea4->getPositionCourante();
  ea4->setPositionCourante(*id3);
  CPPUNIT_ASSERT(ea4->getPositionCourante()==id3 && ea4->getPositionCourante()!=id4 && id4==NULL);

  //setPositionFinale et getPositionFinale
  EcoAgentID *id5 = new EcoAgentID();
  EcoAgentID *id6 = new EcoAgentID();
  id6=ea5->getPositionFinale();
  ea5->setPositionFinale(*id5);
  CPPUNIT_ASSERT(ea5->getPositionFinale()==id5 && ea5->getPositionFinale()!=id6 && id6==NULL);


	
	

}

