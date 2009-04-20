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
 *
 */
#include<iostream>
#include"ecoAgentID.hpp"
#include"ecoAgent.hpp"
using namespace std;

 /*! \class Table
 * \brief Classe derivee de la classe EcoAgent designant le Support sur lequel vont etre poses les cubes
 *
 */

class Table : public EcoAgent{
public:
    /*!
     * \brief Constructeur
     *
     * Constructeur de la classe Table par defaut. Un EcoAgentID sera automatiquement genere pour la table.
     *
     */
    Table();
    
    /*!
     * \brief Constructeur
     *
     * Constructeur de la classe Table
     *
     *\param id : identifiant unique que l'agent se verra attribuer
     *
     */
    Table(EcoAgentID& id); // j'ai enlevé le const

    /*!
     * \brief Destructeur
     *
     * Destructeur de la classe Table
     *
     */
     ~Table();

     /*!
	 * \brief Suite d'operations realisees par la table lorsqu'elle cherche a fuir
	 *
	 *
	 */
	void rechercherFuite();
	
	/*!
	 * \brief Suite d'operations realisees par la table lorsqu'elle cherche a se satisfaire
	 *
	 *
	 */
	void rechercherSatisfaction();
	
	/*!
	 * \brief Suite d'operations realisees lorsque la table agresse un autre eco-agent
	 *
	 *
	 *\param a : EcoAgent a agresser
         *
	 */
	
	void agresser(const EcoAgent& a);
	
	/*!
	 * \brief Suite d'operations realisees par la table lorsqu'elle est agressee
	 *
	 *
	 */
	void estAgresse();
	
	/*!
	 * \brief Suite d'operations realisees par la fuite lorsqu'elle fuit
	 *
	 *
	 */
	void faireFuite();

	/*!
	 * \brief Suite d'operations realisees par la table lorsqu'elle se satisfait
	 *
	 *
	 */
	void faireSatisfaction();
	
	/*!
	 * \brief Suite d'operations realisees par la table lorsqu'il agit
	 *
	 */
	void agir();
	
};
#endif	

