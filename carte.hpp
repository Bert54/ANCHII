#ifndef CARTE_HPP
#define CARTE_HPP

#include <iostream>

class Carte {

public:
    Carte(std::string question, std::string reponse);
    std::string getQuestion();
    std::string getReponse();

private:
    std::string question;
    std::string reponse;
};

#endif // CARTE_HPP
