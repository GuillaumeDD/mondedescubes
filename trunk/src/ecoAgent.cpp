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

EcoAgentID* EcoAgent::getPositionFinale() const{
	return positionFinale;
}

void EcoAgent::setPositionCourante(const EcoAgentID& pos){
	positionCourante = &((EcoAgentID&)pos);
}

void EcoAgent::setPositionFinale(const EcoAgentID& pos){
	positionFinale = &((EcoAgentID&)pos);
}

ostream & operator<< (ostream &f, const EcoAgent& ea){
  return f << "EcoAgentID :" << *(ea.getId()) << "\n" << "Etat :" << ea.etat << "\n" << "Position courante : sur l'EcoAgent d'identifiant" << *(ea.getPositionCourante()) << endl << "Position finale : sur l'EcoAgent d'identifiant" << *(ea.getPositionFinale())<< endl;
}
