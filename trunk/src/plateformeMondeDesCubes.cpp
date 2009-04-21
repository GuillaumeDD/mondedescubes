#include "plateformeMondeDesCubes.hpp"

void PlateformeMondeDesCubes::initialiser(){}

void PlateformeMondeDesCubes::resoudre(){
  Cube* c;
 initialiser();
 while(!sontSatisfaits()){
   c = obtenirCubePrioritaire();
   c->agir();
 }
}

//A FAIRE
Cube* PlateformeMondeDesCubes::obtenirCubePrioritaire(){
  return NULL;
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

EcoAgentID* PlateformeMondeDesCubes::getTableID(){
  return table.getId();
}

bool PlateformeMondeDesCubes::verifierNombreDeCubes(int nb){
  bool result = true;
  if(nb<=0){
    result = false;
  }
  return result;
}

Cube* PlateformeMondeDesCubes::obtenirGeneur(const Cube& currentCube){
  Cube* result = NULL;
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
void PlateformeMondeDesCubes::setCubeID(Cube& currentCube, const EcoAgentID& id){
 currentCube.setId(id); 
}

PlateformeMondeDesCubes::PlateformeMondeDesCubes(){
  nombreDeCubes = 0;
}

//A FAIRE
PlateformeMondeDesCubes::~PlateformeMondeDesCubes(){
}

