#include "ecranmenupaquet.hpp"
#include "paquet.hpp"
#include "anchii.hpp"
#include "observer.hpp"
#include <ui_anchii.h>
#include <ui_mainscreen.h>

#include <QLabel>

EcranMenuPaquet::EcranMenuPaquet(Anchii *anchii, EcranPaquetsControles* ecranPaquetsListener) : Observer () {
    this->anchii = anchii;
    this->ecranPaquetsListener = ecranPaquetsListener;
    this->anchii->addObserver(this);
}

void EcranMenuPaquet::update() {
    int Xaxis = 0;
    int Yaxis = 0;
    QPushButton *button;
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
