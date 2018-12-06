#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <iostream>
#include <vector>
#include "observer.hpp"


class Observable {
public:

    virtual ~Observable();
    void addObserver(Observer *obs);
    void updateObservers(int code);

protected:

    /**
     * @brief observers La liste des observeurs du modèle de l'application concerné
     */
    std::vector<Observer*> observers;

};

#endif // OBSERVABLE_HPP
