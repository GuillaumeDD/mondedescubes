#ifndef __AUCUNESURCHARGE__
#define __AUCUNESURCHARGE__
/*!
 * \file aucuneSurcharge.hpp
 * \brief verification de la regle : est-ce que chaque cube porte au plus un cube?
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
#include <map>
#include<iostream>
using namespace std;
  
/*! \class AucuneSurcharge
 * \brief Cette classe contient les fonctions testant si les cubes ne portent pas plus de un cube
 *
 *
 */

class AucuneSurcharge : public Regle{
public:

   /*!
   * \brief Suite d'operations realisees pour initialiser la regle 
   *
   */
  void initialiser();
      
  /*!
   * \brief Verification de la regle generale : pour l'ensemble des cubes, sont-ils et seront-ils surcharges?
   * \return true si la regle est verifiee, false sinon
   */
  bool verifier();

  /*!
   * \brief Verification d'un element de la regle generale: les cubes sont-ils surcharges?
   * \return true si le cas est verifiee, false sinon
   */
  bool pasSurcharges();

  /*!
   * \brief Verification d'un element de la regle generale: les cubes seront-ils surcharges?
   * \return true si le cas est verifiee, false sinon
   */

  bool serontPasSurcharges();
};
  
#endif
