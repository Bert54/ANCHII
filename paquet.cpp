#include "paquet.hpp"

Paquet::Paquet(std::string nom) {
    this->nom = nom;
}

std::string Paquet::getNomPaquet() {
    return this->nom;
}
