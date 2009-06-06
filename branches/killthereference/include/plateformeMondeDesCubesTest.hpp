#ifndef __PLATEFORMEMONDEDESCUBESTEST__
#define __PLATEFORMEMONDEDESCUBESTEST__
#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>
#include "plateformeMondeDesCubes.hpp"
	
using namespace std;

class plateformeMondeDesCubesTest : public CPPUNIT_NS :: TestFixture
{
  CPPUNIT_TEST_SUITE (plateformeMondeDesCubesTest);
  CPPUNIT_TEST (getNombreDeCubesTest);
  CPPUNIT_TEST (setTableIDTest);
  CPPUNIT_TEST (setPositionTest);
  CPPUNIT_TEST (setCubeIDTest);
  CPPUNIT_TEST (initialiserTest);
  CPPUNIT_TEST (distanceFinaleATableTest);
  CPPUNIT_TEST (obtenirGeneurTest);
  CPPUNIT_TEST (obtenirCubePrioritaireTest);
  CPPUNIT_TEST_SUITE_END ();

public:
  void setUp (void);
  void tearDown (void);

protected:
  void getNombreDeCubesTest (void);
  void setTableIDTest (void);
  void setPositionTest (void);
  void setCubeIDTest (void);
  void initialiserTest (void);
  void distanceFinaleATableTest (void);
  void obtenirGeneurTest (void);
  void obtenirCubePrioritaireTest (void);

private:
  EcoAgent *ea1, 
    *ea2,
    *ea3,
    *ea4,
    *ea5,
    *ea6,
    *ea7,
    *ea8,
    *ea9,
    *ea10;

  PlateformeMondeDesCubes *p;
};

#endif
