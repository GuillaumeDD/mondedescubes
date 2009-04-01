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
 * Implementation de la classe abstraite EcoAgent dont heritent les classes Cube et Table.
 *
  */

using namespace std;

 /*!
 * \class EcoAgent
 * \brief Classe abstraite appelee par les classes Cube et Table
 *
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
	EcoAgentID getId() const;
	
	/*!
	 * \brief Changement de l'Etat
	 *
	 * Methode qui permet de modifier l'attribut prive Etat
	 *
	 *\param e : Etat que recevra l'EcoAgent
	 */
	void setEtat(Etat e);
	
	/*!
	 * \brief Changement de l'EcoAgentID
	 *
	 * Methode qui permet de modifier l'attribut prive EcoAgentID
	 *
	 *\param id : id que recevra l'EcoAgent
	 */
	void setId(EcoAgentID id);
	
	/*!
	 * \brief Suite d'operations realisees par l'agent lorsqu'il cherche a fuir
	 *
	 *
	 */
	virtual void rechercherFuite();
	
	/*!
	 * \brief Suite d'operations realisees par l'agent lorsqu'il cherche a se satisfaire
	 *
	 *
	 */
	virtual void rechercherSatisfaction();
	
		/*!
	 * \brief Suite d'operations realisees lorsqu'un agent1 agresse un agent2
	 *
	 *
	 *\param a : EcoAgent a agresser

		 */
	
	virtual void agresser(EcoAgent a);
	
	/*!
	 * \brief Suite d'operations realisees par un agent agresse
	 *
	 *
	 */
	virtual void estAgresse();
	
	/*!
	 * \brief Suite d'operations realisees par l'agent lorsqu'il se met a fuir
	 *
	 *
	 */
	virtual void faireFuite();

	/*!
	 * \brief Suite d'operations realisees par l'agent lorsqu'il se satisfait
	 *
	 *
	 */
	virtual void faireSatisfaction();

        /*!
	 * \brief Suite d'operations realisees par l'agent lorsqu'il agit
	 *
	 *
	 */
	virtual void agir();

        private:

            EcoAgentID id;
            Etat etat;
}

#endif

