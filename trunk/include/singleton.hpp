#ifndef __SINGLETON__
  #define __SINGLETON__
  /*!
  * \file singleton.hpp
  * \brief Implementation du design pattern singleton
  * \author GDD
  * \author Arnaud Faure
  * \author Pauline Requena
  * \version 0.1
  * \date 29 mars 2009
  *
  * Implementation du design pattern singleton pour rendre une classe instanciable une unique fois.
  *
  */

  #include<iostream>
  using namespace std;
  
  /*!
  * \class Singleton
  * \brief Template de classe permettant de rendre une classe instanciable une seule fois 
  *
  * Une classe qui herite de ce template devient un singleton. Elle sera alors instanciable une unique fois.
  *
  */  
  template<typename T> class Singleton{
    protected:
      /*!
       * \brief Constructeur
       *
       * Constructeur de la classe Singleton.
       *
       */
      Singleton();
      
     /*!
      * \brief Destructeur
      *
      * Destructeur de la classe Singleton.
      *
      */
      ~Singleton();
    public:
     /*!
      * \brief Obtention de l'instance
      *
      * Methode qui permet d'obtenir l'unique instance en fonctionnement
      *
      * \return Un pointeur sur l'instance de type T
      */
      static T* getInstance();
      
     /*!
      * \brief Destruction de l'instance
      *
      * Methode qui permet d'obtenir de détruire l'instance
      *
      */      
      static void kill();
    private:
      static T* _instance; /*!< Instance unique*/
  };
  /*
  * L'insertion du code dans le template est obligatoire.
  * (on ne separe pas la declaration du template de son implementation)
  * L'alternative serait d'utiliser le mot-cle export
  * controverse et non implemente dans certain compilateur.
  */
  template<typename T> T* Singleton<T>::_instance = NULL;
  
  template<typename T> Singleton<T>::Singleton(){
    //cout << "Création du singleton" << endl;
  }
  
  template<typename T> Singleton<T>::~Singleton(){
    //cout << "Destuction du singleton" << endl;
  }
  
  template<typename T> T* Singleton<T>::getInstance(){
    if(_instance==NULL){
      _instance=new T;
    }
    return _instance;
  }
  
  template<typename T> void Singleton<T>::kill(){
    if(_instance != NULL){
      delete _instance;
		_instance = NULL;
    }
  }
#endif
