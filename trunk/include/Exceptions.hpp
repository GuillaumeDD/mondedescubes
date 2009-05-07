#ifndef __EXCEPTIONS__
#define __EXCEPTIONS__
  /*!
  * \file Exceptions.hpp
  * \brief Liste des Exceptions possibles
  * \author GDD
  * \author Pauline Requena
  * \author Arnaud Faure
  * \version 0.1
  * \date 24 avril 2009
  */

/*!
 * \class ExceptionEcoAgentDejaEnregistre
 * \brief Exception lancee dans le cadre de l'ajout d'un EcoAgent deja enregistre dans une PlateformeEcoResolution.
 *
 */
class ExceptionEcoAgentDejaEnregistre{
};

/*!
 * \class ExceptionUnCubeEstSurcharge
 * \brief Exception lancee dans le cadre de la verification de la regle "est-ce que les cubes sont surcharges".
 *
 */


class ExceptionUnCubeEstSurcharge{
};

/*!
 * \class ExceptionUnCubeSeraSurcharge
 * \brief Exception lancee dans le cadre de la verification de la regle "est-ce que les cubes seront surcharges".
 *
 */

class ExceptionUnCubeSeraSurcharge{
};	

/*!
 * \class ExceptionIlExisteUneBoucle
 * \brief Exception lancee dans le cadre de la verification de la regle "est-ce que les cubes sont relies a la table".
 *
 */

class ExceptionIlExisteUneBoucle{
};	
/*!
 * \class ExceptionCubeNonRelie
 * \brief Exception lancee dans le cadre de la verification de la regle "est-ce que les cubes sont relies a la table".
 *
 */

class ExceptionCubeNonRelie{
};	
/*!
 * \class ExceptionIlExisteraUneBoucle
 * \brief Exception lancee dans le cadre de la verification de la regle "est-ce que les cubes seront relies a la table".
 *
 */

class ExceptionIlExisteraUneBoucle{
};	
/*!
 * \class ExceptionCubeSeraNonRelie
 * \brief Exception lancee dans le cadre de la verification de la regle "est-ce que les cubes seront relies a la table".
 *
 */

class ExceptionCubeSeraNonRelie{
};	
#endif
