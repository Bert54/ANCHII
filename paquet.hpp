#ifndef PAQUET_HPP
#define PAQUET_HPP

#include <iostream>
#include <vector>
#include "carte.hpp"

class Paquet {
public:

    explicit Paquet(std::string nom);
    std::string getNomPaquet();
    void ajouterCarte(std::string question, std::string reponse);
    void supprimerCaret(int i);
    Carte getCarte(int i);

private:

    /**
     * @brief nom Le nom de ce paquet
     */
    std::string nom;
    std::vector<Carte> cartes;
};

#endif // PAQUET_H
