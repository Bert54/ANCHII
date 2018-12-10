/** Cette classe représente une carte d'un paquet
 **/

#include "carte.hpp"


/**
 * @brief Carte::Carte Constructeur d'une carte
 * @param question La question d'une carte
 * @param reponse La réponse d'une carte
 */
Carte::Carte(std::string question, std::string reponse) {
    this->question = question;
    this->reponse = reponse;
    this->aSupprimer = false;   // Par défaut, la carte ne doit pas etre supprimée
}

/**
 * @brief Carte::ajouterASupprimer Change le statut de la carte par rapport a sa suppression
 */
void Carte::ajouterASupprimer() {
    if(this->aSupprimer) {     // On change le statut de suppression de la carte
        this->aSupprimer = false;
    }
    else {
        this->aSupprimer = true;
    }
}

/**
 * @brief Carte::getQuestion Retourne la question de cette carte
 * @return La question de cette carte
 */
std::string Carte::getQuestion() {
    return this->question;
}

/**
 * @brief Carte::getQuestion Retourne la reponse de cette carte
 * @return La reponse de cette carte
 */
std::string Carte::getReponse() {
    return this->reponse;
}

/**
 * @brief Carte::getSuppression Retourne le statut de la suppression de la carte
 * @return true si la carte va etre supprimer, false sinon
 */
bool Carte::getSuppression() {
    return this->aSupprimer;
}
