#include "ecranajoutcartecontroles.hpp"
#include "anchii.hpp"

#include <ui_cardscreen.h>

EcranAjoutCarteControles::EcranAjoutCarteControles(Anchii *anchii) {
    this->anchii = anchii;
    QPushButton *returnToDeckScreen = new QPushButton();
    QPushButton *addNewCard = new QPushButton();
    this->anchii->getMenuAddCardUi()->gridLayoutControls->addWidget(returnToDeckScreen, 0, 0);
    this->anchii->getMenuAddCardUi()->gridLayoutControls->addWidget(addNewCard, 0, 1);
    returnToDeckScreen->setText("Annuler");
    connect(returnToDeckScreen, &QPushButton::clicked, this, &EcranAjoutCarteControles::returnToDeckScreen);
    addNewCard->setText("Valider");
    connect(addNewCard, &QPushButton::clicked, this, &EcranAjoutCarteControles::ajouterCarte);
}

void EcranAjoutCarteControles::returnToDeckScreen() {
    this->anchii->getMenuAddCardUi()->textEditQuestion->setText("");
    this->anchii->getMenuAddCardUi()->textEditAnswer->setText("");
    this->anchii->setScreen(1);
}

void EcranAjoutCarteControles::ajouterCarte() {
    std::string question = this->anchii->getMenuAddCardUi()->textEditQuestion->toPlainText().toUtf8().constData();
    std::string answer = this->anchii->getMenuAddCardUi()->textEditAnswer->toPlainText().toUtf8().constData();
    this->anchii->ajouterCarte(question, answer);
    this->anchii->setScreen(1);
}
