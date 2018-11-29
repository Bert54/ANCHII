/** Vue de l'application qui s'occupe de mettre à jour l'écran des paquets quand son modèle est modifié.
 **/

#include "ecranmenupaquet.hpp"
#include "paquet.hpp"
#include "anchii.hpp"
#include "observer.hpp"
#include <ui_anchii.h>
#include <ui_mainscreen.h>

#include <QLabel>

/**
 * @brief EcranMenuPaquet::EcranMenuPaquet Constructeur de la vue de l'écran des paquets
 * @param anchii Le modème
 * @param ecranPaquetsListener Son controleur
 */
EcranMenuPaquet::EcranMenuPaquet(Anchii *anchii, EcranPaquetsControles* ecranPaquetsListener) : Observer () {
    this->anchii = anchii;
    this->ecranPaquetsListener = ecranPaquetsListener;
    this->anchii->addObserver(this);
}

void EcranMenuPaquet::update() {
    //Xaxis et Yaxis permettent de position les boutons sur le GridLayout de l'écran des paquets
    int Xaxis = 0;
    int Yaxis = 0;
    QPushButton *button;
    // Ici, on génère les boutons de l'écran des paquets, un par paquet.
    // Ces boutons permettent de rediriger l'utilisateur vers l'écran de gestion de paquet, en gérant le
    // paquet sur lequel l'utilisateur a appuyé.
    for (Paquet p : this->anchii->getPaquets()) {
        button = new QPushButton(QString::fromStdString(p.getNomPaquet()));
        button->setStyleSheet("border: 1px solid red; padding-top: 20px; padding-bottom: 20px;");
        button->connect(button, &QPushButton::clicked, this->ecranPaquetsListener, &EcranPaquetsControles::setScreenManageDeck);
        anchii->getMainScreenUi()->gridLayoutDecks->addWidget(button, Yaxis, Xaxis);
        Xaxis++;
        if (Xaxis >= 6) {
            Yaxis++;
            Xaxis = 0;
        }
    }
}
