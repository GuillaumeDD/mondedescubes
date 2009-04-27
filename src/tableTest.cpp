#include "tableTest.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(tableTest);

void tableTest::setUp(void)
{

	p = PlateformeMondeDesCubes::getInstance();
	t = new Table();
	ea1 = new Cube();
	p->addEcoAgent(*t);
	p->addEcoAgent(*ea1);
}


void tableTest::tearDown(void)
{
	//destructeur
	delete t;
	delete ea1;
	PlateformeMondeDesCubes::kill();
	
}


void tableTest::doTest(void)
{
	// Tests
	EcoAgentID *idt = new EcoAgentID();
	t->setId(*idt);

	t->rechercherFuite();
	CPPUNIT_ASSERT(t->getEtat()==SATISFAIT && t->getPositionCourante()==NULL && t->getPositionFinale()==NULL);

	t->rechercherSatisfaction();
	CPPUNIT_ASSERT(t->getEtat()==SATISFAIT && t->getPositionCourante()==NULL && t->getPositionFinale()==NULL);

	ea1->setEtat(RECHERCHESATISFACTION);
	t->agresser(*ea1);
	CPPUNIT_ASSERT(ea1->getEtat()==RECHERCHESATISFACTION);

	t->estAgresse();
	CPPUNIT_ASSERT(t->getEtat()==SATISFAIT);

	t->faireFuite();
	CPPUNIT_ASSERT(t->getEtat()==SATISFAIT && t->getPositionCourante()==NULL);

	t->faireSatisfaction();
	CPPUNIT_ASSERT(t->getEtat()==SATISFAIT && t->getPositionCourante()==NULL && t->getPositionFinale()==NULL);

	t->agir();
	CPPUNIT_ASSERT(t->getEtat()==SATISFAIT && t->getPositionCourante()==NULL && t->getPositionFinale()==NULL);
}

