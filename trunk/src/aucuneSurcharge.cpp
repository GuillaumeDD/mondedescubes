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
	map<EcoAgentID, EcoAgent&, compareEcoAgentID>::const_iterator it=p->getEcoAgents().begin();
	/* Creation d'un compteur des successeurs de chaque cube et d'un iterateur*/
	map<EcoAgentID, int> compteur;
	map<EcoAgentID, int>::iterator itcompteur;
	do {
		cout << "it actuel? " << it->first << endl;
		cout << "diff? " << *(it->second.getPositionCourante()) << *(p->getTableID()) << endl;
		cout << "une boucle" << endl;
		/* si la position est bien un cube on applique l'algorithme*/ 
		if(*(it->second.getPositionCourante()) != *(p->getTableID())) {
			/*si ce cube n'est pas encore dans la map compteur on le cree*/
			if(compteur.find(*(it->second.getPositionCourante())) == compteur.end()) {
				cout << "creation ds le compteur" << endl;
				compteur.insert(pair<EcoAgentID, int>(*(it->second.getPositionCourante()),0));
			}

			cout << "recherche ds le compteur" << endl;
			itcompteur=compteur.find(*(it->second.getPositionCourante()));
			itcompteur->second=itcompteur->second+1;
			if(itcompteur->second > 1) {
				cout << "faux" << endl;
				return false;
			}	
		}
	it++;
	}
	while(it != p->getEcoAgents().end());
	cout << "vrai" << endl;
	return true;
}


bool AucuneSurcharge::serontPasSurcharges() {
	PlateformeMondeDesCubes *p = PlateformeMondeDesCubes::getInstance();
	/* Mise en place d'un iterateur sur la map des cubes de la plate forme */
	map<EcoAgentID, EcoAgent&>::const_iterator it;
	
	/* Creation d'un compteur du nombre de successeurs de chaque cube et creation d'un iterateur*/
	map<EcoAgentID, int> compteur;
	map<EcoAgentID, int>::iterator itcompteur;

	for(it = p->getEcoAgents().begin(); it != p->getEcoAgents().end(); ++it) {

		/* si la position est bien un cube on applique l'algorithme*/ 
		if(it->second.getPositionFinale() != p->getTableID()) {
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
