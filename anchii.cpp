#include "anchii.h"
#include "ui_anchii.h"

//TODO : retirer ce commentaire pour le rendu
//Implémentation du patern observer/observable volé à https://www.supinfo.com/articles/single/941-design-pattern-observer-c

Anchii Anchii(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Anchii)
{
    ui->setupUi(this);
}

Anchii ~Anchii()
{
    delete ui;
}

std::string verifNomPaquet(std::string nom){
    return " ";
}

void ajouterPaquet(std::string nom){

}

void ajouterCarte(std::string question, std::string reponse, List<std::string> medias){

}

void supprimerPaquet(){

}

void supprimerCartes(List<std::string> question){

}

void setPaquetActif(std::string nomPaquet){

}

std::string getPaquetActif(){
    return " ";
}

Event<std::string>* Anchii::getEvent(){

    return new Event<std::string>(new std::string(buffer.str()));
}
