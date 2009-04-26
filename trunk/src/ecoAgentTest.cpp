#include "ecoAgentTest.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(ecoAgentTest);

void ecoAgentTest::setUp(void)
{
	//initialisation des variables dont vous aurez besoin
	p = PlateformeMondeDesCubes::getInstance();
}


void ecoAgentTest::tearDown(void)
{
	//destructeur
	PlateformeMondeDesCubes::kill();
}


void ecoAgentTest::doTest(void)
{
	// Tests
}

