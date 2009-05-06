#ifndef __PLATEFORMEECORESOLUTIONTEST__
#define __PLATEFORMEECORESOLUTIONTEST__
#include<cppunit/TestFixture.h>
#include<cppunit/extensions/HelperMacros.h>
#include "plateformeMondeDesCubes.hpp"
	
using namespace std;

class Regletrue : public Regle{
public:
  void initialiser(){
  }
  bool verifier(){
    return true;
  }
};


class Reglefalse : public Regle{
public:
  void initialiser(){
  }
  bool verifier(){
    return false;
  }
};
class plateformeEcoResolutionTest : public CPPUNIT_NS :: TestFixture
{
  CPPUNIT_TEST_SUITE (plateformeEcoResolutionTest);
  CPPUNIT_TEST (addEcoAgentTest);
  CPPUNIT_TEST (addRegleTest);
  CPPUNIT_TEST (getEcoAgentTest);
  CPPUNIT_TEST (verificationRegleTest);
  CPPUNIT_TEST (sontSatisfaitsTest);
  CPPUNIT_TEST (getEcoAgentAuDessusTest);
  CPPUNIT_TEST (nombreEcoAgentAuDessusTest);
  CPPUNIT_TEST (getEcoAgentsEtatTest);
  CPPUNIT_TEST_SUITE_END ();

public:
  void setUp (void);
  void tearDown (void);

protected:
  void addEcoAgentTest (void);
  void addRegleTest (void);
  void getEcoAgentTest (void);
  void verificationRegleTest (void);
  void sontSatisfaitsTest (void);
  void getEcoAgentAuDessusTest (void);
  void nombreEcoAgentAuDessusTest (void);
  void getEcoAgentsEtatTest(void);
private:
  EcoAgent *ea1, 
    *ea2,
    *ea3;
  PlateformeEcoResolution *p;
  Regle* r;
};

#endif
