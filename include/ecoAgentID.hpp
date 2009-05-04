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
   * \brief Constructeur avec un identifiant specifie
   * Ce constructeur cree un EcoAgentID avec l'identifiant donne en parametre
   * \param id : valeur de l'identifiant de l'EcoAgentID cree
   */
  EcoAgentID(const int id);

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
      
  /*!
   *  \brief Comparaison de EcoAgentID
   *
   * Methode qui permet de comparer deux EcoAgentID
   *
   */
  bool operator !=(const EcoAgentID&) const;
      
  /*!
   *  \brief Comparaison de EcoAgentID
   *
   * Methode qui permet de comparer deux EcoAgentID
   *
   */
  bool operator <(const EcoAgentID&) const;
      
  /*!
   *	\brief Obtention du nombre de generation
   *	Methode statique qui permet d'obtenir le nombre de generations d'EcoAgentID
   *
   */
  static int getNombreDeGeneration();

  /*!
   * \brief Cette methode permet d'afficher des informations sur un EcoAgent
   * 
   */
  friend ostream & operator<< (ostream&, const EcoAgentID&);

      
private:
  /*!
   * \brief Genere un identifiant unique
   * Methode qui permet de generer un identifiant unique et comptabilise le nombre de generations
   */
  int genereID();
      
  int identifiant;/*!< Identifiant de l'eco-agent */
  static int nombreDeGeneration;/*!< Nombre de generations d'eco-agent */
};
#endif
