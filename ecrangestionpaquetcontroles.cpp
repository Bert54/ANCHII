#include "ecrangestionpaquetcontroles.hpp"
#include "anchii.hpp"

#include <ui_anchii.h>

/**
 * @brief EcranGestionPaquetControles::EcranGestionPaquetControles Constructeur du contrôleur de l'interface graphique DeckScreen
 * @param anchii Le modèle
 * @param buttonReturn Le bouton de retour vers le menu des decks
 */
EcranGestionPaquetControles::EcranGestionPaquetControles(Anchii *anchii, QPushButton *buttonReturn) {
    this->anchii = anchii;
    this->buttonReturn = buttonReturn;
    // Configuration du bouton
    this->buttonReturn->setText("Retour");
    // Création du lien afin que le bouton nous fasse retourne au menu des paquets
    connect(this->buttonReturn, &QPushButton::clicked, this, &EcranGestionPaquetControles::returnToMainScreen);
}

void EcranGestionPaquetControles::returnToMainScreen() {
    this->anchii->setScreen(0);
}
