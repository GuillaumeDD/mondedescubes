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
