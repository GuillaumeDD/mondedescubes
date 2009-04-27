#include "cube.hpp"
#include "plateformeMondeDesCubes.hpp"
using namespace std;

Cube::Cube(){
}

Cube::Cube(const EcoAgentID& id){
	setId((EcoAgentID&)id);
}

Cube::~Cube(){}


void Cube::rechercherFuite(){
	EcoAgent *c;
	PlateformeMondeDesCubes *p = PlateformeMondeDesCubes::getInstance();
	c = p->obtenirGeneur(*this);
	if(c == NULL) 
		this->faireFuite();
	else
		this->agresser(*c);		
}


void Cube::rechercherSatisfaction(){
	EcoAgent *c;
	PlateformeMondeDesCubes *p = PlateformeMondeDesCubes::getInstance();
	c = p->obtenirGeneur(*this);
	if(c == NULL) 
		this->faireSatisfaction();
	else
		this->agresser(*c);	
}

void Cube::agresser(EcoAgent& a){
  a.estAgresse();
}

void Cube::estAgresse(){
	setEtat(RECHERCHEFUITE);
}

void Cube::faireFuite(){
	PlateformeMondeDesCubes *p = PlateformeMondeDesCubes::getInstance();
	EcoAgentID *tableID;
	tableID = p->getTableID();
	setPositionCourante(*tableID);
	setEtat(RECHERCHESATISFACTION);
}


void Cube::faireSatisfaction(){
	setPositionCourante(*(getPositionFinale()));
	setEtat(SATISFAIT);
}

void Cube::initialiser(){
	if(getPositionFinale() != NULL && getPositionCourante() != NULL)
		{
		if(getPositionFinale() == getPositionCourante())
			setEtat(SATISFAIT);
		else
			setEtat(RECHERCHESATISFACTION);
		}
}

void Cube::agir(){
	if(getEtat() == RECHERCHESATISFACTION)
		rechercherSatisfaction();
	else if(getEtat() == RECHERCHEFUITE)
		rechercherFuite();
}

ostream & operator<< (ostream &f, const Cube& ea){
  return f << "EcoAgentID :" << *(ea.getId()) << "\n" << "Etat :" << ea.getEtat() << "\n" << "Position courante : sur l'EcoAgent d'identifiant" << *(ea.getPositionCourante()) << endl << "Position finale : sur l'EcoAgent d'identifiant" << *(ea.getPositionFinale())<< endl;
}
