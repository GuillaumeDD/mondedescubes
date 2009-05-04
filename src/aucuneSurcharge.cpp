#include "aucuneSurcharge.hpp"


using namespace std;


void AucuneSurcharge::initialiser() {
}
      

bool AucuneSurcharge::verifier() {
  if(this->pasSurcharges() == false) {
    return false;
  }
  if(this->serontPasSurcharges() == false) {
    return false;
  }
  return true;
}
	
	
bool AucuneSurcharge::pasSurcharges() {
  PlateformeMondeDesCubes *p = PlateformeMondeDesCubes::getInstance();	
  map<EcoAgentID,EcoAgent&,compareEcoAgentID> m = p->getEcoAgents();
  /* Mise en place d'un iterateur sur la map des cubes de la plate forme */
  map<EcoAgentID, EcoAgent&, compareEcoAgentID>::const_iterator it = m.begin();

  /* Creation d'un compteur des successeurs de chaque cube et d'un iterateur*/
  map<EcoAgentID, int> compteur;
  map<EcoAgentID, int>::iterator itcompteur;

  // On intialise le compteur à 0 pour chaque eco-agent
  while(it != m.end()) {
    compteur.insert(pair<EcoAgentID, int>(it->first,0));
    it++;
  }
  it=m.begin();
  for(it = m.begin() ; it != m.end() ; ++it) {
    /* si la position est bien un cube on applique l'algorithme*/ 
    if(*(it->second.getPositionCourante()) != *(p->getTableID())) {
      itcompteur=compteur.find(*(it->second.getPositionCourante()));
      itcompteur->second=itcompteur->second+1;
      if(itcompteur->second > 1) {
	return false;
      }	
    }
  }
  return true;
}


bool AucuneSurcharge::serontPasSurcharges() {
  PlateformeMondeDesCubes *p = PlateformeMondeDesCubes::getInstance();	
  map<EcoAgentID,EcoAgent&,compareEcoAgentID> m = p->getEcoAgents();
  /* Mise en place d'un iterateur sur la map des cubes de la plate forme */
  map<EcoAgentID, EcoAgent&, compareEcoAgentID>::const_iterator it = m.begin();

  /* Creation d'un compteur des successeurs de chaque cube et d'un iterateur*/
  map<EcoAgentID, int> compteur;
  map<EcoAgentID, int>::iterator itcompteur;

  // On intialise le compteur à 0 pour chaque eco-agent
  while(it != m.end()) {
    compteur.insert(pair<EcoAgentID, int>(it->first,0));
    it++;
  }
  it=m.begin();
  for(it = m.begin() ; it != m.end() ; ++it) {
    /* si la position est bien un cube on applique l'algorithme*/ 
    if(*(it->second.getPositionFinale()) != *(p->getTableID())) {
      itcompteur=compteur.find(*(it->second.getPositionFinale()));
      itcompteur->second=itcompteur->second+1;
      if(itcompteur->second > 1) {
	return false;
      }	
    }
  }
  return true;
}
