#include "aucuneSurcharge.hpp"


using namespace std;


void AucuneSurcharge::initialiser() {
}
      

bool AucuneSurcharge::verifier() {
	if(pasSurcharges() == false) {
		return false;
	}
	if(serontPasSurcharges() == false) {
		return false;
	}
	return true;
}
	
	
bool AucuneSurcharge::pasSurcharges() {
	PlateformeMondeDesCubes *p = PlateformeMondeDesCubes::getInstance();
	/* Mise en place d'un iterateur sur la map des cubes de la plate forme */
	map<EcoAgentID, EcoAgent&>::const_iterator it=p->getCubes().begin();
	
	/* Creation d'un compteur des successeurs de chaque cube et d'un iterateur*/
	map<EcoAgentID, int> compteur;
	map<EcoAgentID, int>::iterator itcompteur;

	for(it = p->getCubes().begin(); it != p->getCubes().end(); ++it) {

		/* si la position est bien un cube on applique l'algorithme*/ 
		if(p->getCubes().find(it->second.getPositionCourante()) != p->getCubes().end()) {
			/*si ce cube n'est pas encore dans la map compteur on le cree*/
			if(compteur.find(*(it->second.getPositionCourante())) == compteur.end()) {
				compteur.insert(pair<EcoAgentID, int>(*(it->second.getPositionCourante()),0));
			}
			itcompteur=compteur.find(*(it->second.getPositionCourante()));
			itcompteur->second++;
			if(itcompteur->second > 1) {
				return false;
			}
		}
	}
	return true;
}


bool AucuneSurcharge::serontPasSurcharges() {
	PlateformeMondeDesCubes *p = PlateformeMondeDesCubes::getInstance();
	/* Mise en place d'un iterateur sur la map des cubes de la plate forme */
	map<EcoAgentID, EcoAgent&>::const_iterator it;
	
	/* Creation d'un compteur du nombre de successeurs de chaque cube et creation d'un iterateur*/
	map<EcoAgentID, int> compteur;
	map<EcoAgentID, int>::iterator itcompteur;

	for(it = p->getCubes().begin(); it != p->getCubes().end(); ++it) {

		/* si la position est bien un cube on applique l'algorithme*/ 
		if(p->getCubes().find(*(it->second.getPositionFinale())) != p->getCubes().end()) {
			/*si ce cube n'est pas encore dans le compteur on le cree*/
			if(compteur.find(*(it->second.getPositionFinale())) == compteur.end()) {
				compteur.insert(pair<EcoAgentID, int>(*(it->second.getPositionFinale()),0));
			}
			itcompteur=compteur.find(*(it->second.getPositionFinale()));
			itcompteur->second++;
			if(itcompteur->second > 1) {
				return false;
			}
		}
	}
	return true;
}
