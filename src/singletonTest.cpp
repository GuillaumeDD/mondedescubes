#include "singletonTest.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(singletonTest);

void singletonTest::setUp(void)
{
  //initialisation des variables dont vous aurez besoin
  p1 = PlateformeMondeDesCubes::getInstance();
  p2 = PlateformeMondeDesCubes::getInstance();
  p3 = PlateformeMondeDesCubes::getInstance();
  p4 = PlateformeMondeDesCubes::getInstance();
}


void singletonTest::tearDown(void)
{
  //destructeur
  PlateformeMondeDesCubes::kill();
  p1 = p2 = p3 = p4 = NULL;
}


void singletonTest::getTest(void)
{
  //Test d'obtention de la meme instance
  CPPUNIT_ASSERT(p1 == p2 && p2 == p3 && p3 == p4 && p4 != NULL);
}


void singletonTest::killTest(void)
{
  // On detruit plusieurs fois l'instance
  PlateformeMondeDesCubes::kill();
  PlateformeMondeDesCubes::kill();
}
