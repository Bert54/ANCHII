#include "carte.hpp"

/**
 * @brief Carte::Carte Constructeur d'une carte
 * @param question La question de la nouvelle carte
 * @param reponse La reponse de la nouvelle carte
 */
Carte::Carte(std::string question, std::string reponse) {
    this->question = question;
    this->reponse = reponse;
}

/**
 * @brief Paquet::getQuestion Retourne la question de cette carte
 * @return La question de cette carte
 */
std::string Carte::getQuestion() {
    return this->question;
}

/**
 * @brief Paquet::getQuestion Retourne la reponse de cette carte
 * @return La reponse de cette carte
 */
std::string Carte::getReponse() {
    return this->reponse;
}
