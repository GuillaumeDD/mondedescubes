#ifndef __AUCUNESURCHARGETEST__
#define __AUCUNESURCHARGETEST__
	#include<cppunit/TestFixture.h>
	#include<cppunit/extensions/HelperMacros.h>
	#include "aucuneSurcharge.hpp"
	
	using namespace std;

	class aucuneSurchargeTest : public CPPUNIT_NS :: TestFixture
	{
    CPPUNIT_TEST_SUITE (aucuneSurchargeTest);
    CPPUNIT_TEST (doTest);
    CPPUNIT_TEST_SUITE_END ();

    public:
        void setUp (void);
        void tearDown (void);

    protected:
        void doTest (void);

    private:
		PlateformeMondeDesCubes *p;
		// Mettre ici les variables dont vous avez besoin pendant les tests
	};

#endif
