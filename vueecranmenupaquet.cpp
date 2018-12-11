/** Vue de l'application qui s'occupe de mettre à jour l'écran de gestion du paquet actif
 ** quand son modèle est modifié ou quand on bascule sur cette vue.
 **/


#include "vueecranmenupaquet.hpp"
#include "carte.hpp"
#include "paquet.hpp"
#include "anchii.hpp"
#include "observer.hpp"

#include <ui_anchii.h>
#include <ui_mainscreen.h>
#include <ui_deckscreen.h>

/**
 * @brief VueEcranMenuPaquet::VueEcranMenuPaquet Constructeur de la vue de l'écran de gestion du paquet actif
 * @param anchii Le modèle de l'application
 * @param ecranGestionPaquetListener Le listener de la vue
 */
VueEcranMenuPaquet::VueEcranMenuPaquet(Anchii *anchii, EcranGestionPaquetControles* ecranGestionPaquetListener) : Observer () {
    this->anchii = anchii;
    this->ecranGestionPaquetsListener = ecranGestionPaquetListener;
    this->anchii->addObserver(this);
}

void VueEcranMenuPaquet::update(int code) {
    if (code == 2) {
        //Xaxis et Yaxis permettent de position les boutons sur le GridLayout des cartes
        //de l'écran de gestion du paquet
        int Xaxis = 0;
        int Yaxis = 0;
        QPushButton *button;
        // Avant toute chose, on supprime tous les boutons des cartes déjà présents dans l'écran
        for (int i = this->anchii->getMenuDecksUi()->gridLayoutCards->count()-1 ; i >= 0 ; --i) {
            this->anchii->getMenuDecksUi()->gridLayoutCards->itemAt(i)->widget()->deleteLater();
            this->anchii->getMenuDecksUi()->gridLayoutCards->takeAt(i);
        }
        // Ici, on génère les boutons de l'écran de gestion de paquet , un par carte.
        // Pour le moment, ces boutons ne font rien.
        for (Carte *c : this->anchii->getPaquetActif()->getCartes()) {
            button = new QPushButton(QString::fromStdString(c->getQuestion()));
            if(c->getSuppression()) {
                button->setStyleSheet("border: 1px solid green; padding-top: 20px; padding-bottom: 20px;");
            }
            else {
                button->setStyleSheet("border: 1px solid blue; padding-top: 20px; padding-bottom: 20px;");
            }
            // On relie d'abord tous les boutons au mapper
            button->connect(button, SIGNAL(clicked()), &mapper, SLOT(map()));
            // L'argument qui sera envoyé quand on appuiera sur le bouton
            mapper.setMapping(button, button->text());
            anchii->getMenuDecksUi()->gridLayoutCards->addWidget(button, Yaxis, Xaxis);
            Xaxis++;
            if (Xaxis >= 6) {
                Yaxis++;
                Xaxis = 0;
            }
        }
        // On connecte le mapper au bon slot
        button->connect(&mapper, SIGNAL(mapped(QString)), this->ecranGestionPaquetsListener, SLOT(ajouterCarteASupprimer(QString)));
    }
}
