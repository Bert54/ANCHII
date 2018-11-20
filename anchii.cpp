#include "anchii.hpp"
#include "ui_anchii.h"
#include "ecranmenupaquet.hpp"

#include <ui_mainscreen.h>
#include <ui_deckscreen.h>
#include <QTextStream>
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
    QPushButton* newDeckButton = new QPushButton();
    QPushButton* buttonReturn1 = new QPushButton();
    this->deckScreen = new DeckScreen();
    this->mainScreen = new MainScreen();
    this->ecranPaquetsListener = new EcranPaquetsControles(this, newDeckButton);
    this->ecranGestionPaquetListener = new EcranGestionPaquetControles(this, buttonReturn1);
    this->ecranMenuPaquetVue = new EcranMenuPaquet(this, this->ecranPaquetsListener);
    this->mainScreen->ui->gridLayoutControls->addWidget(newDeckButton, 0, 0);
    this->deckScreen->ui->gridLayoutControls->addWidget(buttonReturn1, 0, 0);
    this->screens = new QStackedWidget(this);
    this->screens->addWidget(this->mainScreen);
    this->screens->addWidget(this->deckScreen);
    setCentralWidget(this->screens);
    this->setScreen(0);
}

/**
 * @brief Anchii::~Anchii Destructeur de l'aaplication
 */
Anchii::~Anchii()
{
    delete ui;
    delete deckScreen;
    //delete ecranMenuPaquetVue;
    delete ecranPaquetsListener;
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
