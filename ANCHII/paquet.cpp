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
