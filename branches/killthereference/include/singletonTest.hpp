#ifndef __SINGLETONTEST__
#define __SINGLETONTEST__
#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>
#include "plateformeMondeDesCubes.hpp"
#include "singleton.hpp"
	
using namespace std;

class singletonTest : public CPPUNIT_NS :: TestFixture
{
  CPPUNIT_TEST_SUITE (singletonTest);
  CPPUNIT_TEST (getTest);
  CPPUNIT_TEST (killTest);
  CPPUNIT_TEST_SUITE_END ();

public:
  void setUp (void);
  void tearDown (void);

protected:
  void getTest (void);
  void killTest(void);
private:
  PlateformeMondeDesCubes *p1,*p2,*p3,*p4;
};

#endif
