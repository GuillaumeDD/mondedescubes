#ifndef __CUBETEST__
#define __CUBETEST__
#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>
#include "plateformeMondeDesCubes.hpp"
#include "cube.hpp"
	
using namespace std;

class cubeTest : public CPPUNIT_NS :: TestFixture
{
  CPPUNIT_TEST_SUITE (cubeTest);
  CPPUNIT_TEST (initEtatTest);
  CPPUNIT_TEST (agressionTest);
  CPPUNIT_TEST (RFTest);
  CPPUNIT_TEST (RSTest);
  CPPUNIT_TEST (fuiteTest);
  CPPUNIT_TEST (satisfactionTest);
  CPPUNIT_TEST (agirTest);
  CPPUNIT_TEST_SUITE_END ();

public:
  void setUp (void);
  void tearDown (void);

protected:
  void initEtatTest (void);
  void agressionTest (void);
  void RFTest (void);
  void RSTest (void);
  void satisfactionTest (void);
  void fuiteTest (void);
  void agirTest (void);

private:
  PlateformeMondeDesCubes *p;
  Cube *c1,
    *c2,
    *c3,
    *c4,
    *c5,
    *c6,
    *c7;
  Table *t;
};

#endif
