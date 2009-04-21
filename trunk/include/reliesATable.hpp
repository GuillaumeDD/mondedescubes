#ifndef __RELIESATABLE__
  #define __RELIESATABLE__
  /*!
  * \file reliesATable.hpp
  * \brief verification de la regle : est-ce que tous les cubes sont et seront relies directement ou indirectement a la table?
  * \author GDD
  * \author Pauline Requena
  * \author Arnaud Faure
  * \version 0.1
  * \date 04 avril 2009
  */

#include "plateformeMondeDesCubes.hpp"
#include "regle.hpp"
#include<iostream>
#include <map>
#include "cube.hpp"

using namespace std;
  
  /*! \class reliesATable
  * \brief Cette classe contient les fonctions testant si les cubes sont lies a la table
  *
  *
  */
class ReliesATable : public Regle{
    public:
      /*!
      * \brief Suite d'operations realisees pour initialiser la regle 
      *
      */
      void initialiser();
      
      /*!
      * \brief Verification de la regle generale : pour chaque cube, est-il et sera-t-il lie a la table
      * \return true si la regle est verifiee, false sinon
      */
      bool verifier();
	
	  /*!
      * \brief Verification d'un élément de la regle generale: le cube est-il lie a la table
      * \return true si le cas est verifiee, false sinon
      */
      bool estRelieATable(EcoAgent &c);

	  /*!
      * \brief Verification d'un élément de la regle generale: le cube sera-t-il lie a la table
      * \return true si le cas est verifiee, false sinon
      */

      bool seraRelieATable(EcoAgent &c);
  };
  
#endif
