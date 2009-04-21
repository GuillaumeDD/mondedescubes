#include "reliesATable.hpp"

using namespace std;
  


void ReliesATable::initialiser() {
}
      

bool ReliesATable::verifier(){
	bool b = true;
	PlateformeMondeDesCubes *p = PlateformeMondeDesCubes::getInstance();
	/* creation de 2 iterateurs de la map de cubes : 1 pour les parcourir et 2 pour initialiser leur "visite" a faux*/ 
	map<EcoAgentID, EcoAgent&>::iterator it1=p->getCubes().begin();
	map<EcoAgentID, EcoAgent&>::iterator it2=p->getCubes().begin();

	/*On parcourt toute la map de cube avec it1*/
	for(it1 = p->getCubes().begin(); it1 != p->getCubes().end(); ++it1) {

		/*on initialise toutes les visites a false avant de tester si le cube "courant" est bien relie a la table*/
		for(it2 = p->getCubes().begin(); it2 != p->getCubes().end(); ++it2) {
			it2->second.setVisite(false);
		}
		
		/*on fait appel a la fonction pour savoir si le cube est lie a la table*/
		b = estRelieATable(it1->second);
		if(b == false) {
			return b;
		}

		/*on initialise toutes les visites a false avant de tester si le cube "courant" est bien relie a la table*/
		for(it2 = p->getCubes().begin(); it2 != p->getCubes().end(); ++it2) {
			it2->second.setVisite(false);
		}

		/*on fait appel a la fonction pour savoir si le cube sera lie a la table*/
		b = seraRelieATable(it1->second);
		if(b == false) {
			return b;
		}
	}
	
	return b;
}


bool ReliesATable::estRelieATable(EcoAgent &c) {
	PlateformeMondeDesCubes *p = PlateformeMondeDesCubes::getInstance();
	/*on teste si on a deja visite ce cube*/
	if(c.getVisite() == true){
		return false;
	}
	else {
		c.setVisite(true);
		if(c.getPositionCourante() == NULL) {
			return false;
		}
		else {
			if(c.getPositionCourante() == p->getTableID()) {
				return true;
			}
			else {
				/* On teste si l'eco agent sur lequel est positionne le cube existe*/
				if(p->getEcoAgent(*(c.getPositionCourante())) == NULL) {
					return false;
				}
				else {
					return estRelieATable(*(p->getEcoAgent(*(c.getPositionCourante()))));
				}
			}
		}
	}
}

bool ReliesATable::seraRelieATable(EcoAgent &c) {
	PlateformeMondeDesCubes *p = PlateformeMondeDesCubes::getInstance();
	if(c.getVisite() == true){
		return false;
	}
	else {
		c.setVisite(true);
		if(c.getPositionFinale() == NULL) {
			return false;
		}
		else {
			if(c.getPositionFinale() == p->getTableID()) {
				return true;
			}
			else {
				if(p->getEcoAgent(*(c.getPositionFinale())) == NULL) {
					return false;
				}
				else {
					return estRelieATable(*(p->getEcoAgent(*(c.getPositionFinale()))));
				}
			}
		}
	}
}

