#ifndef __REGLE__
  #define __REGLE__
  /*!
  * \file regle.hpp
  * \brief Squelette d'une regle pour une plateforme d'eco-resolution
  * \author GDD
  * \author Pauline Requena
  * \author Arnaud Faure
  * \version 0.1
  * \date 04 avril 2009
  */
#include<iostream>
using namespace std;
  
  /*! \class Regle
  * \brief Cette classe abstraite est une squelette pour une regle
  *
  *  Cette classe abstraite est une squelette pour une regle qui sera ajoutee dans une PlateformeEcoResolution.
  * Une regle est une condition ou un ensemble de conditions qui doivent etre verifiee pour que la resolution puisse se faire.
  */
  class Regle{
    public:
    /*!
     * \brief Destructeur de la classe abstraite Regle
     *
     */
    virtual ~Regle();

      /*!
      * \brief Suite d'operations realisees pour initialiser la regle 
      *
      */
      virtual void initialiser()=0;
      
      /*!
      * \brief Verification de la regle 
      * \return true si la regle est verifiee, false sinon (ou bien une exception en fonction des cas)
      */
      virtual bool verifier()=0;
  };
  
#endif
