#ifndef __TABLETEST__
#define __TABLETEST__
#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>
#include "plateformeMondeDesCubes.hpp"
#include "table.hpp"
	
using namespace std;

class tableTest : public CPPUNIT_NS :: TestFixture
{
  CPPUNIT_TEST_SUITE (tableTest);
  CPPUNIT_TEST (doTest);
  CPPUNIT_TEST_SUITE_END ();

public:
  void setUp (void);
  void tearDown (void);

protected:
  void doTest (void);

private:
  PlateformeMondeDesCubes *p;
  Table *t;
  EcoAgent *ea1;
	
};

#endif
