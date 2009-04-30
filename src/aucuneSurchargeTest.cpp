#include "aucuneSurchargeTest.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(aucuneSurchargeTest);

void aucuneSurchargeTest::setUp(void)
{
	//initialisation
	AucuneSurcharge *nosurcharge = new AucuneSurcharge();
	p = PlateformeMondeDesCubes::getInstance();	
	id1 = new EcoAgentID();
	id2 = new EcoAgentID();
	id3 = new EcoAgentID();
	id4 = new EcoAgentID();
	c1= new Cube(*id1);
	c2= new Cube(*id2);
	c3= new Cube(*id3);
	c4= new Cube(*id4);

	p->addEcoAgent(*c1);
  	p->addEcoAgent(*c2);
  	p->addEcoAgent(*c3);
  	p->addEcoAgent(*c4);

	c1->setPositionCourante(*(p->getTableID()));
	c2->setPositionCourante(*id1);
	c3->setPositionCourante(*id2);
	c4->setPositionCourante(*id3);
	
	

	map<EcoAgentID,EcoAgent&,compareEcoAgentID> m = p->getEcoAgents();	
	map<EcoAgentID,EcoAgent&,compareEcoAgentID>::iterator it;
	it = m.begin();
	while(it != m.end()){
	  //cout <<endl<< it->second << endl;
	  ++it;
	}
	
	/*
	cout << endl;
	cout << "ecoagentID " << *(p->getTableID()) << endl;
	cout << "ecoagentID " << *id1 << endl;
	cout << "ecoagentID " << *id2 << endl;
	cout << "ecoagentID " << *id3 << endl;
	cout << "ecoagentID " << *id4 << endl;
	*/
}


void aucuneSurchargeTest::tearDown(void)
{
	//destructeur
	delete c1;
	delete c2;
	delete c3;
	delete c4;

	PlateformeMondeDesCubes::kill();
}


void aucuneSurchargeTest::verifierTest(void)
{
	


}

void aucuneSurchargeTest::pasSurchargesTest(void)
{
  	
	//les cubes ne sont pas surcharges
	CPPUNIT_ASSERT(nosurcharge->pasSurcharges()== true );
	//un cube est surcharges
	c3->setPositionCourante(*id1);
	CPPUNIT_ASSERT(nosurcharge->pasSurcharges()== false );
  
}

void aucuneSurchargeTest::serontPasSurchargesTest(void)
{
	// Tests
}
