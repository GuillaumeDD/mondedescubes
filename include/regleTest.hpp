#ifndef __REGLETEST__
#define __REGLETEST__
	#include<cppunit/TestFixture.h>
	#include<cppunit/extensions/HelperMacros.h>
	#include "plateformeMondeDesCubes.hpp"
	#include "regle.hpp"
	
	using namespace std;

	class regleTest : public CPPUNIT_NS :: TestFixture
	{
    CPPUNIT_TEST_SUITE (regleTest);
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
