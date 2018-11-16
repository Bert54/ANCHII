#ifndef ANCHII_H
#define ANCHII_H

#include <QMainWindow>
#include <string>
#include <ctime>
#include <sstream>

#include "observable.h"

namespace Ui {

class Anchii : public QMainWindow, Observable<std::string>
{
    Q_OBJECT
public:
    explicit Anchii(QWidget *parent = 0);
    Anchii Anchii();
    Anchii ~Anchii();
    std::string verifNomPaquet(std::string nom);
    void ajouterPaquet(std::string nom);
    void ajouterCarte(std::string question, String reponse, List<String> medias);
    void supprimerPaquet(); //A peut etre besoin d'un parametre pour savoir quel paquet supprimer
    void: supprimerCartes(List<std::string> question);
    void setPaquetActif(std::string nomPaquet);
    std::string getPaquetActif();

protected :
    Event<std::string>* getEvent();

private:
    Ui::Anchii *ui;
    std::string nomPaquetActif;
};

#endif // ANCHII_H
