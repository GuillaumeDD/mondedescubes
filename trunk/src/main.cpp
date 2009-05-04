#include<iostream>
#include<cstdlib>
#include"plateformeMondeDesCubes.hpp"
#include<tinyxml.h>

using namespace std;

void init();

int main(int argc, char** argv){
  PlateformeMondeDesCubes *p = NULL;
  int temp;
  init();
  p = PlateformeMondeDesCubes::getInstance();
  p->initialiser();
  cout << "INITIALISATION" << endl;
  cout << *p << endl;
  cout << "------------------------"<< endl << endl;

  if(p->verifierCoherence()){
    while(!p->sontSatisfaits()){
      cout << p->toString()<<endl;
      cout << "------------------------"<< endl;
      cout << *p << endl;
      cout << "------------------------"<< endl << endl;
      p->resoudre();
      cin >> temp;
    }
    cout << "SOLUTION FINALE :" << endl;
    cout << p->toString()<<endl;
    cout << "------------------------"<< endl;
    cout << *p << endl;
    cout << "------------------------"<< endl;
  }else{
    cout << "Regle non verifie !"<< endl;
  }

  /*
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
  */
  return EXIT_SUCCESS;
}


void init(){
  PlateformeMondeDesCubes *p = NULL;
  EcoAgentID *eaid = NULL;
  Cube* c = NULL;
  int idTemp = 0,
    positionCouranteTemp =0,
    positionFinaleTemp = 0;
  
  // Chargement de la plateforme
  p = PlateformeMondeDesCubes::getInstance();


  // Chargement du document XML
  TiXmlDocument doc( "data.xml" );
  if(!doc.LoadFile()){
    cout << "Impossible de charger le fichier de donnees." << endl;
  }

  // Chargement de la table
  TiXmlHandle hdl(&doc);
  TiXmlElement *elem = hdl.FirstChildElement("MondeDesCubes").FirstChildElement("Table").Element();
  
  if(!elem){
    cout << "Impossible de charger la table" << endl;
  }else{
    if(elem->QueryIntAttribute("id", &idTemp) == TIXML_SUCCESS){
      eaid = new EcoAgentID(idTemp);
    }else{
      eaid = new EcoAgentID();
    }
    cout << "Attribution de l'EcoAgentID suivant a la table : "<< *eaid << endl;
    p->setTableIdentifiant(*eaid);
  }

  // Chargement de la liste des cubes
  elem = hdl.FirstChildElement("MondeDesCubes").FirstChildElement("CubeList").FirstChildElement().Element();
  if(!elem){
    cout << "Impossible de charger les cubes" << endl;
  }else{

    try{
      while(elem){
	// Lecture de l'identifiant
	if(elem->QueryIntAttribute("id", &idTemp) == TIXML_SUCCESS){
	  eaid = new EcoAgentID(idTemp);
	}else{
	  eaid = new EcoAgentID();
	}
      
	c = new Cube(*eaid);
      
	// Lecture de la position courante
	if(elem->QueryIntAttribute("positionCourante", &positionCouranteTemp) == TIXML_SUCCESS){
	  eaid = new EcoAgentID(positionCouranteTemp);
	}else{
	  eaid = new EcoAgentID();
	}
	c->setPositionCourante(*eaid);

	// Lecture de la position finale
	if(elem->QueryIntAttribute("positionFinale", &positionFinaleTemp) == TIXML_SUCCESS){
	  eaid = new EcoAgentID(positionFinaleTemp);
	}else{
	  eaid = new EcoAgentID();
	}
	c->setPositionFinale(*eaid);

	// Ajout de l'agent dans la plateforme
	p->addEcoAgent(*c);
	cout << "Ajout du cube suivant dans la plateforme :" << *c << endl;

	elem = elem->NextSiblingElement();
      }
    }catch(ExceptionEcoAgentDejaEnregistre ex){
      cout << "L'ajout d'un EcoAgent avec un ID attribue a un autre EcoAgent a ete tente. Chaque EcoAgent doit avoir un identifiant unique ! La resolution est donc impossible." << endl;
    }
  }

}
