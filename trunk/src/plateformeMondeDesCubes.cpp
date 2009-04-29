#include "plateformeMondeDesCubes.hpp"

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
  initialiser();
  while(!sontSatisfaits()){
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

void PlateformeMondeDesCubes::setNombreDeCubes(int nb){
  if(verifierNombreDeCubes(nb)){
    nombreDeCubes = nb;
  }else{
    nombreDeCubes = 0; 
  }
}

int PlateformeMondeDesCubes::getNombreDeCubes() const{
  return nombreDeCubes;  
}

void PlateformeMondeDesCubes::setTableIdentifiant(const EcoAgentID& id){
  table.setId(id);
}

EcoAgentID* PlateformeMondeDesCubes::getTableID() const{
  return table.getId();
}

bool PlateformeMondeDesCubes::verifierNombreDeCubes(int nb){
  bool result = true;
  if(nb<=0){
    result = false;
  }
  return result;
}

EcoAgent* PlateformeMondeDesCubes::obtenirGeneur(const EcoAgent& currentCube){
  EcoAgent* result = NULL;
  EcoAgentID* id = NULL;
  if(currentCube.getPositionFinale() != currentCube.getPositionCourante())
    {

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
	      if(currentCube.getPositionFinale() != getTableID())
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
  nombreDeCubes = 0;
}

//A FAIRE
PlateformeMondeDesCubes::~PlateformeMondeDesCubes(){
}

int PlateformeMondeDesCubes::distanceFinaleATable(const EcoAgentID& c) const{
  int result = 0;
  EcoAgent* ecoA = NULL;
  if(c != *getTableID()){
    ecoA = getEcoAgent(c);
    if(ecoA != NULL && ecoA->getPositionFinale() != getTableID()){
      result = 1 + distanceFinaleATable(*(ecoA->getPositionFinale()));
    }
  }
  return result;
}

ostream& operator<<(ostream& f, const PlateformeMondeDesCubes& p){
  f << "---------------------------" << endl;
  f << "Plateforme monde des cubes :" << endl;
  f << "Table : " << p.table << endl;
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
