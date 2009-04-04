#ifndef __PLATEFORMEECORESOLUTION__
  #define __PLATEFORMEECORESOLUTION__
  /*!
  * \file plateformeEcoResolution.hpp
  * \brief Plateforme abstraite d'eco-resolution
  * \author GDD
  * \author Pauline Requena
  * \author Arnaud Faure
  * \version 0.1
  * \date 29 mars 2009
  */
  #include<iostream>
  #include<map>
  #include<list>
  #include"plateformeEcoResolution.hpp"
  #include"ecoAgentID.hpp"
  #include"ecoAgent.hpp"
  #include"regle.hpp"
  using namespace std;
  /*! \class PlateformeEcoResolution
  * \brief classe representant une plateforme d'eco-resolution abstraite
  *
  *  La classe gere les fonctionnalites basiques d'une plateforme d'eco-resolution.
  */
  class PlateformeEcoResolution{
    public:
      /*!
       * \brief Constructeur
       *
       * Constructeur de la classe abstraite PlateformeEcoResolution
       *
       */
      PlateformeEcoResolution();
      
      /*!
      * \brief Destructeur
      *
      * Destructeur de la classe abstraite PlateformeEcoResolution
      *
      */
      ~PlateformeEcoResolution();
      
      /*!
      * \brief Obtention d'un eco-agent
      *
      * Methode qui permet d'obtenir un eco-agent de la plateforme a partir de son identifiant
      *
      * \param id : id de l'eco-agent voulu
      * \return un pointeur sur l'eco-agent recherche s'il existe, NULL sinon
      */
      EcoAgent* getEcoAgent(const EcoAgentID& id) const;
      
      /*!
      * \brief Ajout d'un eco-agent
      *
      * Methode qui permet d'ajouter un eco-agent dans la plateforme
      *
      * \param ea : l'eco-agent a ajouter
      *
      */      
      void addEcoAgent(const EcoAgent& ea);
      
      /*!
      * \brief Ajout d'une nouvelle regle
      *
      * Methode qui permet d'ajouter une nouvelle regle dans la plateforme
      *
      * \param r : la regle a ajouter
      *
      */      
      void addRegle(const Regle& r);
            
      /*!
      * \brief Initialisation de la resolution
      *
      * Methode qui permet d'initialiser le probleme avant d'attaquer la resolution
      *
      */    
      virtual void initialiser()=0;
      
      /*!
      *\brief Resolution du probleme par eco-resolution
      *
      * Methode qui permet de lancer la resolution du probleme par eco-resolution
      *
      */
      virtual void resoudre()=0;
      
      /*!
      *\brief Verification du respect des regles apres l'initialisation de la plateforme
      *
      * Methode qui permet de verifier l'ensemble des regles apres l'initialisation de la plateforme
      *
      *\return true si toutes les regles sont verifiees, false sinon
      *
      */
      virtual bool verifierCoherence()=0;
      
    private:
      map<EcoAgentID,EcoAgent&> ecoagents; /*!< Referencement des eco-agents a partir de leurs identifiants uniques*/
      list<Regle*> regles; /*!< Liste des regles a verifier avant de lancer la resolution */
  };

#endif
