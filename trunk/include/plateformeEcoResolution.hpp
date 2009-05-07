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
#include"ecoAgentID.hpp"
#include"ecoAgent.hpp"
#include"regle.hpp"
#include"compareEcoAgentID.hpp"
#include "Exceptions.hpp"
using namespace std;
/*! \class PlateformeEcoResolution
 * \brief classe representant une plateforme d'eco-resolution abstraite
 *
 * La classe gere les fonctionnalites basiques d'une plateforme d'eco-resolution.
 * Elle permet l'ajout d'EcoAgent et les references grace a leur identifiant EcoAgentID.
 * Elle integre un ensemble de fonctionnalites "basiques" qui permettent par exemple d'obtenir un EcoAgent reference a partir de son ID, d'ajouter des regles et de les verifier.
 * Bien evidemment, la plateforme permet de lancer la resolution en elle-meme.
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
   * \brief Obtention d'un EcoAgent
   *
   * Methode qui permet d'obtenir un EcoAgent de la plateforme a partir de son identifiant
   *
   * \param id : id de l'EcoAgent voulu
   * \return un pointeur sur l'EcoAgent recherche s'il existe, NULL sinon
   */
  EcoAgent* getEcoAgent(const EcoAgentID& id) const;
      
  /*!
   * \brief Ajout d'un EcoAgent
   *
   * Methode qui permet d'ajouter un EcoAgent dans la plateforme. Il est alors reference par son EcoAgentID.
   * \throw ExceptionEcoAgentDejaEnregistre : lancee lorsqu'on enregistre un EcoAgent deja enregistre, autrement dit lorsqu'un EcoAgent avec le meme EcoAgentID a deja ete ajoute.
   * \param ea : l'EcoAgent a ajouter
   *
   */      
  virtual void addEcoAgent(EcoAgent& ea);
      
  /*!
   * \brief Ajout d'une nouvelle regle
   *
   * Methode qui permet d'ajouter une nouvelle Regle dans la plateforme
   *
   * \param r : la Regle a ajouter
   *
   */      
  void addRegle(Regle& r);
     
  /*!
   * \brief Obtention de la liste des regles
   *
   * Methode qui permet d'obtenir la liste des regles
   *
   *\return La liste des regles list<Regle*>
   *
   */
  list<Regle*> getRegles();

  /*!
   *\brief Verification du respect des regles apres l'initialisation de la plateforme
   *
   * Methode qui permet de verifier l'ensemble des regles de la plateforme.
   *
   *\return true si toutes les regles sont verifiees, false sinon
   *
   */
  bool verifierCoherence() const;
      
  /*!
   *\brief Methode qui verifie si tous les EcoAgents sont satisfaits i.e. si la resolution est terminee.
   *
   * Methode qui verifie si tous les eco-agents sont satisfaits. Elle permet de determiner quand la resolution est terminee.
   *
   *\return true si tous les EcoAgents sont satisfaits, false sinon
   *
   */
  bool sontSatisfaits() const;

  /*!
   *\brief Methode qui retourne l'EcoAgentID de l'EcoAgent au dessus
   *
   * Methode qui retourne l'EcoAgentID de l'EcoAgent dont la position courante est l'EcoAgentID passe en parametre 
   *
   * \param id : EcoAgentID dont on cherche l'EcoAgent qui l'a en position courante
   *\return EcoAgentID de l'EcoAgent correspondant, NULL s'il n'y en a pas
   *
   */
  EcoAgentID* getEcoAgentAuDessus(const EcoAgentID& id) const;

  /*!
   * \brief Methode qui retourne le nombre d'EcoAgent au dessus de l'EcoAgent avec l'id specifie
   *
   * Methode qui retourne le nombre d'EcoAgent au dessus de l'EcoAgent avec l'id specifie 
   *
   * \param id : EcoAgentID dont on cherche le nombre d'EcoAgent superieur
   *\return un entier superieur ou egal a 0
   *
   */
  int nombreEcoAgentAuDessus(const EcoAgentID& id) const;
      
  /*!
   * \brief Methode qui retourne les EcoAgentID des EcoAgent possedant l'etat specifie
   *
   * Methode qui retourne les EcoAgentID des EcoAgent possedant un etat specifie dans le parametre de la fonction
   *
   * \param e : l'etat dans lequel tous les EcoAgent listes doivent etre
   * \return la liste des EcoAgentID des EcoAgent dans cet Etat
   */
  list<EcoAgentID*> getEcoAgents(const Etat e) const;
      
  /*!
   *\brief Methode qui retourne tous les eco-agents
   *
   * Methode qui retourne tous les eco-agents. Cette methode est surtout utilisee pour les regles.
   *
   *\return un conteneur associatif map<EcoAgentID,EcoAgent&>
   *
   */
  map<EcoAgentID,EcoAgent&,compareEcoAgentID> getEcoAgents() const;

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
   * Methode qui permet de realiser une etape de la resolution du probleme par eco-resolution
   *
   */
  virtual void resoudre()=0;
      
      
protected:
  map<EcoAgentID,EcoAgent&,compareEcoAgentID> ecoagents; /*!< Referencement des eco-agents a partir de leurs identifiants uniques*/
  list<Regle*> regles; /*!< Liste des regles a verifier avant de lancer la resolution */
};
  
#endif
