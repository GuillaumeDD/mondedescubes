#include "table.hpp"

Table::Table(){
this->setEtat(SATISFAIT);
}

Table::Table(EcoAgentID& id){
	this->setId(id);
	this->setEtat(SATISFAIT);}


Table::~Table(){}


void Table::rechercherFuite(){}


void Table::rechercherSatisfaction(){}


void Table::faireSatisfaction(){}


void Table::faireFuite(){}


void Table::agresser(EcoAgent& a){}


void Table::estAgresse(){}


void Table::agir(){}

void Table::initialiser(){}
