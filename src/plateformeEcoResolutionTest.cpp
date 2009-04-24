#include "plateformeEcoResolutionTest.hpp"
#include "reliesATable.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(plateformeEcoResolutionTest);

void plateformeEcoResolutionTest::setUp(void)
{
	//initialisation
	ea1 = new Cube();
	ea2 = new Cube();
	ea3 = new Cube();
	r = new ReliesATable();
	p = PlateformeMondeDesCubes::getInstance();
	p->addEcoAgent(*ea2);
}


void plateformeEcoResolutionTest::tearDown(void)
{
	//destructeur
	delete ea1;
	delete ea2;
	delete ea3;
	PlateformeMondeDesCubes::kill();
}


void plateformeEcoResolutionTest::addTest(void)
{
	// Ajout d'un EcoAgent deja enregistre dans la plateforme
	CPPUNIT_ASSERT_THROW (p->addEcoAgent(*ea2), ExceptionEcoAgentDejaEnregistre);

	// Ajout d'un EcoAgent non enregistre dans la plateforme
	unsigned int temp1=0;
	temp1 = (p->getEcoAgents()).size();
	p->addEcoAgent(*ea3);
	CPPUNIT_ASSERT(temp1+1 == (p->getEcoAgents()).size());
	CPPUNIT_ASSERT_THROW (p->addEcoAgent(*ea3), ExceptionEcoAgentDejaEnregistre);
	
	// Ajout d'une regle
	temp1 = (p->getRegles()).size();
	p->addRegle(*r);
	CPPUNIT_ASSERT(temp1+1 == (p->getRegles()).size());

}


void plateformeEcoResolutionTest::getTest(void)
{
	// Recherche d'un EcoAgent inexistant dans la plateforme
	CPPUNIT_ASSERT(p->getEcoAgent(*(ea1->getId())) == NULL);
	
	//Recherche d'un EcoAgent existant dans la plateforme
	CPPUNIT_ASSERT(p->getEcoAgent(*(ea2->getId())) == ea2);

	//CPPUNIT_ASSERT_EQUAL(1,1);
	//CPPUNIT_ASSERT_THROW (Fraction (1, 0), DivisionByZeroException);
	
}


void plateformeEcoResolutionTest::exceptionTest(void)
{

}


void plateformeEcoResolutionTest::regleTest(void)
{
	unsigned int temp;	
	temp = p->getRegles().size();
	//verification des regles quand il n'y en a pas
	CPPUNIT_ASSERT(p->verifierCoherence() && temp == 0);
	
	//verification des regles
	p->addRegle(*(new Regletrue()));
	p->addRegle(*(new Regletrue()));
	p->addRegle(*(new Regletrue()));
	temp = p->getRegles().size();
	CPPUNIT_ASSERT(p->verifierCoherence() && temp > 0);
	
	//Verification des regles avec une regle non verifiee
	p->addRegle(*(new Reglefalse()));
	temp = p->getRegles().size();
	CPPUNIT_ASSERT(!p->verifierCoherence() && temp > 0);
	
}
