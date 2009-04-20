#include "ecoAgent.hpp"
#include "ecoAgentID.hpp"


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

void EcoAgent::rechercherFuite(){}

void EcoAgent::rechercherSatisfaction(){}

void EcoAgent::agresser(const EcoAgent& a){}

void EcoAgent::estAgresse(){}

void EcoAgent::faireFuite(){}

void EcoAgent::faireSatisfaction(){}

void EcoAgent::agir(){}




