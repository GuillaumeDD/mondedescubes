#include "reliesATableTest.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(reliesATableTest);

void reliesATableTest::setUp(void)
{
  //initialisation des variables

  p = PlateformeMondeDesCubes::getInstance();	
  id1 = new EcoAgentID();
  id2 = new EcoAgentID();
  id3 = new EcoAgentID();
  id4 = new EcoAgentID();
  id5 = new EcoAgentID();

  c1= new Cube(*id1);
  c2= new Cube(*id2);
  c3= new Cube(*id3);
  c4= new Cube(*id4);
  c5= new Cube();

  p->addEcoAgent(*c1);
  p->addEcoAgent(*c2);
  p->addEcoAgent(*c3);
  p->addEcoAgent(*c4);

  c1->setPositionCourante(*(p->getTableID()));
  c2->setPositionCourante(*id1);
  c3->setPositionCourante(*id2);
  c4->setPositionCourante(*id3);
	
  c1->setPositionFinale(*(p->getTableID()));
  c2->setPositionFinale(*id1);
  c3->setPositionFinale(*id2);
  c4->setPositionFinale(*id3);

  relies = new ReliesATable();

  c1->setVisite(false);
  c2->setVisite(false);
  c3->setVisite(false);
  c4->setVisite(false);
  c5->setVisite(false);
}


void reliesATableTest::tearDown(void)
{
  //destructeur
  delete c1;
  delete c2;
  delete c3;
  delete c4;
  delete c5;
  delete id1;
  delete id2;
  delete id3;
  delete id4;
  delete id5;
  delete relies;
  PlateformeMondeDesCubes::kill();
}


void reliesATableTest::verifierTest(void)
{
  //les cubes sont et seront relies a la table
  CPPUNIT_ASSERT(relies->verifier() == true);
		
  //les cubes sont relies mais un cube ne sera pas relies a la table
  c3->setPositionFinale(*id5);
  CPPUNIT_ASSERT(relies->verifier() == false);

  //un des cubes n'est pas relies mais les cubes seront relies a la table	
  c3->setPositionCourante(*id5);
  c3->setPositionFinale(*id2);	
  CPPUNIT_ASSERT(relies->verifier() == false);
		
  //un des cubes n'est pas et ne sera pas relie a la table
  c3->setPositionCourante(*id2);
  c1->setPositionCourante(*id4);	
  c1->setPositionFinale(*id5);
  CPPUNIT_ASSERT(relies->verifier() == false);
}

void reliesATableTest::estRelieATableTest(void)
{
  //le cube c4 est relie a la table de maniere indirecte

  CPPUNIT_ASSERT(relies->estRelieATable(*c4) == true);

  //les cube c2, c3 et c4 forment une boucle
  c1->setVisite(false);
  c2->setVisite(false);
  c3->setVisite(false);
  c4->setVisite(false);
  c2->setPositionCourante(*id4);
  CPPUNIT_ASSERT(relies->estRelieATable(*c4) == false);

  
  //le cube c5 n'est pas relie

  CPPUNIT_ASSERT(relies->estRelieATable(*c5) == false);

  //le cube c5 est relie a un cube non existant
  c5->setVisite(false);

  c5->setPositionCourante(*id5);
  CPPUNIT_ASSERT(relies->estRelieATable(*c5) == false);
  
}

void reliesATableTest::seraRelieATableTest(void)
{
  //le cube c4 sera relie a la table de maniere indirecte

  CPPUNIT_ASSERT(relies->seraRelieATable(*c4) == true);

  //les cube c2, c3 et c4 formeront une boucle
  c1->setVisite(false);
  c2->setVisite(false);
  c3->setVisite(false);
  c4->setVisite(false);
  c2->setPositionFinale(*id4);
  CPPUNIT_ASSERT(relies->seraRelieATable(*c4) == false);

  
  //le cube c5 ne sera pas relie

  CPPUNIT_ASSERT(relies->seraRelieATable(*c5) == false);

  //le cube c5 sera relie a un cube non existant
  c5->setVisite(false);

  c5->setPositionFinale(*id5);
  CPPUNIT_ASSERT(relies->seraRelieATable(*c5) == false);
  
}

