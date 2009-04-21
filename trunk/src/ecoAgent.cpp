#include "ecoAgent.hpp"


Etat EcoAgent::getEtat() const{
 return etat; 
}

EcoAgentID* EcoAgent::getId() const{
 return id;
}

void EcoAgent::setEtat(const Etat e){
	etat=e;
}

void EcoAgent::setId(const EcoAgentID& identifiant){
	id = &((EcoAgentID&)identifiant);
}

EcoAgentID* EcoAgent::getPositionCourante() const{
	return positionCourante;
}

EcoAgentID* EcoAgent::getPositionFinale() const{
	return positionFinale;
}

void EcoAgent::setPositionCourante(const EcoAgentID& pos){
	positionCourante = &((EcoAgentID&)pos);
}

void EcoAgent::setPositionFinale(const EcoAgentID& pos){
	positionFinale = &((EcoAgentID&)pos);
}

// A FAIRE
ostream & operator<< (ostream &f, const EcoAgent& ea){
  return f << "EcoAgentID :" << ea.getId()->getId() << "\n" << "Etat :" << ea.etat << "\n" << "Position courante : sur l'EcoAgent d'identifiant" << ea.getPositionCourante()->getId() << "\n" << "Position finale : sur l'EcoAgent d'identifiant" << ea.getPositionFinale()->getId()<<"\n";
}






