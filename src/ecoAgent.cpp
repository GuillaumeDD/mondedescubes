#include "ecoAgent.hpp"


Etat EcoAgent::getEtat() const{
 return etat; 
}

void EcoAgent::setEtat(const Etat e){
	etat=e;
}

EcoAgentID* EcoAgent::getId() const{
 return id;
}

void EcoAgent::setId(const EcoAgentID& identifiant){
	id = &((EcoAgentID&)identifiant);
}

bool EcoAgent::getVisite() const{
 return visite;
}

void EcoAgent::setVisite(const bool b){
	visite = b;
}

EcoAgentID* EcoAgent::getPositionCourante() const{
	return positionCourante;
}

void EcoAgent::setPositionCourante(const EcoAgentID& pos){
	positionCourante = &((EcoAgentID&)pos);
}

EcoAgentID* EcoAgent::getPositionFinale() const{
	return positionFinale;
}

void EcoAgent::setPositionFinale(const EcoAgentID& pos){
	positionFinale = &((EcoAgentID&)pos);
}

EcoAgentID* EcoAgent::getAuDessus() const{
	return auDessus;
}

void EcoAgent::setAuDessus(const EcoAgentID& pos){
  if(&pos != NULL){
	auDessus = &((EcoAgentID&)pos);
  }else{
   auDessus = NULL; 
  }
}

ostream & operator<< (ostream &f, const EcoAgent& ea){
  return f << "EcoAgentID :" << *(ea.getId()) << "\n" << "Etat :" << ea.etat << "\n" << "Position courante : sur l'EcoAgent d'identifiant" << *(ea.getPositionCourante()) << endl << "Position finale : sur l'EcoAgent d'identifiant" << *(ea.getPositionFinale())<< endl;
}
