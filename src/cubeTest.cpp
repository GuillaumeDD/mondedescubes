#include "cubeTest.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(cubeTest);

void cubeTest::setUp(void)
{
	//initialisation des variables dont vous aurez besoin
	p = PlateformeMondeDesCubes::getInstance();
}


void cubeTest::tearDown(void)
{
	//destructeur
	PlateformeMondeDesCubes::kill();
}


void cubeTest::doTest(void)
{
	// Tests
}

