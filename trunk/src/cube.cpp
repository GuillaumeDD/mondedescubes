#include "cube.hpp"
#include "ecoAgent.hpp"
#include "ecoAgentID.hpp"
#include "plateformeMondeDesCubes.hpp"

using namespace std;

Cube::Cube(){
	EcoAgentID *eaid;
	eaid = new EcoAgentID();
	this->EcoAgent::setId(*eaid);
}

Cube::Cube(const EcoAgentID& id){
	this->EcoAgent::setId((EcoAgentID&)id);
}

Cube::~Cube(){}


void Cube::rechercherFuite(){
	Cube *c;
	c=new Cube();
	//PlateformeMondeDesCubes *p = PlateformeMondeDesCubes::getInstance();
	//c=p->obtenirGeneur((Cube)this);
	if(c == NULL) 
		this->faireFuite();
	else
		this->agresser(*c);		
}


void Cube::rechercherSatisfaction(){
	Cube *c;
	c=new Cube();
	//PlateformeMondeDesCubes *p = PlateformeMondeDesCubes::getInstance();
	//c=p->obtenirGeneur((Cube)this);
	if(c == NULL) 
		this->faireSatisfaction();
	else
		this->agresser(*c);	
}

void Cube::agresser(const Cube& a){
	((Cube)a).estAgresse();}

void Cube::agresser(const EcoAgent& a){}


void Cube::estAgresse(){
	this->EcoAgent::setEtat(RECHERCHEFUITE);}


void Cube::faireFuite(){
	//PlateformeMondeDesCubes *p = PlateformeMondeDesCubes::getInstance();
	EcoAgentID *tableID;
	//tableID = p->getTableID();
	this->EcoAgent::setPositionCourante(*tableID);
	this->EcoAgent::setEtat(RECHERCHESATISFACTION);}


void Cube::faireSatisfaction(){
	this->EcoAgent::setPositionCourante(*(this->getPositionFinale()));
	this->EcoAgent::setEtat(SATISFAIT);}


void Cube::initialiserEtat(){
	if(this->EcoAgent::getPositionFinale() != NULL && this->EcoAgent::getPositionCourante() != NULL)
		{
		if(this->EcoAgent::getPositionFinale() == this->EcoAgent::getPositionCourante())
			this->EcoAgent::setEtat(SATISFAIT);
		else
			this->EcoAgent::setEtat(RECHERCHESATISFACTION);
		}
}

void Cube::agir(){
	if(this->EcoAgent::getEtat() == RECHERCHESATISFACTION)
		this->rechercherSatisfaction();
	else if(this->EcoAgent::getEtat() == RECHERCHEFUITE)
		this->rechercherFuite();}
