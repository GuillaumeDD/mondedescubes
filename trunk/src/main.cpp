#include<iostream>
#include<cstdlib>
#include"plateformeMondeDesCubes.hpp"
#include<tinyxml.h>

using namespace std;

void init(string);

int main(int argc, char** argv){
  PlateformeMondeDesCubes *p = NULL;
  string data = "data.xml";
  int temp;

  if(argc > 1){
    data = argv[1];
  }
  init(data);
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
      cout << "------------------------"<< endl;
      cout << "CUBE PRIORITAIRE"<< endl;
      cout << *p->obtenirCubePrioritaire()<< endl;
      cout << "------------------------"<< endl << endl;
      p->resoudre();
//      cin >> temp;
    }
    cout << "SOLUTION FINALE :" << endl;
    cout << p->toString()<<endl;
    cout << "------------------------"<< endl;
    cout << *p << endl;
    cout << "------------------------"<< endl;
  }else{
    cout << "Regle non verifie !"<< endl;
  }

  return EXIT_SUCCESS;
}


void init(string file){
  PlateformeMondeDesCubes *p = NULL;
  EcoAgentID *eaid = NULL;
  Cube* c = NULL;
  int idTemp = 0,
    positionCouranteTemp =0,
    positionFinaleTemp = 0;
  
  // Chargement de la plateforme
  p = PlateformeMondeDesCubes::getInstance();


  // Chargement du document XML
  TiXmlDocument doc( file );
  if(!doc.LoadFile()){
    cout << "Impossible de charger le fichier de donnees." << endl;
    exit(0);
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
    exit(0);
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
      exit(0);
    }
  }

}
