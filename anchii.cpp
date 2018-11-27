/** Cette classe est le modèle de l'application. Elle contient en cons"quent toutes les données utiles.
 **/


#include "anchii.hpp"
#include "ui_anchii.h"
#include "ecranmenupaquet.hpp"

#include <ui_mainscreen.h>
#include <ui_deckscreen.h>
#include <QString>
#include <QLabel>
#include <QFrame>
#include <QPushButton>

/**
 * @brief Anchii::Anchii Constructeur du modèle ainsi que de l'IG
 * @param parent
 */
Anchii::Anchii(QWidget *parent) : QMainWindow(parent), ui(new Ui::Anchii) {
    ui->setupUi(this);
    // Ces 2 boutons sont des boutons qui seront constamment présents dans leur écrans respectifs
    QPushButton* newDeckButton = new QPushButton();
    QPushButton* newCardButton = new QPushButton();
    QPushButton* buttonReturn1 = new QPushButton();
    this->deckScreen = new DeckScreen(); // L'écran de gestion de deck
    this->mainScreen = new MainScreen(); // L'écran des decks
    this->ecranPaquetsListener = new EcranPaquetsControles(this, newDeckButton); // Listener de l'écran des paquets
    this->ecranGestionPaquetListener = new EcranGestionPaquetControles(this, newCardButton, buttonReturn1); // Listener de l'écran de gestion de paquet
    this->ecranMenuPaquetVue = new EcranMenuPaquet(this, this->ecranPaquetsListener); // La vue de l'écran des paquets
    this->screens = new QStackedWidget(this); // Ce QStackedWidget va servir à la gestion multi-écran de l'application
    this->screens->addWidget(this->mainScreen); // Ajout de l'écran des paquets
    this->screens->addWidget(this->deckScreen);
    setCentralWidget(this->screens);
    this->setScreen(0);
}

/**
 * @brief Anchii::~Anchii Destructeur de l'application
 */
Anchii::~Anchii()
{
    delete ecranPaquetsListener;
    delete ecranGestionPaquetListener;
    delete ui;
    delete deckScreen;
    delete mainScreen;
    delete screens;
}

/**
 * @brief Anchii::ajouterPaquet Ajoute un nouveau paquet
 * @param nom Le nom du nouveau paquet
 */
void Anchii::ajouterPaquet(std::string nom) {
    nom = this->verifNomPaquet(nom);
    Paquet paquet(nom);
    paquets.push_back(paquet);
    this->setPaquetActif(nom);
    this->updateObservers();
}

/**
 * @brief Anchii::setPaquetActif Change le paquet actif de l'application
 * @param nomPaquet Le nom du paquet qui doit être actif
 */
void Anchii::setPaquetActif(std::string nomPaquet) {
    this->nomPaquetActif = nomPaquet;
}

/**
 * @brief Anchii::getPaquetActif Récupère le paquet actif de l'application
 * @return Le nom du paquet actif
 */
std::string Anchii::getPaquetActif() {
    return this->nomPaquetActif;
}

/**
 * @brief Anchii::getPaquets Retourne la liste des paquets
 * @return Liste des paquets
 */
std::vector<Paquet> Anchii::getPaquets() {
    return this->paquets;
}

/**
 * @brief Anchii::verifNomPaquet Vérifie que le nom du paquet donné en paramètre n'est pas contenu dans la liste des paquets
 * @param nom Nom du paquet à vérifier
 * @return Nouveau nom
 */
std::string Anchii::verifNomPaquet(std::string nom) {
    for (Paquet p : this->paquets) {
        if (nom.compare(p.getNomPaquet()) == 0) {
            nom.append("_bis");
        }
    }
    return nom;
}
/**
 * @brief Anchii::getMenuDecksUi Retourne l'inferface graphique du menu de gestion du paquet actif
 * @return L'inferface graphique du menu de gestion du deck actif
 */
Ui::DeckScreen* Anchii::getMenuDecksUi() {
    return this->deckScreen->ui;
}
/**
 * @brief Anchii::getMainScreenUi Retourne l'inferface graphique du menu des paquets
 * @return
 */
Ui::MainScreen* Anchii::getMainScreenUi() {
    return this->mainScreen->ui;
}
/**
 * @brief Anchii::setScreen Change l'écran actif
 * @param s La valeur déterminant quel écran doit être actif
 */
void Anchii::setScreen(int s) {
    this->screens->setCurrentIndex(s);
}
