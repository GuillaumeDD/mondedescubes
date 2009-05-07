#ifndef __TABLE__
#define	__TABLE__
/*!
 * \file table.hpp
 * \brief Implementation du module table qui est un derive d'un EcoAgent
 * \author GDD
 * \author Arnaud Faure
 * \author Pauline Requena
 * \version 0.1
 * \date 1er avril 2009
 *
 * Implementation de la classe Table qui est une classe derivee de la classe EcoAgent.
 * La Table est le support sur lequel sont poses les cubes.
 */
#include<iostream>
#include"ecoAgentID.hpp"
#include"ecoAgent.hpp"
using namespace std;

/*! \class Table
 *
 * \brief Classe derivee de la classe EcoAgent designant le support sur lequel vont etre poses les cubes
 *
 * Classe derivee de la classe EcoAgent designant le support sur lequel vont etre poses les cubes. La table est suppose de capacite infinie.
 * C'est a dire qu'il est possible de poser autant de cubes qu'on veut dessus. 
 * La Table est toujours satisfaite.
 */
class Table : public EcoAgent{
public:
  /*!
   * \brief Constructeur
   *
   * Constructeur de la classe Table par defaut. Un EcoAgentID sera automatiquement genere pour la table.
   * L'Etat de la table est fixe a SATISFAIT.
   */
  Table();
    
  /*!
   * \brief Constructeur
   *
   * Constructeur de la classe Table
   *
   *\param id : identifiant unique que la table se verra attribuer
   *
   */
  Table(EcoAgentID& id);

  /*!
   * \brief Destructeur
   *
   * Destructeur de la classe Table
   *
   */
  ~Table();

  /*!
   * \brief Suite d'operations realisees par la table lorsqu'elle cherche a fuir
   * Cette procedure ne fait rien car la table ne fuit jamais.
   *
   */
  void rechercherFuite();
	
  /*!
   * \brief Suite d'operations realisees par la table lorsqu'elle cherche a se satisfaire
   * Cette procedure ne fait rien car la table est toujours satisfaite.
   *
   */
  void rechercherSatisfaction();
	
  /*!
   * \brief Suite d'operations realisees lorsque la table agresse un autre eco-agent
   * Cette procedure ne fait rien car la table n'agresse aucun autre EcoAgent.
   *
   *\param a : EcoAgent a agresser
   *
   */
	
  void agresser(EcoAgent& a);
	
  /*!
   * \brief Suite d'operations realisees par la table lorsqu'elle est agressee
   * Cette procedure ne fait rien car la table ne reagit pas lorsqu'elle est agresse.
   *
   */
  void estAgresse();
	
  /*!
   * \brief Suite d'operations realisees par la fuite lorsqu'elle fuit
   * Cette procedure ne fait rien car la table ne peut pas fuire.
   *
   */
  void faireFuite();

  /*!
   * \brief Suite d'operations realisees par la table lorsqu'elle se satisfait
   * Cette procedure ne fait rien car la table est toujours satisfaite.
   *
   */
  void faireSatisfaction();
	
  /*!
   * \brief Suite d'operations realisees par la table lorsqu'il agit
   * Cette procedure ne fait rien car la table n'agit jamais. C'est juste un support.
   */
  void agir();

  /*!
   * \brief Initialisation de la table avant l'EcoResolution
   * Cette procedure ne fait rien, la table etant toujours satisfaite.
   */
  void initialiser();
};
#endif	

