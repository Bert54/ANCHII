/** Cette classe représente un paquet de l'application, qui contient des cartes.
 **/

#include "paquet.hpp"

/**
 * @brief Paquet::Paquet Constructeur d'un paquet
 * @param nom Le nom du nouveau paquet
 */
Paquet::Paquet(std::string nom) {
    this->nom = nom;
}

/**
 * @brief Paquet::~Paquet Destructeur d'un paquet. ON détruit toutes les cartes, une par une.
 */
Paquet::~Paquet() {
    for (Carte *c: this->cartes) {
        delete c;
    }
}

/**
 * @brief Paquet::getNomPaquet Retourne le nom de ce paquet
 * @return Le nom de ce paquet
 */
std::string Paquet::getNomPaquet() {
    return this->nom;
}

/**
 * @brief Paquet::ajouterCarte Ajout d'une nouvelle carte dans le paquet actif
 * @param question La question de la carte
 * @param reponse La réponse de la carte
 */
void Paquet::ajouterCarte(std::string question, std::string reponse, std::string* mediaQuestion, std::string* mediaReponse) {
    Carte *carte = new Carte(question, reponse, mediaQuestion, mediaReponse);
    cartes.push_back(carte);

}

/**
 * @brief Paquet::getCartes Récuèpre les cartes du paquet actif
 * @return La liste des cartes du paquet actif
 */
std::vector<Carte*> Paquet::getCartes() {
    return this->cartes;
}
