/** Cette classe est le listener de l'écran des paquets. Celui-ci a donc pour rôle d'exécuter des actions quand
 ** l'utilisateur fait quelque chose sur son écran associé.
 **/

#include "ecranpaquetscontroles.hpp"
#include "anchii.hpp"

#include <QInputDialog>
#include <QEventLoop>
#include <QObject>
#include <ui_anchii.h>
#include <ui_mainscreen.h>

/**
 * @brief EcranPaquetsControles::EcranPaquetsControles Constructeur du controleur de l'écran des paquets
 * @param anchii Le modèle
 * @param buttonNewDeck BOuton que sera toujours présent
 */
EcranPaquetsControles::EcranPaquetsControles(Anchii* anchii, QPushButton *buttonNewDeck) {
    this->anchii = anchii;
    this->buttonNewDeck = buttonNewDeck;
    // Ajoute le bouton de création d'un paquet au layout de l'écran associé à ce controleur
    this->anchii->getMainScreenUi()->gridLayoutControls->addWidget(buttonNewDeck, 0, 0);
    // Configuration du bouton
    this->buttonNewDeck->setText("Nouveau");
    // Création du lien afin que le bouton crée un nouveau paquet
    connect(this->buttonNewDeck, &QPushButton::clicked, this, &EcranPaquetsControles::ajouterPaquet);
}

/**
 * @brief EcranPaquetsControles::ajouterPaquet Demande au modèle d'ajouter un paquet
 */
void EcranPaquetsControles::ajouterPaquet() {
    bool isOkPressed; // Sert à déterminer si l'utilisateur a appuyé sur le bouton 'ok' ou sur le bouton 'annuler' de la fenêtre de dialogue
    QString text;
    // Ici, la boucle oblige à l'utilisateur de saisir un texte non vide dans une fenêtre de saisie si il n'appuie pas sur le bouton 'annuler'.
    do {
        text = QInputDialog::getText(0, tr("Nouveau Paquet"), tr("Entrez le nom du nouveau paquet :"), QLineEdit::Normal, "", &isOkPressed);
    } while (strcmp(text.toUtf8().constData(), "") == 0 && isOkPressed);
    if (isOkPressed) {
        this->anchii->ajouterPaquet(text.toUtf8().constData());
        this->anchii->setScreen(1);
    }
}

/**
 * @brief EcranPaquetsControles::setScreenManageDeck Demande au modèle d'afficher l'écran de gestion de deck
 */
void EcranPaquetsControles::setScreenManageDeck() {
    this->anchii->setScreen(1);
}
