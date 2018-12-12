/** Cette classe est le listener de l'écran de gestion de paquet. Celui-ci a donc pour rôle d'exécuter des actions quand
 ** l'utilisateur fait quelque chose sur son écran associé.
 **/

#include "ecrangestionpaquetcontroles.hpp"
#include "anchii.hpp"

#include <ui_anchii.h>
#include <ui_deckscreen.h>
#include <ui_mainscreen.h>
#include <QMessageBox>

/**
 * @brief EcranGestionPaquetControles::EcranGestionPaquetControles Constructeur du contrôleur de l'interface graphique DeckScreen
 * @param anchii Le modèle
 * @param buttonReturn Le bouton de retour vers le menu des decks
 */
EcranGestionPaquetControles::EcranGestionPaquetControles(Anchii *anchii, QPushButton *buttonReturn) {
    QPushButton* buttonAddCard = new QPushButton();
    QPushButton* buttonSauvegarder = new QPushButton();
    QPushButton* buttonDeleteCards = new QPushButton();
    QPushButton* buttonDeleteDeck = new QPushButton();
    this->anchii = anchii;
    this->buttonReturn = buttonReturn;
    // Ajoute le bouton de retour au menu des paquets au layout de l'écran associé à ce controleur
    this->anchii->getMenuDecksUi()->gridLayoutControls->addWidget(buttonReturn, 1, 0);
    this->anchii->getMenuDecksUi()->gridLayoutControls->addWidget(buttonAddCard, 0, 0);
    // Configuration du bouton
    this->buttonReturn->setText("Retour");
    // Création du lien afin que le bouton nous fasse retourne au menu des paquets
    connect(this->buttonReturn, &QPushButton::clicked, this, &EcranGestionPaquetControles::returnToMainScreen);
    buttonAddCard->setText("Ajouter Nouvelle Carte");
    connect(buttonAddCard, &QPushButton::clicked, this, &EcranGestionPaquetControles::setAddCardMode);
    // Création du bouton de suppression de cartes
    this->anchii->getMenuDecksUi()->gridLayoutControls->addWidget(buttonDeleteCards, 0, 1);
    buttonDeleteCards->setText("Supprimer des cartes");
    connect(buttonDeleteCards, &QPushButton::clicked, this, &EcranGestionPaquetControles::supprimerCartes);
    // Création du bouton de suppression du paquet
    buttonDeleteDeck = new QPushButton();
    this->anchii->getMenuDecksUi()->gridLayoutControls->addWidget(buttonDeleteDeck, 1, 1);
    buttonDeleteDeck->setText("Supprimer le paquet");
    connect(buttonDeleteDeck, &QPushButton::clicked, this, &EcranGestionPaquetControles::supprimerPaquet);
    //Sauvegarde du deck
    this->anchii->getMenuDecksUi()->gridLayoutControls->addWidget(buttonSauvegarder, 1, 2);
    buttonSauvegarder->setText("Sauvegarder le paquet");
    connect(buttonSauvegarder, &QPushButton::clicked, this, &EcranGestionPaquetControles::sauvegarderPaquet);
}

/**
 * @brief EcranGestionPaquetControles::setAddCardMode Change l'application en mode ajout de carte en demandant au modèle d'afficher l'écran d'ajout de carte
 */
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

/**
 * @brief EcranGestionPaquetControles::ajouterCartesASupprimer Ajoute une carte a la liste des cartes a supprimer
 * @param question La question de la carte a supprimer
 */
void EcranGestionPaquetControles::ajouterCarteASupprimer(QString question) {
    if(this->supprCartes == 1) {    // On ajoute la carte seulement si on a déjà cliqué sur le bouton de suppression 1 fois
        std::string q = question.toStdString();
        this->anchii->ajouterCarteASupprimer((q));
    }
}

/** TODO Finir la fonction, elle ne supprime rien pour le moment. ET ELLE N EST PAS AU BON ENDROITVDSGOSHGISUHGJdk
 * @brief EcranGestionPaquetControles::supprimerCartes Supprime les cartes sélectionnees
 */
void EcranGestionPaquetControles::supprimerCartes() {
     // Si on a pas encore cliqué sur le bouton, on rend les cartes cliquables
    if(this->supprCartes == 0) {
        this->supprCartes = 1;          // On prévient que l'on a cliqué
    }
    // Si on a déjà cliqué sur le bouton une fois, cette fois on supprime les cartes
    else if(this->supprCartes == 1) {
        this->supprCartes = 0;          // On réinitialise le clic
        this->anchii->supprimerCartes();
    }
}

/**
 * @brief EcranGestionPaquetControles::sauvegarderPaquet Sauvegarde un paquet dans un fichier local
 */
void EcranGestionPaquetControles::sauvegarderPaquet(){
    std::string msg = this->anchii->sauvegarderPaquet(this->anchii->getPaquetActif());
    QMessageBox::information(0, tr("Sauvegarde"), tr(("Paquet sauvegardé en tant que : " + QString::fromStdString(msg)).toStdString().c_str()));

}
