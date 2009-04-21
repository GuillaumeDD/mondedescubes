#include "cube.hpp"
#include "plateformeMondeDesCubes.hpp"

using namespace std;

Cube::Cube(){
	EcoAgentID *eaid;
	eaid = new EcoAgentID();
	setId(*eaid);
}

Cube::Cube(const EcoAgentID& id){
	setId((EcoAgentID&)id);
}

Cube::~Cube(){}


void Cube::rechercherFuite(){
	Cube *c;
	PlateformeMondeDesCubes *p = PlateformeMondeDesCubes::getInstance();
	c = p->obtenirGeneur(*this);
	if(c == NULL) 
		faireFuite();
	else
		agresser(*c);		
}


void Cube::rechercherSatisfaction(){
	Cube *c;
	PlateformeMondeDesCubes *p = PlateformeMondeDesCubes::getInstance();
	c = p->obtenirGeneur(*this);
	if(c == NULL) 
		faireSatisfaction();
	else
		agresser(*c);	
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

void Cube::initialiserEtat(){
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

ostream & operator<< (ostream &f, const Cube& c){
  return f << "EcoAgentID :" << c.getId()->getId() << "\n" << "Etat :" << c.getEtat() << "\n" << "Position courante : sur l'EcoAgent d'identifiant" << c.getPositionCourante()->getId() << "\n" << "Position finale : sur l'EcoAgent d'identifiant" << c.getPositionFinale()->getId()<<"\n";
}



