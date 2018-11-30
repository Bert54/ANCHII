/** Cette classe est héritée par le modèle de l'application. Elle permet une application direct du Design Pattern "Observable/Observer".
 ** Cette classe contient en outre les vues du modèle de l'application.
 **/

#include "observable.hpp"

/**
 * @brief Observable::~Observable Destructeur des vues de l'application
 */
Observable::~Observable() {
    for (Observer* obs : this->observers) {
        delete obs;
    }
}

/**
 * @brief Observable::addObserver Ajoute une vue qui va observer le modèle
 * @param obs La nouvelle vue
 */
void Observable::addObserver(Observer *obs) {
    this->observers.push_back(obs);
}

/**
 * @brief Observable::updateObservers Met à jour les vues
 */
void Observable::updateObservers() {
    for (Observer* obs : this->observers) {
        obs->update();
    }
}
