#ifndef CARTE_HPP
#define CARTE_HPP

#include <iostream>

#include "media.hpp"
#include "mediaimage.hpp"

class Carte {

public:
    Carte(std::string question, std::string reponse, std::string* mediaQuestion, std::string* mediaReponse);
    virtual ~Carte();
    std::string getQuestion();
    std::string getReponse();
    MediaImage* getMediaQuestion();
    MediaImage* getMediaReponse();
    std::string convertFileToLocal(std::string path);
    bool getSuppression();
    void ajouterASupprimer();

private:
    std::string question;
    std::string reponse;
    MediaImage *mediaQuestion;
    MediaImage *mediaReponse;
    bool aSupprimer;
};

#endif // CARTE_HPP
