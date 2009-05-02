#ifndef __RELIESATABLETEST__
#define __RELIESATABLETEST__
	#include<cppunit/TestFixture.h>
	#include<cppunit/extensions/HelperMacros.h>
	#include "plateformeMondeDesCubes.hpp"
	#include "reliesATable.hpp"
	
	using namespace std;

	class reliesATableTest : public CPPUNIT_NS :: TestFixture
	{
    CPPUNIT_TEST_SUITE (reliesATableTest);
    CPPUNIT_TEST (verifierTest);
    CPPUNIT_TEST (seraRelieATableTest);
    CPPUNIT_TEST (estRelieATableTest);
    CPPUNIT_TEST_SUITE_END ();

    public:
        void setUp (void);
        void tearDown (void);

    protected:
        void verifierTest (void);
        void seraRelieATableTest (void);
        void estRelieATableTest (void);

    private:
		ReliesATable *relies;
		PlateformeMondeDesCubes *p;
		Cube *c1,
		     *c2,
		     *c3,
		     *c4,
		     *c5;
		EcoAgentID *id1, *id2, *id3, *id4, *id5;
		// Mettre ici les variables dont vous avez besoin pendant les tests
	};

#endif
