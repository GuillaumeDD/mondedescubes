#include "aucuneSurchargeTest.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(aucuneSurchargeTest);

void aucuneSurchargeTest::setUp(void)
{
	//initialisation des variables dont vous aurez besoin
	p = PlateformeMondeDesCubes::getInstance();
}


void aucuneSurchargeTest::tearDown(void)
{
	//destructeur
	PlateformeMondeDesCubes::kill();
}


void aucuneSurchargeTest::doTest(void)
{
	// Tests
}

