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
    CPPUNIT_TEST (addTest);
    CPPUNIT_TEST (getTest);
    CPPUNIT_TEST (informationTest);
    CPPUNIT_TEST (regleTest);
    CPPUNIT_TEST_SUITE_END ();

    public:
        void setUp (void);
        void tearDown (void);

    protected:
        void addTest (void);
        void getTest (void);
        void informationTest (void);
        void regleTest (void);

    private:
		EcoAgent *ea1, 
					*ea2,
					*ea3;
		PlateformeEcoResolution *p;
		Regle* r;
	};

#endif
