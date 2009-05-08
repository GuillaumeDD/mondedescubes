#include "plateformeMondeDesCubes.hpp"
#include "aucuneSurcharge.hpp"
#include "reliesATable.hpp"
#include <sstream>
#include<iomanip>

void PlateformeMondeDesCubes::initialiser(){
  map<EcoAgentID,EcoAgent&>::const_iterator it = ecoagents.begin();
  //initialisation de chaque EcoAgent
  while(it != ecoagents.end()){
    (it->second).initialiser();
    ++it;
  }
}

void PlateformeMondeDesCubes::resoudre(){
  EcoAgent* c;
  if(!sontSatisfaits()){
    c = obtenirCubePrioritaire();
    c->agir();
  }
}

EcoAgent* PlateformeMondeDesCubes::obtenirCubePrioritaire() const{
  EcoAgent* result = NULL;
  list<EcoAgentID*> candidats;
  list<EcoAgentID*>::const_iterator it;
  unsigned int nbCubeSup, nbCubeInfFinal, temp;
  nbCubeInfFinal = nbCubeSup = ecoagents.size()+1;
  // on cherche les cubes en recherche de fuite
  candidats = getEcoAgents(RECHERCHEFUITE);
  if(candidats.size() > 0){
    // on recherche le cube en recherche de fuite le plus haut place
    it = candidats.begin();
    while(it != candidats.end()){
      temp = nombreEcoAgentAuDessus(**it);
      if( temp < nbCubeSup){
	nbCubeSup = temp;
	result = getEcoAgent(**it);
      }
      ++it;
    }
  }else{
    //il n'y a pas de cube en recherche de fuite, on cherche les cubes en 
    // recherche de satisfaction
    candidats = getEcoAgents(RECHERCHESATISFACTION);
    // on selectionne le cube en recherche de satisfaction qui doit etre
    // place le plus bas
    // i.e. le cube dont la distance de la position finale a la table est
    // la plus petite

    it = candidats.begin();
    while(it != candidats.end()){
      temp = distanceFinaleATable(**it);
      if(temp < nbCubeInfFinal){
	nbCubeInfFinal = temp;
	result = getEcoAgent(**it);
      }
      ++it;
    }
  }
  return result;
}

int PlateformeMondeDesCubes::getNombreDeCubes() const{
  return ecoagents.size();  
}

void PlateformeMondeDesCubes::setTableIdentifiant(const EcoAgentID& id){
  table->setId(id);
}

EcoAgentID* PlateformeMondeDesCubes::getTableID() const{
  return table->getId();
}

EcoAgent* PlateformeMondeDesCubes::obtenirGeneur(const EcoAgent& currentCube){
  EcoAgent* result = NULL;
  EcoAgentID* id = NULL;
      if(currentCube.getEtat()== RECHERCHEFUITE)
	{
	  // si le Cube est en RF : soit il a un cube posé sur lui et il l'agresse
	  // soit il n'a aucun gêneur et il peut fuir
	  id = getEcoAgentAuDessus(*(currentCube.getId()));
	  if(id != NULL) result = getEcoAgent(*id);
	}

      if(currentCube.getEtat()== RECHERCHESATISFACTION)
	{
	  id = getEcoAgentAuDessus(*(currentCube.getId()));

	  if(id == NULL)
	    {
	      //il n'y a aucun EcoAgent dont la position courante est currentCube
	      // on regarde s'il y a un EcoAgent dont la position courante est la
	      // position finale de currentCube sauf si la position finale est la table
	      if(*(currentCube.getPositionFinale()) != *getTableID())
		{
		  id = getEcoAgentAuDessus(*(currentCube.getPositionFinale()));
		  if(id != NULL)
		    {
		      // il y a un EcoAgent dont la position courante est la position finale
		      result = getEcoAgent(*id);
		    }
		}
	    }
	  else result = getEcoAgent(*id);
	}
  return result;
}

void PlateformeMondeDesCubes::setPositionFinale(const EcoAgentID& c, const EcoAgentID& pos){
  EcoAgent* agent;
  agent = getEcoAgent(c);
  if(agent == NULL){
    cout << "Agent inexistant" << endl;  
  }else{
    agent->setPositionFinale(pos);
  }
}

void PlateformeMondeDesCubes::setPositionCourante(const EcoAgentID& c, const EcoAgentID& pos){
  EcoAgent* agent;
  agent = getEcoAgent(c);
  if(agent == NULL){
    cout << "Agent inexistant" << endl;  
  }else{
    agent->setPositionCourante(pos);
  }  
}

//verifier la pertinence de cette methode
void PlateformeMondeDesCubes::setCubeID(EcoAgent& currentCube, const EcoAgentID& id){
  currentCube.setId(id); 
}

PlateformeMondeDesCubes::PlateformeMondeDesCubes(){
  table = new Table();

  // Ajout des regles
  addRegle(*(new AucuneSurcharge()));
  addRegle(*(new ReliesATable()));
}

