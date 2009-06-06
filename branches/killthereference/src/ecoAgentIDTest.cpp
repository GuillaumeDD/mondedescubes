#include "ecoAgentIDTest.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(ecoAgentIDTest);

void ecoAgentIDTest::setUp(void)
{
  //initialisation des variables dont vous aurez besoin
  eaid1 = new EcoAgentID();
  eaid2 = new EcoAgentID();
}


void ecoAgentIDTest::tearDown(void)
{
  //destructeur
  delete eaid1;
  delete eaid2;
}

void ecoAgentIDTest::generateTest(void)
{
  // Test de l'incrementation du numero
  CPPUNIT_ASSERT((eaid1->getId()+1) == eaid2->getId());
}

void ecoAgentIDTest::egaliteTest(void)
{
  // Test d'egalite
  CPPUNIT_ASSERT(*eaid1 == *eaid1 && *eaid1 != *eaid2);

}
