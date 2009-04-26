#include "reliesATableTest.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(reliesATableTest);

void reliesATableTest::setUp(void)
{
	//initialisation des variables dont vous aurez besoin
	p = PlateformeMondeDesCubes::getInstance();
}


void reliesATableTest::tearDown(void)
{
	//destructeur
	PlateformeMondeDesCubes::kill();
}


void reliesATableTest::doTest(void)
{
	// Tests
}

