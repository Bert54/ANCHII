#include "ecranpaquetscontroles.hpp"
#include "anchii.hpp"

#include <QInputDialog>
#include <QEventLoop>
#include <QObject>
#include <QDir>
#include <QTextStream>
#include <ui_anchii.h>

/**
 * @brief EcranPaquetsControles::EcranPaquetsControles
 * @param anchii
 * @param buttonNewDeck
 */
EcranPaquetsControles::EcranPaquetsControles(Anchii* anchii, QPushButton *buttonNewDeck) {
    this->anchii = anchii;
    this->buttonNewDeck = buttonNewDeck;
    // Configuration du bouton
    this->buttonNewDeck->setText("Nouveau");
    // Création du lien afin que le bouton crée un nouveau paquet
    connect(this->buttonNewDeck, &QPushButton::clicked, this, &EcranPaquetsControles::ajouterPaquet);
}

void EcranPaquetsControles::ajouterPaquet() {
    bool isOkPressed;
    QString text;
    do {
        text = QInputDialog::getText(0, tr("Nouveau Paquet"), tr("Entrez le nom du nouveau paquet :"), QLineEdit::Normal, "", &isOkPressed);
    } while (strcmp(text.toUtf8().constData(), "") == 0 && isOkPressed);
    if (isOkPressed) {
        this->anchii->ajouterPaquet(text.toUtf8().constData());
        this->anchii->setScreen(1);
    }
}

void EcranPaquetsControles::setScreenManageDeck() {
    this->anchii->setScreen(1);
}
