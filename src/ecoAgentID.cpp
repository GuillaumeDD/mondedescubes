#include "ecoAgentID.hpp"

int EcoAgentID::nombreDeGeneration = 0;

EcoAgentID::EcoAgentID(){
 identifiant = genereID();
}

EcoAgentID::~EcoAgentID(){}

int EcoAgentID::getId() const{
 return identifiant; 
}

void EcoAgentID::setId(const int id) {
  identifiant=id; 
}

bool EcoAgentID::operator ==(const EcoAgentID& eid) const{
 return eid.getId() == getId();
}

bool EcoAgentID::operator !=(const EcoAgentID& eid) const{
 return eid.getId() != getId();
}

bool EcoAgentID::operator <(const EcoAgentID& eid) const{
 return eid.getId() < getId();
}

int EcoAgentID::getNombreDeGeneration(){
    return nombreDeGeneration;
}

int EcoAgentID::genereID(){
 int result = nombreDeGeneration;
 nombreDeGeneration++;
 return result;
}

ostream & operator<< (ostream &f, const EcoAgentID& aid){
    return f << "(EcoAgentID) " <<  aid.identifiant << " ";
}
