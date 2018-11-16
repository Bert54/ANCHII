#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <list>
#include <algorithm>
#include <iterator>

#include "observateur.hpp"
#include "event.hpp"

template<typename Object>
class Observable{
public :
    void addObservateur(Observateur<Object>* obs){
        this->_listObservateur.push_back(obs);
    }

    void removeObservateur(Observateur<Object>* obs){
        ItListObs beginList = this->_listObservateur.begin();
        ItListObs endList = this->_listObservateur.end();

        ItListObs it  = std::find(beginList, endList, obs);
        if (it != endList)
            this->_listObservateur.erase(it);
    }
protected :
    virtual Event<Object>* getEvent() = 0;

    void notify(){
        ItListObs beginList = this->_listObservateur.begin();
        ConstItListObs endList = this->_listObservateur.end();

        for (ListObs it = beginList; it != endList; it++){  //ou ItListObs
            (*it)->refresh(this->getEvent()());
        }
    }
private :
    typedef Observateur<Object>* PrtObs;
    typedef std::list<PrtObs> ListObs;
    typedef typename ListObs::iterator ItListObs;
    typedef typename ListObs::const_iterator ConstItListObs;
    ListObs _listObservateur;
};

#endif // OBSERVABLE_H
