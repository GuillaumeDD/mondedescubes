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
  #include<stdio>
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
      * \return l'eco-agent recherche s'il existe, NULL sinon
      */
      EcoAgent getEcoAgent(EcoAgentID id);
      
      /*!
      * \brief Ajout d'un eco-agent
      *
      * Methode qui permet d'ajouter un eco-agent dans la plateforme
      *
      * \param ea : l'eco-agent a ajouter
      *
      */      
      void addEcoAgent(EcoAgent ea);
      
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
      
  };

#endif