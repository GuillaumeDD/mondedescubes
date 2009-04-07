#ifndef __PLATEFORMEMONDEDESCUBES__
#define	__PLATEFORMEMONDEDESCUBES__

/*!
  * \file plateformeMondeDesCubes.hpp
  * \brief Plateforme d'eco-resolution appliquee au monde des cubes
  * \author GDD
  * \author Pauline Requena
  * \author Arnaud Faure
  * \version 0.1
  * \date 02 avril 2009
  */

  #include<iostream>
  #include "plateformeEcoResolution.hpp"
  #include "singleton.hpp"
  #include "regle.hpp"
  #include "ecoAgent.hpp"
  #include "ecoAgentID.hpp"
  #include "table.hpp"
  #include "cube.hpp"
  
  using namespace std;

  /*!
   * \class PlateformeMondeDesCubes
   * \brief Classe representant une plateforme d'eco-resolution appliquee au monde des cubes
   *
   *  La classe gere les fonctionnalites de la plateforme d'eco-resolution du monde des cubes.
   */

  class PlateformeMondeDesCubes : public PlateformeEcoResolution, public Singleton<PlateformeMondeDesCubes>{
  friend class Singleton<PlateformeMondeDesCubes>; //ligne necessaire pour que le template Singleton ait acces au constructeur de cette classe
    public:

      /*!
       * \brief Constructeur
       *
       * Constructeur de la classe PlateformeMondeDesCubes derivee de la classe PlateformeEcoResolution
       *
       */
      PlateformeMondeDesCubes();

      /*!
      * \brief Destructeur
      *
      * Destructeur de la classe PlateformeMondeDesCubes derivee de la classe PlateformeEcoResolution
      *
      */
      ~PlateformeMondeDesCubes();

           

      /*!
      * \brief Initialisation de la resolution du monde des cubes
      *
      * Methode qui permet d'initialiser le probleme avant d'attaquer la resolution
      * Les cubes sont disposes sur la table selon une position initiale et une position finale est determinee
      */
      void initialiser();

      /*!
      *\brief Resolution du probleme du monde des cubes par eco-resolution
      *
      * Methode qui permet de lancer la resolution du probleme du monde des cubes par eco-resolution
      *
      */
      void resoudre();

      /*!
      *\brief Verification du respect des regles apres l'initialisation de la plateforme
      *
      * Methode qui permet de verifier l'ensemble des regles apres l'initialisation de la plateforme
      *
      *\return true si toutes les regles sont verifiees, false sinon
      *
      */
      bool verifierCoherence();

      /*!
      *\brief Obtention du cube qui a la priorite pour agir dans la plateforme d'eco-resolution
      *
      * Methode qui permet d'obtenir le cube qui doit agir en priorite dans la plateforme d'eco-resolution
      *
      *\return un pointeur sur le Cube prioritaire s'il existe, NULL sinon
      *
      */
      Cube* obtenirCubePrioritaire();

      /*!
      *\brief Determination du nombre de cubes dans la plateforme d'eco-resolution
      *
      * Methode qui permet de fixer le nombre de cubes de la plateforme d'eco-resolution
      *
      *\param nb : le nombre de cubes
      *
      */
      void setNombreDeCubes(int nb);

       /*!
      *\brief Determination de l'identifiant de la table dans la plateforme
      *
      * Methode qui permet de fixer l'identifiant de la table de la plateforme d'eco-resolution
      *
      *\param id : identifiant de la table
      *
      */
      void setTableIdentifiant(const EcoAgentID& id);

      /*!
      *\brief Verification de la coherence du nombre de cubes (s'il est bien positif)
      *
      * Methode qui permet de verifier si le nombre des cubes est bien strictement positif
      *
      *\return true si le nombre des cubes est strictement positif, false sinon
      *
      */
      bool verifierNombreDeCubes();

      /*!
      *\brief Obtention du geneur du cube courant
      *
      * Methode qui permet d'obtenir le geneur du cube courant
      *
      *\param currentCube : le cube courant
      *\return un pointeur sur le cube geneur s'il existe, NULL sinon
      *
      */
      Cube* obtenirGeneur(const Cube& currentCube);

      /*!
      *\brief Ajout d'un cube dans la plateforme
      *
      * Methode qui permet d'ajouter un cube dans la plateforme d'eco-resolution
      *
      *\param cube : le cube a ajouter
      *
      */
      void addEcoAgent(const Cube& cube);

      /*!
      *\brief Determination de la position finale d'un cube de la plateforme
      *
      * Methode qui permet de fixer la position finale d'un cube de la plateforme
      *
      *\param c : identifiant du cube a positionner
      *\param pos : position finale du cube, ie identifiant du cube destinataire
      *
      */
      void setPositionFinale(const EcoAgentID& c,const EcoAgent& pos);

      /*!
      *\brief Determination de la position courante d'un cube de la plateforme
      *
      * Methode qui permet de fixer la position courante d'un cube de la plateforme
      *
      *\param c : identifiant du cube a positionner
      *\param pos : position courante du cube, ie identifiant du cube destinataire
      *
      */
      void setPositionCourante(const EcoAgentID& c,const EcoAgent& pos);

     /*!
      *\brief Determination de l'identifiant d'un cube
      *
      * Methode qui permet de fixer l'identifiant d'un cube de la plateforme lorsqu'on l'initialise
      *
      *\param currentCube : cube a identifier
      *\param id : identifiant du cube
      *
      */
      void setCubeID(const Cube& currentCube,const EcoAgentID& id);

      /*!
      *\brief Obtention de l'identifiant de la table
      *
      * Methode qui permet d'obtenir l'identifiant de la table
      *
      *\return l'identifiant de la table (de type EcoAgentID)
      *
      */
      EcoAgentID getTableID();

    private:
     Table table; /*!< Table : Support de tous les cubes dans la plateforme d'eco-resolution du monde des cubes */
  };


#endif	
