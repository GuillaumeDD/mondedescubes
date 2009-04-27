#include "table.hpp"

Table::Table(){
}

Table::Table(EcoAgentID& id){
	this->EcoAgent::setId(id);}


Table::~Table(){}


void Table::rechercherFuite(){}


void Table::rechercherSatisfaction(){}


void Table::faireSatisfaction(){}


void Table::faireFuite(){}


void Table::agresser(EcoAgent& a){}


void Table::estAgresse(){}


void Table::agir(){}

void Table::initialiser(){}
