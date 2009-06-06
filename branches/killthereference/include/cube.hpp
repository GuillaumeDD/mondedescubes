#ifndef __CUBE__
#define __CUBE__
/*!
 * \file cube.hpp
 * \brief Implementation du module cube qui est un derive d'un EcoAgent.
 * \author GDD
 * \author Arnaud Faure
 * \author Pauline Requena
 * \version 0.1
 * \date 04 avril 2009
 *
 * Implementation de la classe Cube qui est une classe derivee de la classe EcoAgent.
 *
 */
#include<iostream>  
#include "ecoAgent.hpp"
#include "ecoAgentID.hpp"
#include "plateformeEcoResolution.hpp"
  
using namespace std;

/*! \class Cube
 * \brief Classe derivee de la classe EcoAgent designant un Cube
 *
 * Un Cube s'execute generalement dans une PlateformeMondeDesCubes afin de resoudre le probleme du monde des cubes.
 * Un cube peut etre pose sur une Table, un autre Cube et plus generalement un autre EcoAgent en rapport avec le probleme du monde des cubes.
 * Cette classe determine les comportements d'un Cube quand il doit agir dans le cadre d'une eco-resolution (fuite, satisfaction, agression).
 *
 */

class Cube : public EcoAgent
{
public:

  /*!
   * \brief Constructeur
   *
   * Constructeur de la classe Cube par defaut. Le cube recevra un EcoAgentID automatiquement genere.
   *
   */
  Cube();
    
  /*!
   * \brief Constructeur
   *
   * Constructeur de la classe Cube avec un EcoAgentID specifique
   *
   *\param id : identifiant unique que l'agent se verra attribuer
   *
   */
  Cube(const EcoAgentID& id); 


  /*!
   * \brief Destructeur
   *
   * Destructeur de la classe Cube
   *
   */
  ~Cube();

  /*!
   * \brief Suite d'operations realisees par le cube lorsqu'il cherche a fuir
   * Le comportement de recherche de fuite est le suivant : le cube determine s'il a un geneur (un EcoAgent au dessus de lui ou au dessus de sa position finale).
   * S'il possede un geneur, il l'agresse, sinon il fuit.
   *
   */
  void rechercherFuite();
	
  /*!
   * \brief Suite d'operations realisees par le cube lorsqu'il cherche a se satisfaire
   * Le comportement de recherche de satisfaction est le suivant : le cube determine s'il a un geneur (un EcoAgent au dessus de lui ou au dessus de sa position finale).
   * S'il possede un geneur, il l'agresse, sinon il se satisfait.
   *
   */
  void rechercherSatisfaction();
	
  /*!
   * \brief Suite d'operations realisees lorsque le cube agresse un autre eco-agent
   *
   *
   *\param a : EcoAgent a agresser
   *
   */
  void agresser(EcoAgent& a);
	
  /*!
   * \brief Suite d'operations realisees par le cube lorsqu'il est agressee
   * Lorsque le cube est agresse, il passe son Etat en RECHERCHEFUITE.
   *
   */
  void estAgresse();
	
  /*!
   * \brief Suite d'operations realisees par le cube lorsqu'il fuit
   * Si le cube est agresse par le cube qui est sa position finale ou alors que sa position finale n'est pas satisfaite alors le cube fuit sur la table.
   * Sinon le cube fuit en allant directement sur le cube qui est sa position finale.
   */
  void faireFuite();

  /*!
   * \brief Suite d'operations realisees par le cube lorsqu'il se satisfait
   * Le cube se deplace sur sa position finale et passe sont Etat a SATISFAIT.
   *
   */
  void faireSatisfaction();
	
  /*!
   * \brief Initialisation de l'etat du cube
   *
   * Cette methode permet d'initialiser l'etat du cube en prenant en compte sa position courante et sa position finale.
   * Par exemple, si la position courante correspond a la position finale, cette methode initialisera l'Etat a SATISFAIT.
   *
   */
  void initialiser();

  /*!
   * \brief Suite d'operations realisees par le cube lorsqu'il agit
   * Le cube determine comment il doit agir en fonction de son Etat. S'il est en RECHERCHESATISFACTION il execute rechercherSatisfaction(), s'il est en RECHERCHEFUITE il execute rechercherFuite().
   */
  void agir();

  /*!
   * \brief Suite d'operations permettant d'afficher des informations sur le cube
   * Affichage d'information sur le cube comme son EcoAgentID, sont Etat et ses positions initiale et finale.
   */
  friend ostream & operator<< (ostream &f, const Cube& c);
};

#endif
