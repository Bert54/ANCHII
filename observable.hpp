#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <iostream>
#include <vector>
#include "observer.hpp"


class Observable {
public:

    void addObserver(Observer *obs);
    void updateObservers();

protected:

    std::vector<Observer*> observers;

};

#endif // OBSERVABLE_HPP
