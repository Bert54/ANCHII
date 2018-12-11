#ifndef PAQUET_HPP
#define PAQUET_HPP

#include <iostream>
#include <vector>
#include <algorithm>    // std::sort
#include "carte.hpp"

class Paquet {
public:

    explicit Paquet(std::string nom);
    virtual ~Paquet();
    std::string getNomPaquet();
    void ajouterCarte(std::string question, std::string reponse, std::string* mediaQuestion, std::string* mediaReponse);
    void ajouterCarteASupprimer(std::string question);
    void supprimerCartes();
    void initCartesASupprimer();
    int getNumeroCarte(std::string question);
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
    /**
     * @brief cartesASupprimer La liste des cartes à supprimer
     */
    std::vector<int> cartesASupprimer;

};

#endif // PAQUET_H
