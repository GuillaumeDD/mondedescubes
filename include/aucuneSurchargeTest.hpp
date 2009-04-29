#ifndef __AUCUNESURCHARGETEST__
#define __AUCUNESURCHARGETEST__
	#include<cppunit/TestFixture.h>
	#include<cppunit/extensions/HelperMacros.h>
	#include "aucuneSurcharge.hpp"
	
	using namespace std;

	class aucuneSurchargeTest : public CPPUNIT_NS :: TestFixture
	{
    CPPUNIT_TEST_SUITE (aucuneSurchargeTest);
    CPPUNIT_TEST (verifierTest);
    CPPUNIT_TEST (pasSurchargesTest);
    CPPUNIT_TEST (serontPasSurchargesTest);
    CPPUNIT_TEST_SUITE_END ();

    public:
        void setUp (void);
        void tearDown (void);

    protected:
        void verifierTest (void);
        void pasSurchargesTest (void);
        void serontPasSurchargesTest (void);

    private:
		AucuneSurcharge *nosurcharge;
		PlateformeMondeDesCubes *p;
		Cube *c1,
		     *c2,
		     *c3,
		     *c4;
		EcoAgentID *id1, *id2, *id3, *id4;
		// Mettre ici les variables dont vous avez besoin pendant les tests
	};

#endif
