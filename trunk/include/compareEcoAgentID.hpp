#ifndef __COMPAREECOAGENTID__
#define __COMPAREECOAGENTID__
#include"ecoAgentID.hpp"
  /*!
  * \file compareEcoAgentID.hpp
  * \brief Comparaison d'EcoAgentID
  * \author GDD
  * \author Pauline Requena
  * \author Arnaud Faure
  * \version 0.1
  * \date 18 avril 2009
  */
  
  /*!
  * \class compareEcoAgentID
  * \brief Structure contenant la redefinition de l'operateur de comparaison d'EcoAgentID
  * Structure contenant la redefinition de l'operateur de comparaison d'EcoAgentID pour le transformer en cle unique d'une map
  */
  struct compareEcoAgentID{
    bool operator() (const EcoAgentID& id1,const EcoAgentID& id2) const
    {
     return id1.getId() < id2.getId();
    }
  };
#endif
