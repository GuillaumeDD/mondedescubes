#ifndef __ECOAGENTTEST__
#define __AUCUNESURCHARGETEST__
	#include<cppunit/TestFixture.h>
	#include<cppunit/extensions/HelperMacros.h>
	#include "ecoAgent.hpp"
	#include "cube.hpp"
	
	using namespace std;

	class ecoAgentTest : public CPPUNIT_NS :: TestFixture
	{
    CPPUNIT_TEST_SUITE (ecoAgentTest);
    CPPUNIT_TEST (doTest);
    CPPUNIT_TEST_SUITE_END ();

    public:
        void setUp (void);
        void tearDown (void);

    protected:
        void doTest (void);

    private:
		EcoAgent *ea1,
			  		*ea2,
		     		*ea3,
		     		*ea4,
		     		*ea5;

	};

#endif
