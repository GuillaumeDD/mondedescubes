#include<iostream>
#include<cstdlib>
#include"plateformeMondeDesCubes.hpp"

using namespace std;
int main(int argc, char** argv){
  cout << SATISFAIT << endl;
  EcoAgentID *id,*id2,*id3;
  id = new EcoAgentID();
  id2 = new EcoAgentID();
  id3 = new EcoAgentID();
  cout << *id << endl;
  cout << *id2 << endl;
  cout << *id3 << endl;	
  Cube *c;
  c = new Cube(*id);
  c->setPositionCourante(*id2);
  c->setPositionFinale(*id3);
  c->initialiser();
  cout << *c << endl;
 	
  PlateformeMondeDesCubes* p = PlateformeMondeDesCubes::getInstance();
  cout << *p << endl;
	
  p->addEcoAgent(*c);
  p->addEcoAgent(*c);
  p->addEcoAgent(*c);

  cout << *p << endl;
  return EXIT_SUCCESS;
}
