#ifndef CARTE_H
#define CARTE_H

#include <iostream>

class Carte
{
public:
    Carte();

    explicit Carte(std::string question, std::string reponse);
    std::string getQuestion();
    std::string getReponse();

private :
    std::string question;
    std::string reponse;
};

#endif // CARTE_H
