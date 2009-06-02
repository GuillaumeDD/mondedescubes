#include "ecoAgent.hpp"
#include "plateformeEcoResolution.hpp"

EcoAgent::EcoAgent(){
  id = new EcoAgentID();
  positionCourante = NULL;
  positionFinale = NULL;
  etat = UNDEFINED;
}

EcoAgent::~EcoAgent(){
  if(id != NULL){
    delete id;
  }
}

EcoAgent::EcoAgent(const EcoAgent& e){
  id = new EcoAgentID(*(e.getId()));
  positionCourante =  e.getPositionCourante();
  positionFinale =  e.getPositionFinale();
  etat = e.getEtat();
}

EcoAgent& EcoAgent::operator=(const EcoAgent& e){
  if(this != &e){
    delete id;
    id = new EcoAgentID(*(e.getId()));
    positionCourante = e.getPositionCourante();
    positionFinale = e.getPositionFinale();
    etat = e.getEtat();
  }
  return *this;
}

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

ostream & operator<< (ostream &f, const EcoAgent& ea){
  f << "EcoAgentID :" << *(ea.getId()) << endl; 
  f << "Etat : " << ea.etat << endl;
  if(ea.getPositionCourante() != NULL){
    f << "Position courante : " << *(ea.getPositionCourante()) << endl;
  }
  if(ea.getPositionFinale() != NULL){
    f << "Position finale : " << *(ea.getPositionFinale()) << endl;
  }
  return f;
}
