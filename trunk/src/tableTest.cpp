#include "tableTest.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(tableTest);

void tableTest::setUp(void)
{
	//initialisation des variables dont vous aurez besoin
	p = PlateformeMondeDesCubes::getInstance();
}


void tableTest::tearDown(void)
{
	//destructeur
	PlateformeMondeDesCubes::kill();
}


void tableTest::doTest(void)
{
	// Tests
}

