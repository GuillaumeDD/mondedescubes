#include "aucuneSurchargeTest.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(aucuneSurchargeTest);

void aucuneSurchargeTest::setUp(void) {
	//initialisation
	nosurcharge = new AucuneSurcharge();
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
	
	c1->setPositionFinale(*(p->getTableID()));
	c2->setPositionFinale(*id1);
	c3->setPositionFinale(*id2);
	c4->setPositionFinale(*id3);

}


void aucuneSurchargeTest::tearDown(void) {
	//destructeur
	delete c1;
	delete c2;
	delete c3;
	delete c4;
	delete id1;
	delete id2;
	delete id3;
	delete id4;
	delete nosurcharge;
	PlateformeMondeDesCubes::kill();
}


void aucuneSurchargeTest::verifierTest(void) {


		//les cubes ne sont pas surcharges et ne seront pas surcharges
		CPPUNIT_ASSERT(nosurcharge->verifier() == true);
		
		//les cubes sont surcharges mais ne seront pas surcharges
		c3->setPositionCourante(*id1);
		CPPUNIT_ASSERT_THROW (nosurcharge->verifier(), ExceptionUnCubeEstSurcharge);
 
		//les cubes ne sont pas surcharges mais seront surcharges		
		c3->setPositionCourante(*id2);
		c4->setPositionFinale(*id1);		
		CPPUNIT_ASSERT_THROW (nosurcharge->verifier(), ExceptionUnCubeSeraSurcharge);
		
		//les cubes sont surcharges et seront surcharges
		c4->setPositionCourante(*id1);	
		CPPUNIT_ASSERT_THROW (nosurcharge->verifier(), ExceptionUnCubeEstSurcharge);

}

void aucuneSurchargeTest::pasSurchargesTest(void) {
  	
	//les cubes ne sont pas surcharges
	CPPUNIT_ASSERT(nosurcharge->pasSurcharges() == true);
	//un cube est surcharges
	c3->setPositionCourante(*id1);
	CPPUNIT_ASSERT_THROW (nosurcharge->pasSurcharges(), ExceptionUnCubeEstSurcharge);
  
}

void aucuneSurchargeTest::serontPasSurchargesTest(void) {
	//les cubes ne seront pas surcharges
	CPPUNIT_ASSERT(nosurcharge->serontPasSurcharges() == true);
	//un cube sera surcharge
	c4->setPositionFinale(*id1);
	CPPUNIT_ASSERT_THROW (nosurcharge->serontPasSurcharges(), ExceptionUnCubeSeraSurcharge);

}
