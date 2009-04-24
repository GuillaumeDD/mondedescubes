#ifndef __ETAT__
  #define __ETAT__
   /*!
 * \file etat.hpp
 * \brief Enumeration des etats possibles des eco-agents
 * \author GDD
 * \author Arnaud Faure
 * \author Pauline Requena
 * \version 0.1
 * \date 04 avril 2009
 *
 * Implementation de l'enumeration des etats que peuvent prendre les eco-agents
 *
  */
   #include<iostream>
   using namespace std;
   
   /*!
   * \enum Etat
   * \brief Enumeration repertoriant les etats possibles d'un eco-agent
   *
   */
   enum Etat{
    SATISFAIT, RECHERCHEFUITE, RECHERCHESATISFACTION
   };

inline ostream& operator<<(ostream &f, const Etat& e){
   switch(e){
	   case SATISFAIT: f << "SATISFAIT"; break;
	   case RECHERCHEFUITE: f << "RECHERCHEFUITE"; break;
	   case RECHERCHESATISFACTION: f << "RECHERCHESATISFACTION"; break;
	}
	return f;
}


#endif