PlateformeMondeDesCubes::~PlateformeMondeDesCubes(){
  delete table;
}

int PlateformeMondeDesCubes::distanceFinaleATable(const EcoAgentID& c) const{
  int result = 0;
  EcoAgent* ecoA = NULL;
  if(c != *getTableID()){
    ecoA = getEcoAgent(c);
    if(ecoA != NULL && *(ecoA->getPositionFinale()) != *getTableID()){
      result = 1 + distanceFinaleATable(*(ecoA->getPositionFinale()));
    }
  }
  return result;
}

int PlateformeMondeDesCubes::distanceATable(const EcoAgentID& c) const{
  int result = 0;
  EcoAgent* ecoA = NULL;
  if(c != *getTableID()){
    ecoA = getEcoAgent(c);
    if(ecoA != NULL && *(ecoA->getPositionCourante()) != *getTableID()){
      result = 1 + distanceATable(*(ecoA->getPositionCourante()));
    }
  }
  return result;
}

void PlateformeMondeDesCubes::addEcoAgent(EcoAgent& ea){
  if(*(ea.getId()) != *(table->getId())){
    PlateformeEcoResolution::addEcoAgent(ea);
  }else{
    throw(*(new ExceptionEcoAgentDejaEnregistre()));
  }
}

ostream& operator<<(ostream& f, const PlateformeMondeDesCubes& p){
  f << "---------------------------" << endl;
  f << "Plateforme monde des cubes :" << endl;
  f << "Table : " << *(p.table) << endl;
  f << "Cube ou assimilé : " << endl;
  if(p.ecoagents.size() > 0){
    map<EcoAgentID,EcoAgent&>::const_iterator it = p.ecoagents.begin();
    while(it != p.ecoagents.end()){
      f << it->second << endl;
      ++it;
    }
  }else{
    f << "Aucun cube ou assimilé dans la plateforme" << endl;
  }
  f << "---------------------------" << endl;
  return f;
}

string PlateformeMondeDesCubes::toString() const{
  string result, separateur = "      ";
  list< list<EcoAgent*> > piles;
  list<EcoAgent*> *l = NULL;
  EcoAgent *temp = NULL;
  EcoAgentID *tempID = NULL;
  ostringstream *os;
  unsigned int maxHauteurPile = 0;

  map<EcoAgentID,EcoAgent&,compareEcoAgentID> mapCopy;
  mapCopy = getEcoAgents();
  map<EcoAgentID,EcoAgent&,compareEcoAgentID>::const_iterator it;
  it = mapCopy.begin();

  // construction des listes de piles
 while(it != mapCopy.end()){
   if(*((it->second).getPositionCourante()) == *getTableID()){
     l = new list<EcoAgent*>();
     l->push_back(&it->second);
     // on ajoute alors tous les EcoAgent au dessus
     tempID = getEcoAgentAuDessus(*(it->second.getId()));
     if(tempID != NULL){
       temp = getEcoAgent(*(tempID));
       while(temp != NULL){
	 l->push_back(temp);
	 tempID = getEcoAgentAuDessus(*(temp->getId()));
	 if(tempID == NULL){
	   temp = NULL;
	 }else{
	   temp = getEcoAgent(*(tempID));
	 }
       }
     }
     //on ajoute la liste a la liste de piles
     piles.push_back(*l);
      
   }
   ++it;
 }

  list< list<EcoAgent*> >::iterator itPiles;
  list<EcoAgent*>::iterator itL;
  
  // on calcule la taille de la plus grande pile
  itPiles = piles.begin();
  while(itPiles != piles.end()){
    if(itPiles->size() > maxHauteurPile){
      maxHauteurPile = itPiles->size();
    }
    ++itPiles;
  }

  for(int i=maxHauteurPile ; i>0 ; i--){

    // on parcourt chaque cube de chaque pile 4 fois pour l'affichage
    for(int k=0 ; k<4 ; k++){
    itPiles = piles.begin();

      // on parcourt chacune des piles
      while(itPiles != piles.end()){
	itL = itPiles->begin();

	// on positionne la pile sur le bon cube
	for(int j = i-1; j > 0 ; j--){
	  if(itL != itPiles->end()){
	    ++itL;
	  }
	}

	if(itL != itPiles->end() && itPiles->size() <= maxHauteurPile){
	  switch(k){
	    case 0 : 
	      result += "______";break;
	    case 1 : 
	      result += "|    |";break;
	    case 2 : 
	      os = new ostringstream();
	      *os << setw(4)<< (*itL)->getId()->getId();
	      result += "|"+os->str()+"|";
	      delete os;
	      //result += "|    |";
	      break;
	    case 3 : result += "|____|";break;
	    }     
	}else{
	  result += separateur;
	}

	++itPiles;
      }
      result += "\n";
    }
  }

  return result;
}
