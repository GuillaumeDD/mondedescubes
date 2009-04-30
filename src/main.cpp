#include<iostream>
#include<cstdlib>
#include"plateformeMondeDesCubes.hpp"

using namespace std;
int main(int argc, char** argv){
  PlateformeMondeDesCubes *p = NULL;
  EcoAgent *ea1 = NULL, *ea2 = NULL, *ea3 = NULL;

  p = PlateformeMondeDesCubes::getInstance();
  cout << p->toString()<< endl;

  ea1 = new Cube();
  ea2 = new Cube();
  ea3 = new Cube();

  p->addEcoAgent(*ea1);
  p->addEcoAgent(*ea2);
  p->addEcoAgent(*ea3);
  ea1->setPositionCourante(*(p->getTableID()));
  ea1->setPositionFinale(*(p->getTableID()));
  
  ea2->setPositionCourante(*(ea3->getId()));
  ea2->setPositionFinale(*(ea1->getId()));

  ea3->setPositionCourante(*(ea1->getId()));
  ea3->setPositionFinale(*(ea2->getId()));

  // lancement de la resolution
  p->initialiser();
  if(p->verifierCoherence()){
    while(!p->sontSatisfaits()){
      cout << p->toString()<<endl;
      cout << "------------------------"<< endl;
      cout << *p << endl;
      cout << "------------------------"<< endl;
      p->resoudre();
    }
  }
  
  cout << "SOLUTION FINALE :" << endl;
  cout << p->toString()<<endl;
  cout << "------------------------"<< endl;
  cout << *p << endl;
  cout << "------------------------"<< endl;
  p->resoudre();

  return EXIT_SUCCESS;
}
