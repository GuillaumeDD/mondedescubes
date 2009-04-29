#ifndef __PLATEFORMEMONDEDESCUBESTEST__
#define __PLATEFORMEMONDEDESCUBESTEST__
#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>
#include "plateformeMondeDesCubes.hpp"
	
using namespace std;

class plateformeMondeDesCubesTest : public CPPUNIT_NS :: TestFixture
{
  CPPUNIT_TEST_SUITE (plateformeMondeDesCubesTest);
  CPPUNIT_TEST (setTest);
  CPPUNIT_TEST (getTest);
  CPPUNIT_TEST (obtenirCubePrioritaireTest);
  CPPUNIT_TEST_SUITE_END ();

public:
  void setUp (void);
  void tearDown (void);

protected:
  void setTest (void);
  void getTest (void);
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
