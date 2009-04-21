#include "cube.hpp"
#include "plateformeMondeDesCubes.hpp"

using namespace std;

Cube::Cube(){
	EcoAgentID *eaid;
	eaid = new EcoAgentID();
	EcoAgent::setId(*eaid);
}

Cube::Cube(const EcoAgentID& id){
	EcoAgent::setId((EcoAgentID&)id);
}

Cube::~Cube(){}


void Cube::rechercherFuite(){
	Cube *c;
	PlateformeMondeDesCubes *p = PlateformeMondeDesCubes::getInstance();
	c = p->obtenirGeneur(*this);
	if(c == NULL) 
		this->faireFuite();
	else
		this->agresser(*c);		
}


void Cube::rechercherSatisfaction(){
	Cube *c;
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
  return f << "EcoAgentID :" << c.EcoAgent::getId()->getId() << "\n" << "Etat :" << c.EcoAgent::getEtat() << "\n" << "Position courante : sur l'EcoAgent d'identifiant" << c.EcoAgent::getPositionCourante()->getId() << "\n" << "Position finale : sur l'EcoAgent d'identifiant" << c.EcoAgent::getPositionFinale()->getId()<<"\n";
}



