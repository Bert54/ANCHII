#include "anchii.hpp"
//#include "ui_anchii.hpp"

//TODO : retirer ce commentaire pour le rendu
//Implémentation du patern observer/observable volé à https://www.supinfo.com/articles/single/941-design-pattern-observer-c

/*Anchii(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Anchii)
{
    ui->setupUi(this);
}*/

Anchii(QWidget *parent) {
    ui=parent;
}

~Anchii()
{
    delete ui;
}

std::string verifNomPaquet(std::string nom){
    return " ";
}

void ajouterPaquet(std::string nom){

}

void ajouterCarte(std::string question, std::string reponse, std::list<std::string> medias){

}

void supprimerPaquet(){

}

void supprimerCartes(std::list<std::string> questions){

}

void setPaquetActif(std::string nomPaquet){

}

std::string getPaquetActif(){
    return " ";
}

Event<std::string>* Anchii::getEvent(){

    return new Event<std::string>(new std::string(buffer.str()));
}
