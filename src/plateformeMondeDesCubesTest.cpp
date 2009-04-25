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

	// Test setTableIdentifiant et getTableID
	EcoAgentID *tid1 = new EcoAgentID(),
	*tid2 = p->getTableID();
	p->setTableIdentifiant(*tid1);
	CPPUNIT_ASSERT( tid1 == p->getTableID() && p->getTableID() != tid2);
}


void plateformeMondeDesCubesTest::getTest(void)
{
	
}
