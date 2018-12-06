/** Vue de l'application qui s'occupe de mettre à jour l'écran de gestion du paquet actif
 ** quand son modèle est modifié ou quand on bascule sur cette vue.
 **/


#include "vueecranmenupaquet.hpp"
#include "carte.hpp"
#include "paquet.hpp"
#include "anchii.hpp"
#include "observer.hpp"
#include "mediaimage.hpp"

#include <ui_anchii.h>
#include <ui_mainscreen.h>
#include <ui_deckscreen.h>
#include <QPixmap>
#include <QIcon>

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
        QPixmap *img;
        MediaImage *mediaImg;
        // Avant toute chose, on supprime tous les boutons des cartes déjà présents dans l'écran
        for (int i = this->anchii->getMenuDecksUi()->gridLayoutCards->count()-1 ; i >= 0 ; --i) {
            this->anchii->getMenuDecksUi()->gridLayoutCards->itemAt(i)->widget()->deleteLater();
            this->anchii->getMenuDecksUi()->gridLayoutCards->takeAt(i);
        }
        // Ici, on génère les boutons de l'écran de gestion de paquet , un par carte.
        // Pour le moment, ces boutons ne font rien.
        for (Carte *c : this->anchii->getPaquetActif()->getCartes()) {
            button = new QPushButton(QString::fromStdString(c->getQuestion()));
            mediaImg = c->getMediaQuestion();
            // Cette partie s'occupe de charger l'image associé à la question si il y en a une
            if (mediaImg != NULL) {
                img = new QPixmap(QString::fromStdString(c->getMediaQuestion()->getMedia()));
                button->setIcon(QIcon(*img));
                button->setIconSize(QSize(50, 50));
            }
            button->setStyleSheet("border: 1px solid blue; padding-top: 20px; padding-bottom: 20px;");
            anchii->getMenuDecksUi()->gridLayoutCards->addWidget(button, Yaxis, Xaxis);
            Xaxis++;
            if (Xaxis >= 6) {
                Yaxis++;
                Xaxis = 0;
            }
        }
    }
}
