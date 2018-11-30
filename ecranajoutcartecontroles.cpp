/** Cette classe est le listener de l'écran d'e gestion de paquet'ajout d'une carte. Celui-ci a donc pour rôle d'exécuter des actions quand
 ** l'utilisateur fait quelque chose sur son écran associé.
 **/


#include "ecranajoutcartecontroles.hpp"
#include "anchii.hpp"

#include <ui_cardscreen.h>

/**
 * @brief EcranAjoutCarteControles::EcranAjoutCarteControles Constructeur ddu controlleur de l'écran d'ajout d'une carte
 * @param anchii Le modèle de l'application
 */
EcranAjoutCarteControles::EcranAjoutCarteControles(Anchii *anchii) {
    this->anchii = anchii;
    QPushButton *returnToDeckScreen = new QPushButton(); // Bouton qui permet de retourner à l'écran de gestion
    QPushButton *addNewCard = new QPushButton(); // Boutton qui confirme l'ajout d'une nouvelle carte
    this->anchii->getMenuAddCardUi()->gridLayoutControls->addWidget(returnToDeckScreen, 0, 0);
    this->anchii->getMenuAddCardUi()->gridLayoutControls->addWidget(addNewCard, 0, 1);
    returnToDeckScreen->setText("Annuler");
    connect(returnToDeckScreen, &QPushButton::clicked, this, &EcranAjoutCarteControles::returnToDeckScreen);
    addNewCard->setText("Valider");
    connect(addNewCard, &QPushButton::clicked, this, &EcranAjoutCarteControles::ajouterCarte);
}

/**
 * @brief EcranAjoutCarteControles::returnToDeckScreen Permet de retourner à l'écran de gestion du paquet actif
 */
void EcranAjoutCarteControles::returnToDeckScreen() {
    this->anchii->getMenuAddCardUi()->textEditQuestion->setText("");
    this->anchii->getMenuAddCardUi()->textEditAnswer->setText("");
    this->anchii->setScreen(1);
}

/**
 * @brief EcranAjoutCarteControles::ajouterCarte Permet d'ajouter une nouvelle carte au paquet actif
 */
void EcranAjoutCarteControles::ajouterCarte() {
    std::string question = this->anchii->getMenuAddCardUi()->textEditQuestion->toPlainText().toUtf8().constData();
    std::string answer = this->anchii->getMenuAddCardUi()->textEditAnswer->toPlainText().toUtf8().constData();
    this->anchii->ajouterCarte(question, answer);
    this->anchii->getMenuAddCardUi()->textEditQuestion->setText("");
    this->anchii->getMenuAddCardUi()->textEditAnswer->setText("");
    this->anchii->setScreen(1);
}
