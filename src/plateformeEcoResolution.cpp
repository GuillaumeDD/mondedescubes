#include"plateformeEcoResolution.hpp"

PlateformeEcoResolution::PlateformeEcoResolution(){
}

PlateformeEcoResolution::~PlateformeEcoResolution(){
	/*
	//destruction des eco-agents
	map<EcoAgentID,EcoAgent&>::iterator itEcoAgent;
	itEcoAgent = ecoagents.begin();
	while(itEcoAgent != ecoagents.end()){
	 delete &((*itEcoAgent).second); 
	}

	//destruction des regles
	list<Regle*>::iterator itRegle;
	itRegle = regles.begin();
	while(itRegle != regles.end())
	{
	  delete &((*itRegle));
	}
	*/
}

EcoAgent* PlateformeEcoResolution::getEcoAgent(const EcoAgentID& id){
  EcoAgent* result = NULL;
  map<EcoAgentID, EcoAgent&>::iterator it;
  it = ecoagents.find(id);
  if(it == ecoagents.end()){
    cout << "EcoAgent inexistant " << endl ;
  }else{
      result=&((*it).second);
  }
  return result;
}

void PlateformeEcoResolution::addEcoAgent(EcoAgent& ea){
 pair<map<EcoAgentID,EcoAgent&>::iterator, bool> ret;
 ret = ecoagents.insert(pair<EcoAgentID,EcoAgent&>(*(ea.getId()), ea));
 if(ret.second == false){
    cout << "Attention : cet ecoAgent a deja ete enregistre" << ea << endl;
 }
}

void PlateformeEcoResolution::addRegle(Regle& r){
 regles.push_back(&r); 
}

bool PlateformeEcoResolution::verifierCoherence(){
    bool result = true;
    list<Regle*>::iterator it;
    it = regles.begin();
    while(it != regles.end() && result){
      // verification des regles une par une
      if(!(*(*it)).verifier()){
	result = false;
      }
      it++; 
    }
    return result;
}

bool PlateformeEcoResolution::sontSatisfaits(){
  bool result = true;
  map<EcoAgentID,EcoAgent&>::iterator it;
  it = ecoagents.begin();
  while(it != ecoagents.end() && result){
    if( ((*it).second).getEtat() != SATISFAIT ){
      result = false;
    }
    it++;
  }
  return result;
}
