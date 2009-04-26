#include "ecoAgentIDTest.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(ecoAgentIDTest);

void ecoAgentIDTest::setUp(void)
{
	//initialisation des variables dont vous aurez besoin
	p = PlateformeMondeDesCubes::getInstance();
}


void ecoAgentIDTest::tearDown(void)
{
	//destructeur
	PlateformeMondeDesCubes::kill();
}


void ecoAgentIDTest::doTest(void)
{
	// Tests
}

