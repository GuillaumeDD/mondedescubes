#include "singletonTest.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(singletonTest);

void singletonTest::setUp(void)
{
	//initialisation des variables dont vous aurez besoin
	p = PlateformeMondeDesCubes::getInstance();
}


void singletonTest::tearDown(void)
{
	//destructeur
	PlateformeMondeDesCubes::kill();
}


void singletonTest::doTest(void)
{
	// Tests
}

