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
#include <string>
#include<algorithm>
  
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
   * \brief Initialisation de la resolution du monde des cubes
   *
   * Methode qui permet d'initialiser le probleme avant d'attaquer la resolution
   * Les cubes sont disposes sur la table selon une position initiale et une position finale est determinee
   */
  void initialiser();

  /*!
   *\brief Resolution du probleme du monde des cubes par eco-resolution
   *
   * Methode qui permet de realiser une etape et une seule de la resolution du probleme du monde des cubes par eco-resolution
   *
   */
  void resoudre();

  /*!
   *\brief Obtention de l'EcoAgent qui a la priorite pour agir dans la plateforme d'eco-resolution du monde des cubes
   *
   * Methode qui permet d'obtenir l'EcoAgent qui doit agir en priorite dans la plateforme d'eco-resolution du monde des cubes
   *
   *\return un pointeur sur l'EcoAgent prioritaire s'il existe, NULL sinon
   *
   */
  EcoAgent* obtenirCubePrioritaire() const;

  /*!
   *\brief Obtention du nombre de cubes present dans la plateforme d'eco-resolution
   *
   * Methode qui permet d'obtenir le nombre de cubes present dans la plateforme d'eco-resolution
   *
   *\return le nombre de cubes
   *
   */
  int getNombreDeCubes() const;
      
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
   *\brief Obtention de l'identifiant de la table
   *
   * Methode qui permet d'obtenir l'identifiant de la table
   *
   *\return (l'identifiant de la table (de type EcoAgentID)) ==> un pointeur sur l'identifiant de la table de type EcoAgentID*
   *
   */
  EcoAgentID* getTableID() const;
      
  /*!
   *\brief Obtention du geneur de l'EcoAgent courant
   *
   * Methode qui permet d'obtenir le geneur de l'EcoAgent courant
   * Cette methode retourne NULL quand la position courante de l'EcoAgent est sa
   * position finale (ou s'il n'y a aucun geneur)
   *
   *\param currentCube : l'EcoAgent courant
   *\return un pointeur sur l'EcoAgent geneur s'il existe, NULL sinon
   *
   */
  EcoAgent* obtenirGeneur(const EcoAgent& currentCube);

  /*!
   *\brief Determination de la position finale d'un EcoAgent de la plateforme
   *
   * Methode qui permet de fixer la position finale d'un cube de la plateforme
   *
   *\param c : identifiant de l'EcoAgent a positionner
   *\param pos : position finale de l'EcoAgent, ie identifiant du cube destinataire
   *
   */
  void setPositionFinale(const EcoAgentID& c,const EcoAgentID& pos);

  /*!
   *\brief Determination de la position courante d'un EcoAgent de la plateforme
   *
   * Methode qui permet de fixer la position courante d'un cube de la plateforme
   *
   *\param c : identifiant de l'EcoAgent a positionner
   *\param pos : position courante de l'EcoAgent, ie identifiant du cube destinataire
   *
   */
  void setPositionCourante(const EcoAgentID& c,const EcoAgentID& pos);

  /*!
   *\brief Determination de l'identifiant d'un cube
   *
   * Methode qui permet de fixer l'identifiant d'un cube de la plateforme lorsqu'on l'initialise
   *
   *\param currentCube : cube a identifier
   *\param id : identifiant du cube
   *
   */
  void setCubeID(EcoAgent& currentCube,const EcoAgentID& id);

  /*!
   * \brief Determination du nombre d'EcoAgent separant de la table
   *
   * Cette methode permet de determiner le nombre d'EcoAgent separant un EcoAgent de la table
   * en position courante.
   *
   * \param c : identifiant de l'EcoAgent
   * \return La distance a la table
   */
  int distanceATable(const EcoAgentID& c) const;


  /*!
   * \brief Determination du nombre d'EcoAgent separant de la table en position finale
   *
   * Cette methode permet de determiner le nombre d'EcoAgent separant un EcoAgent de la table
   * en position finale.
   *
   * \param c : identifiant de l'EcoAgent
   * \return La distance a la table
   */
  int distanceFinaleATable(const EcoAgentID& c) const;

  /*!
   * \brief Ajout d'un EcoAgent en verifiant que l'EcoAgentID est different de celui de la Table
   *
   * Methode qui permet d'ajouter un eco-agent dans la plateforme tout en verifiant que l'identifiant de celui-ci est different de l'identifiant de la table
   * \throw ExceptionEcoAgentDejaEnregistre : lancee lorsqu'on enregistre un EcoAgent deja enregistre, autrement dit lorsqu'un EcoAgent avec le meme EcoAgentID a deja ete ajoute.
   * \param ea : l'EcoAgent a ajouter
   *
   */
  void addEcoAgent(EcoAgent& ea);

  /*!
   * \brief Redefinition d'operateur qui permet d'obtenir des informations sur la plateforme
   * Redefinition d'operateur qui permet d'obtenir des informations sur la plateforme
   * monde des cubes
   *
   *Redefinition d'operateur qui permet d'obtenir des informations sur la plateforme
   * Redefinition d'operateur qui permet d'obtenir des informations sur la plateforme
   * monde des cubes
   *
   */
  friend ostream& operator<<(ostream &,const PlateformeMondeDesCubes&);

  /*!
   * \brief Methode qui permet d'obtenir un affichage minimal de l'agencement des cubes
   *
   * Methode qui permet d'obtenir un affichage minimal de l'agencement des cubes
   *
   * \return La chaine de caractere de type string a afficher
   */
  string toString() const;

private:

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
      
  Table* table; /*!< Table : Support de tous les cubes dans la plateforme d'eco-resolution du monde des cubes */
};


#endif	

