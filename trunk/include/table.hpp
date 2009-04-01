
#ifndef __TABLE__
#define	__TABLE__

/*!
 * \file table.hpp
 * \brief Implementation du module table qui est un dérivé d'un EcoAgent
 * \author GDD
 * \author Arnaud Faure
 * \author Pauline Requena
 * \version 0.1
 * \date 1er avril 2009
 *
 * Implementation de la classe Table qui est une classe derivee de la classe EcoAgent.
 *
 */

using namespace std;

 /*! \class Table
 * \brief Classe dérivee de la classe EcoAgent designant le Support sur lequel vont être poses les cubes
 *
 */

class Table 
{
private:
    
public:
    /*!
     * \brief Constructeur
     *
     * Constructeur de la classe Table
     *
     *\param id : identifiant unique que l'agent se verra attribuer
     *
     */
    Table(EcoAgentID id);

    /*!
     * \brief Destructeur
     *
     * Destructeur de la classe Table
     *
     */
     ~Table();
        
public:
        /*!
	 * \brief Suite d'operations realisees par la table lorsqu'elle cherche a fuir
	 *
	 *
	 */
	virtual void rechercherFuite();
	
	/*!
	 * \brief Suite d'operations realisees par la table lorsqu'elle cherche a se satisfaire
	 *
	 *
	 */
	virtual void rechercherSatisfaction();
	
	/*!
	 * \brief Suite d'operations realisees lorsque la table agresse un autre eco-agent
	 *
	 *
	 *\param a : EcoAgent a agresser
         *
	 */
	
	virtual void agresser(EcoAgent a);
	
	/*!
	 * \brief Suite d'operations realisees par la table lorsqu'elle est agressee
	 *
	 *
	 */
	virtual void estAgresse();
	
	/*!
	 * \brief Suite d'operations realisees par la fuite lorsqu'elle fuit
	 *
	 *
	 */
	virtual void faireFuite();

	/*!
	 * \brief Suite d'operations realisees par la table lorsqu'elle se satisfait
	 *
	 *
	 */
	void faireSatisfaction();

    
};
 


#endif	

