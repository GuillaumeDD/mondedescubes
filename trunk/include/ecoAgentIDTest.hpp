#ifndef __ECOAGENTIDTEST__
#define __ECOAGENTIDTEST__
#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>
#include "plateformeMondeDesCubes.hpp"
#include "ecoAgentID.hpp"
	
using namespace std;

class ecoAgentIDTest : public CPPUNIT_NS :: TestFixture
{
  CPPUNIT_TEST_SUITE (ecoAgentIDTest);
  CPPUNIT_TEST (generateTest);
  CPPUNIT_TEST (egaliteTest);
  CPPUNIT_TEST_SUITE_END ();

public:
  void setUp (void);
  void tearDown (void);

protected:
  void generateTest (void);
  void egaliteTest (void);
private:
  EcoAgentID *eaid1, *eaid2;	  
};

#endif
