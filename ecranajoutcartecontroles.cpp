/** Cette classe est le listener de l'écran d'e gestion de paquet'ajout d'une carte. Celui-ci a donc pour rôle d'exécuter des actions quand
 ** l'utilisateur fait quelque chose sur son écran associé.
 **/


#include "ecranajoutcartecontroles.hpp"
#include "anchii.hpp"

#include <QFileDialog>
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
    connect(this->anchii->getMenuAddCardUi()->mediaquestion, &QPushButton::clicked, this, &EcranAjoutCarteControles::chargerMediaQuestion);
    connect(this->anchii->getMenuAddCardUi()->mediareponse, &QPushButton::clicked, this, &EcranAjoutCarteControles::chargerMediaReponse);
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
    std::string question = this->anchii->getMenuAddCardUi()->textEditQuestion->toPlainText().toUtf8().constData(); // La question de la carte
    std::string answer = this->anchii->getMenuAddCardUi()->textEditAnswer->toPlainText().toUtf8().constData(); // La réponse de la carte
    QString mediaQuestion = this->anchii->getMenuAddCardUi()->labelMediaQuestion->text(); // Récupère le chemin de l'image pour la question
    QString mediaReponse = this->anchii->getMenuAddCardUi()->labelMediaReponse->text(); // Récupère le chemin de l'image pour la réponse
    std::string mediaQuestionStd = mediaQuestion.toUtf8().constData();
    std::string mediaReponseStd = mediaReponse.toUtf8().constData();
    bool compareQuestion;
    bool compareReponse;
    // On vérifie si l'utilisateur a sélectionné une image pour la question
    if (QString::compare(mediaQuestion, "", Qt::CaseInsensitive) != 0) {
        compareQuestion = true;
    }
    else {
        compareQuestion = false;
    }
    // On vérifie si l'utilisateur a sélectionné une image pour la réponse
    if (QString::compare(mediaReponse, "", Qt::CaseInsensitive) != 0) {
        compareReponse = true;
    }
    else {
        compareReponse = false;
    }
    // Pas d'images pour la question et réponse
    if (!compareQuestion && !compareReponse) {
        this->anchii->ajouterCarte(question, answer, NULL, NULL);
    }
    // Pas d'images pour la question mais une image pour la réponse
    else if (!compareQuestion) {
        this->anchii->ajouterCarte(question, answer, NULL, &mediaReponseStd);
    }
    // Une image pour la question mais pas d'images pour la réponse
    else if (!compareReponse) {
        this->anchii->ajouterCarte(question, answer, &mediaQuestionStd, NULL);
    }
    // Une image pour la question et une autre pour la réponse
    else {
        this->anchii->ajouterCarte(question, answer, &mediaQuestionStd, &mediaReponseStd);
    }
    this->anchii->getMenuAddCardUi()->textEditQuestion->setText("");
    this->anchii->getMenuAddCardUi()->textEditAnswer->setText("");
    this->anchii->getMenuAddCardUi()->labelMediaQuestion->setText("");
    this->anchii->getMenuAddCardUi()->labelMediaReponse->setText("");
    this->anchii->setScreen(1);
}

/**
 * @brief EcranAjoutCarteControles::chargerMediaQuestion Permet de chercher une image pour la question
 */
void EcranAjoutCarteControles::chargerMediaQuestion() {
    QString temp = this->chargerMedia();
    if (temp != NULL) {
        this->anchii->getMenuAddCardUi()->labelMediaQuestion->setText(temp);
    }
}

/**
 * @brief EcranAjoutCarteControles::chargerMediaReponse Permet de chercher une image pour la réponse
 */
void EcranAjoutCarteControles::chargerMediaReponse() {
    QString temp = this->chargerMedia();
    if (temp != NULL) {
        this->anchii->getMenuAddCardUi()->labelMediaReponse->setText(temp);
    }
}

/**
 * @brief EcranAjoutCarteControles::chargerMedia Permet de chercher une image
 * @return Le chemin externe de l'image cherchée
 */
QString EcranAjoutCarteControles::chargerMedia() {
    QString fileName = QFileDialog::getOpenFileName(NULL,
            tr("Ouvrir nouveau média"), "",
            tr("Images (*.png *.jpg *.jpeg *.gif *.bmp)"));
    return fileName;
}
