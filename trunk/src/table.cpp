#include "table.hpp"

Table::Table(){
	EcoAgentID *id;
	id = new EcoAgentID();
	this->EcoAgent::setId(*id);}

Table::Table(EcoAgentID& id){
	this->EcoAgent::setId(id);}


Table::~Table(){}


void Table::rechercherFuite(){}


void Table::rechercherSatisfaction(){}


void Table::faireSatisfaction(){}


void Table::faireFuite(){}


void Table::agresser(const EcoAgent& a){}


void Table::estAgresse(){}


void Table::agir(){}
