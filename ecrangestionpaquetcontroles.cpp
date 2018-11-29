/** Cette classe est le listener de l'écran de gestion de paquet. Celui-ci a donc pour rôle d'exécuter des actions quand
 ** l'utilisateur fait quelque chose sur son écran associé.
 **/

#include "ecrangestionpaquetcontroles.hpp"
#include "anchii.hpp"

#include <QInputDialog>
#include <ui_anchii.h>
#include <ui_deckscreen.h>

/**
 * @brief EcranGestionPaquetControles::EcranGestionPaquetControles Constructeur du contrôleur de l'interface graphique DeckScreen
 * @param anchii Le modèle
 * @param buttonReturn Le bouton de retour vers le menu des decks
 */
EcranGestionPaquetControles::EcranGestionPaquetControles(Anchii *anchii, QPushButton *buttonNewCard, QPushButton *buttonReturn) {
    this->anchii = anchii;
    this->buttonReturn = buttonReturn;
    this->buttonNewCard = buttonNewCard;
    // Ajoute les bouton de retour et de création de paquet au menu des paquets au layout de l'écran associé à ce controleur
    this->anchii->getMenuDecksUi()->gridLayoutControls->addWidget(buttonReturn, 0, 1);
    this->anchii->getMenuDecksUi()->gridLayoutControls->addWidget(buttonNewCard, 0, 0);
    // Configuration des boutons
    this->buttonNewCard->setText("Nouvelle carte");
    this->buttonReturn->setText("Retour");
    // Création du lien afin que le bouton crée une nouvelle carte
    connect(this->buttonNewCard, &QPushButton::clicked, this, &EcranGestionPaquetControles::ajouterCarte);
    // Création du lien afin que le bouton nous fasse retourne au menu des paquets
    connect(this->buttonReturn, &QPushButton::clicked, this, &EcranGestionPaquetControles::returnToMainScreen);
}

/**
 * @brief EcranGestionPaquetControles::returnToMainScreen Demande au modèle d'afficher l'écran des paquets
 */
void EcranGestionPaquetControles::returnToMainScreen() {
    this->anchii->setScreen(0);
}

void EcranGestionPaquetControles::ajouterCarte() {
    bool isOkPressed; // Sert à déterminer si l'utilisateur a appuyé sur le bouton 'ok' ou sur le bouton 'annuler' de la fenêtre de dialogue
    QString question;
    QString reponse;
    // Ici, la boucle oblige à l'utilisateur de saisir un texte non vide dans une fenêtre de saisie si il n'appuie pas sur le bouton 'annuler'.
    do {
        question = QInputDialog::getText(0, tr("Nouvelle Carte"), tr("Entrez la question de la nouvelle carte :"), QLineEdit::Normal, "", &isOkPressed);
    } while (strcmp(question.toUtf8().constData(), "") == 0 && isOkPressed);
    if (isOkPressed) {
        do {
            reponse = QInputDialog::getText(0, tr("Nouvelle Carte"), tr("Entrez la reponse de la nouvelle carte :"), QLineEdit::Normal, "", &isOkPressed);
        } while (strcmp(reponse.toUtf8().constData(), "") == 0 && isOkPressed);
            if (isOkPressed) {
            this->anchii->getPaquetActif().ajouterCarte(question.toUtf8().constData(), reponse.toUtf8().constData());
            //TODO : ecran modifier carte : this->anchii->setScreen(2);
        }
    }
}
