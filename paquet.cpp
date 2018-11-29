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
 * @brief Paquet::getNomPaquet Retourne le nom de ce paquet
 * @return Le nom de ce paquet
 */
std::string Paquet::getNomPaquet() {
    return this->nom;
}

void Paquet::ajouterCarte(std::string question, std::string reponse){
    Carte carte(question, reponse);
    cartes.push_back(carte);
}

void Paquet::supprimerCaret(int i){
    this->cartes.erase(cartes.begin() + i);
}

Carte Paquet::getCarte(int i){
    return this->cartes.at(i);
}
