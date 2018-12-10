#ifndef CARTE_HPP
#define CARTE_HPP

#include <iostream>

class Carte {

public:
    Carte(std::string question, std::string reponse);
    void ajouterASupprimer();
    std::string getQuestion();
    std::string getReponse();
    bool getSuppression();

private:
    std::string question;
    std::string reponse;
    bool aSupprimer;
};

#endif // CARTE_HPP
