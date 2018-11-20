#include "observable.hpp"

void Observable::addObserver(Observer *obs) {
    this->observers.push_back(obs);
}

void Observable::updateObservers() {
    for (Observer* obs : this->observers) {
        obs->update();
    }
}
