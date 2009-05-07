#ifndef __RELIESATABLE__
#define __RELIESATABLE__
/*!
 * \file reliesATable.hpp
 * \brief Cette regle verifie que tous les cubes sont relies a la table a l'initialisation de la resolution ainsi que dans l'etat final de la resolution.
 * \author GDD
 * \author Pauline Requena
 * \author Arnaud Faure
 * \version 0.1
 * \date 04 avril 2009
 */

#include "plateformeMondeDesCubes.hpp"
#include "regle.hpp"
#include "cube.hpp"
#include "Exceptions.hpp"
#include<iostream>
#include <map>


using namespace std;
  
/*! \class reliesATable
 * \brief Cette classe contient les fonctions testant si les cubes sont lies a la table
 *
 * Cette regle verifie que tous les cubes sont relies a la table a l'initialisation de la resolution ainsi que dans l'etat final de la resolution.
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
   * \return true si la regle est verifiee, une exception sinon
   * \throw ExceptionCubeNonRelie : lancee lorsqu'au moins un cube n'est pas relie a la table dans l'etat initial de la resolution
   * \throw ExceptionCubeSeraNonRelie : lancee lorsqu'au moins un cube ne sera pas relie a la table dans l'etat final de la resolution
   */
  bool verifier();

  /*!
   * \brief Verification d'un element de la regle generale: le cube est-il lie a la table
   * \return true si le cas est verifiee, une exception sinon
   * \throw ExceptionCubeNonRelie : lancee lorsqu'au moins un cube n'est pas relie a la table dans l'etat initial de la resolution
   */
  bool estRelieATable(EcoAgent &c);

  /*!
   * \brief Verification d'un element de la regle generale: le cube sera-t-il lie a la table
   * \return true si le cas est verifiee, une exception sinon
   * \throw ExceptionCubeSeraNonRelie : lancee lorsqu'au moins un cube ne sera pas relie a la table dans l'etat final de la resolution
   */

  bool seraRelieATable(EcoAgent &c);
};
  
#endif
