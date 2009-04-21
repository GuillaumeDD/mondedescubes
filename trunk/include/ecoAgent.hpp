#ifndef __ECOAGENT__
  #define __ECOAGENT__
 /*!
 * \file ecoAgent.hpp
 * \brief Mise en place de la classe abstraite EcoAgent
 * \author GDD
 * \author Arnaud Faure
 * \author Pauline Requena
 * \version 0.1
 * \date 31 mars 2009
 *
 * Implementation de la classe abstraite EcoAgent qui regroupe les fonctionnalites communes a tout eco-agent
 *
  */
#include<iostream>
#include"ecoAgentID.hpp"
#include"etat.hpp"
using namespace std;

 /*!
 * \class EcoAgent
 * \brief Classe abstraite qui permet de creer un eco-agent
 *
 * Classe abstraite qui permet de creer un eco-agent. Tout eco-agent doit herite de cette classe.
 *
  */  

class EcoAgent {
	public:
	/*!
	 * \brief Obtention de l'Etat
	 *
	 * Methode qui permet d'obtenir l'attribut prive Etat
	 *
	 * \return l'Etat de l'objet EcoAgent
	  */
	Etat getEtat() const;
	
	 /*!
	 * \brief Obtention de l'EcoAgentID
	 *
	 * Methode qui permet d'obtenir l'attribut prive EcoAgentID
	 *
	 * \return l'EcoAgentID de l'objet EcoAgent
	  */
	EcoAgentID* getId() const;
	
	/*!
	 * \brief Changement de l'Etat
	 *
	 * Methode qui permet de modifier l'attribut prive Etat
	 *
	 *\param e : Etat que recevra l'EcoAgent
	 */
	void setEtat(const Etat e);
	
	/*!
	 * \brief Changement de l'EcoAgentID
	 *
	 * Methode qui permet de modifier l'attribut prive EcoAgentID
	 *
	 *\param id : id que recevra l'EcoAgent
	 */
	void setId(const EcoAgentID& id);
	
	
	/*!
	* \brief Changement de la position courante de l'agent
	*
	* Methode qui permet de changer la position courante de l'eco-agent
	*
	* \param pos : EcoAgentID de la nouvelle position
	*/
	void setPositionCourante(const EcoAgentID& pos);
	
	
	/*!
	* \brief Permet d'obtenir la position courante de l'eco-agent
	*
	* Methode qui permet d'obtenir l'EcoAgentID de l'eco-agent sur lequel est placé l'eco-agent
	*
	* \return EcoAgentID de l'EcoAgent avec lequel cet EcoAgent est en relation
	*
	*/
	EcoAgentID* getPositionCourante() const;
	
	/*!
	* \brief Changement de la position finale de l'agent
	*
	* Methode qui permet de changer la position finale de l'eco-agent, c'est a dire, l'identifiant
	* de l'eco-agent sur lequel l'eco-agent doit se trouver a la fin de la resolution
	*
	* \param pos : EcoAgentID de la nouvelle position
	*/
	void setPositionFinale(const EcoAgentID& pos);
	
	
	/*!
	* \brief Permet d'obtenir la position courante de l'eco-agent
	*
	* Methode qui permet d'obtenir l'EcoAgentID de l'eco-agent sur lequel est placé l'eco-agent
	*
	* \return EcoAgentID de l'EcoAgent avec lequel cet EcoAgent doit se trouver en relation a la fin de la resolution
	*/
	EcoAgentID* getPositionFinale() const;	
	
	/*!
	 * \brief Suite d'operations realisees par l'agent lorsqu'il cherche a fuir
	 *
	 */
	virtual void rechercherFuite()=0;
	
	/*!
	 * \brief Suite d'operations realisees par l'agent lorsqu'il cherche a se satisfaire
	 *
	 */
	virtual void rechercherSatisfaction()=0;
	
	/*!
	 * \brief Suite d'operations realisees lorsqu'un agent1 agresse un agent2
	 *
	 *\param a : EcoAgent a agresser
	 *
	 */
	virtual void agresser(EcoAgent& a)=0;
	
	/*!
	 * \brief Suite d'operations realisees par un agent agresse
	 *
	 */
	virtual void estAgresse()=0;
	
	/*!
	 * \brief Suite d'operations realisees par l'agent lorsqu'il est agresse
	 *
	 */
	virtual void faireFuite()=0;

	/*!
	 * \brief Suite d'operations realisees par l'agent lorsqu'il se satisfait
	 *
	 */
	virtual void faireSatisfaction()=0;

        /*!
	 * \brief Suite d'operations realisees par l'agent lorsqu'il agit
	 *
	 */
	virtual void agir()=0;

	/*!
	* \brief Cette methode permet d'afficher des informations sur un EcoAgent
	* 
	*/
	friend ostream & operator<< (ostream&, const EcoAgent&);

        private:
            EcoAgentID* id; /*!< Identifiant de l'eco-agent */
            Etat etat; /*!< Etat dans lequel se situe l'agent */
	    EcoAgentID* positionCourante; /*!< Eco-agent sur lequel est actuellement l'eco-agent */
	    EcoAgentID* positionFinale; /*!< Eco-agent sur lequel il doit finir a la fin de la resolution */
};


#endif

