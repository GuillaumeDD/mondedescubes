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
   
#endif