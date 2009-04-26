#include "regleTest.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(regleTest);

void regleTest::setUp(void)
{
	//initialisation des variables dont vous aurez besoin
	p = PlateformeMondeDesCubes::getInstance();
}


void regleTest::tearDown(void)
{
	//destructeur
	PlateformeMondeDesCubes::kill();
}


void regleTest::doTest(void)
{
	// Tests
}

