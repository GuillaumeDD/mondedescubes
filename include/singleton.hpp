#ifndef __SINGLETON__
  #define __SINGLETON__
  /*!
  * \file singleton.cpp
  * \brief Implementation du design pattern singleton
  * \author GDD
  * \version 0.1
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
      Singleton();
      ~Singleton();
    public:
      static T* getInstance();
      static void kill();
    private:
      static T* _instance;
  };
  /*
  * L'insertion du code dans le template est obligatoire.
  * (on ne separe pas la declaration du template de son implementation)
  * L'alternative serait d'utiliser le mot-cle export
  * controverse et non implemente dans certain compilateur.
  */
  template<typename T> T* Singleton<T>::_instance = NULL;
  
  template<typename T> Singleton<T>::Singleton(){
    cout << "Création du singleton" << endl;
  }
  
  template<typename T> Singleton<T>::~Singleton(){
    cout << "Destuction du singleton" << endl;
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
    }
  }
#endif