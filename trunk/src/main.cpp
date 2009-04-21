#include<iostream>
#include<cstdlib>
#include"plateformeMondeDesCubes.hpp"
#include"ecoAgentID.hpp"
#include"cube.hpp"
#include"ecoAgent.hpp"

using namespace std;
int main(int argc, char** argv){
   EcoAgentID *id,*id2,*id3;
	id = new EcoAgentID();
	id2 = new EcoAgentID();
	id3 = new EcoAgentID();
	Cube *c;
   c = new Cube(*((EcoAgentID*)id));
	c->EcoAgent::setPositionCourante(*((EcoAgentID*)id2));
	c->EcoAgent::setPositionFinale(*((EcoAgentID*)id3));
	c->initialiserEtat();
	cout << c;
  
  return EXIT_SUCCESS;
}
