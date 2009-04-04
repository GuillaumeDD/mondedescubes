#ifndef __CUBE__
  #define __CUBE__
  /*!
 * \file cube.hpp
 * \brief Implementation du module cube qui est un derive d'un EcoAgent
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
using namespace std;

 /*! \class Cube
 * \brief Classe derivee de la classe EcoAgent designant un Cube
 *
 */

class Cube : public EcoAgent
{
public:
    /*!
     * \brief Constructeur
     *
     * Constructeur de la classe Cube
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
	* \brief Initialisation de l'etat de l'agent
	*
	* Cette methode permet d'initialiser l'etat d'un agent en prenant en compte sa position courante et sa position finale.
	* Par exemple, si la position courante correspond a la position finale, cette methode initialisera l'Etat a "satisfait"
	*
	*/
	void initialiserEtat();
};

#endif