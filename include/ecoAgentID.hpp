#ifndef __ECOAGENTID__
  #define __ECOAGENTID__
  /*!
  * \file ecoAgentID.hpp
  * \brief Implementation de la classe EcoAgentID
  * \author GDD
  * \author Arnaud Faure
  * \author Pauline Requena
  * \version 0.1
  * \date 04 avril 2009
  *
  * Implementation de la classe EcoAgentID qui est un identifiant unique d'un eco-agent
  *
  */

  #include<iostream>
  using namespace std;
  
   /*!
  * \class EcoAgentID
  * \brief Identifiant unique d'un eco-agent 
  *
  * La classe EcoAgentID represente un identifiant unique d'un eco-agent. Il permet la generation automatique
  * des identifiants
  *
  */  
  class EcoAgentID{
    public:
      /*!
      * \brief Constructeur
      *	
      * Constructeur de la classe EcoAgentID
      *
      */
      EcoAgentID();
      
      /*!
      * \brief Destructeur
      *
      * Destructeur de la classe EcoAgentID
      *
      */
      ~EcoAgentID();
      
      /*!
      *  \brief Obtention de l'identifiant
      *
      * Methode qui retourne l'identifiant de l'eco-agent
      *
      */
      int getId() const;
      
      /*!
      *  \brief Comparaison de EcoAgentID
      *
      * Methode qui permet de comparer deux EcoAgentID
      *
      */
      bool operator ==(const EcoAgentID&) const;
      
    private:
      int identifiant;
      static int nombreDeGeneration;
  };
#endif