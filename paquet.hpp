#ifndef PAQUET_HPP
#define PAQUET_HPP

#include <iostream>
#include <vector>
#include "carte.hpp"

class Paquet {
public:

    explicit Paquet(std::string nom);
    virtual ~Paquet();
    std::string getNomPaquet();
    void ajouterCarte(std::string question, std::string reponse, std::string* mediaQuestion, std::string* mediaReponse);
    std::vector<Carte*> getCartes();

private:

    /**
     * @brief nom Le nom de ce paquet
     */
    std::string nom;
    /**
     * @brief cartes La liste des cartes de ce paquet
     */
    std::vector<Carte*> cartes;

};

#endif // PAQUET_H
