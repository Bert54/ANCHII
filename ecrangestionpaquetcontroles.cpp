/** Cette classe est le listener de l'écran de gestion de paquet. Celui-ci a donc pour rôle d'exécuter des actions quand
 ** l'utilisateur fait quelque chose sur son écran associé.
 **/

#include "ecrangestionpaquetcontroles.hpp"
#include "anchii.hpp"

#include <ui_anchii.h>
#include <ui_deckscreen.h>
#include <ui_mainscreen.h>

/**
 * @brief EcranGestionPaquetControles::EcranGestionPaquetControles Constructeur du contrôleur de l'interface graphique DeckScreen
 * @param anchii Le modèle
 * @param buttonReturn Le bouton de retour vers le menu des decks
 */
EcranGestionPaquetControles::EcranGestionPaquetControles(Anchii *anchii, QPushButton *buttonReturn) {
    QPushButton* buttonAddCard = new QPushButton();
    QPushButton* buttonDeleteDeck = new QPushButton();
    this->anchii = anchii;
    this->buttonReturn = buttonReturn;
    // Ajoute le bouton de retour au menu des paquets au layout de l'écran associé à ce controleur
    this->anchii->getMenuDecksUi()->gridLayoutControls->addWidget(buttonReturn, 0, 0);
    this->anchii->getMenuDecksUi()->gridLayoutControls->addWidget(buttonAddCard, 0, 1);
    // Configuration du bouton
    this->buttonReturn->setText("Retour");
    // Création du lien afin que le bouton nous fasse retourne au menu des paquets
    connect(this->buttonReturn, &QPushButton::clicked, this, &EcranGestionPaquetControles::returnToMainScreen);
    buttonAddCard->setText("Ajouter Nouvelle Carte");
    connect(buttonAddCard, &QPushButton::clicked, this, &EcranGestionPaquetControles::setAddCardMode);
    // Création du bouton de suppression du paquet
    buttonDeleteDeck = new QPushButton();
    this->anchii->getMenuDecksUi()->gridLayoutControls->addWidget(buttonDeleteDeck, 1, 1);
    buttonDeleteDeck->setText("Supprimer le paquet");
    connect(buttonDeleteDeck, &QPushButton::clicked, this, &EcranGestionPaquetControles::supprimerPaquet);
}

void EcranGestionPaquetControles::setAddCardMode() {
    this->anchii->setScreen(2);
}

/**
 * @brief EcranGestionPaquetControles::supprimerPaquet Supprime le paquet actif
 */
void EcranGestionPaquetControles::supprimerPaquet() {
    this->anchii->supprimerPaquet();
    this->returnToMainScreen();
}

/**
 * @brief EcranGestionPaquetControles::returnToMainScreen Demande au modèle d'afficher l'écran des paquets
 */
void EcranGestionPaquetControles::returnToMainScreen() {
    this->anchii->setPaquetActif("");
    this->anchii->setScreen(0);
}
