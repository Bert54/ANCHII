/** Cette classe est le modèle de l'application. Elle contient en conséquent toutes les données utiles.
 **/


#include "anchii.hpp"
#include "ui_anchii.h"
#include "ecranmenupaquet.hpp"

#include <ui_mainscreen.h>
#include <ui_deckscreen.h>
#include <QString>
#include <QLabel>
#include <QFrame>
#include <QPushButton>
#include <QDir>
#include <fstream>
#include <QDebug>

/**
 * @brief Anchii::Anchii Constructeur du modèle ainsi que de l'IG
 * @param parent
 */
Anchii::Anchii(QWidget *parent) : QMainWindow(parent), ui(new Ui::Anchii) {
    ui->setupUi(this);
    // Ces 2 boutons sont des boutons qui seront constamment présents dans leur écrans respectifs
    QPushButton* newDeckButton = new QPushButton();
    QPushButton* buttonReturn1 = new QPushButton();
    this->deckScreen = new DeckScreen(); // L'écran de gestion de deck
    this->mainScreen = new MainScreen(); // L'écran des decks
    this->cardScreen = new CardScreen();
    this->ecranPaquetsListener = new EcranPaquetsControles(this, newDeckButton); // Listener de l'écran des paquets
    this->ecranGestionPaquetListener = new EcranGestionPaquetControles(this, buttonReturn1); // Listener de l'écran de gestion de paquet
    this->ecranAjoutCarteListener = new EcranAjoutCarteControles(this);
    VueEcranMenuPaquet *vemp = new VueEcranMenuPaquet(this, this->ecranGestionPaquetListener);
    this->ecranMenuPaquetVue = new EcranMenuPaquet(this, this->ecranPaquetsListener); // La vue de l'écran des paquets
    this->screens = new QStackedWidget(this); // Ce QStackedWidget va servir à la gestion multi-écran de l'application
    this->screens->addWidget(this->mainScreen); // Ajout de l'écran principal
    this->screens->addWidget(this->deckScreen); // Ajout de l'écran des paquets
    this->screens->addWidget(this->cardScreen);
    this->toutCharger(this->getNomUtilisateurActif());
    setCentralWidget(this->screens);
    this->setScreen(0);
}

/**
 * @brief Anchii::~Anchii Destructeur de l'application On y détruit les listeners, les vues, les ui et leur conteneur et enfin, le modèle lui-même.
 */
Anchii::~Anchii()
{
    delete ecranPaquetsListener;
    delete ecranGestionPaquetListener;
    delete ecranAjoutCarteListener;
    delete ui;
    delete deckScreen;
    delete mainScreen;
    delete screens;
}

/**
 * @brief Anchii::ajouterPaquet Ajoute un nouveau paquet
 * @param nom Le nom du nouveau paquet
 */
void Anchii::ajouterPaquet(std::string nom) {
    nom = this->verifNomPaquet(nom);
    Paquet *paquet = new Paquet(nom);
    paquets.push_back(paquet);
    this->setPaquetActif(nom);
    this->updateObservers(1);
    this->updateObservers(2);
}

/**
 * @brief Anchii::supprimerPaquet Supprime le paquet actif
 */
void Anchii::supprimerPaquet() {
    int i = 0;
    int numPaquet;  // Numéro du paquet à supprimer
    Paquet *paq;
    for (Paquet *p : this->paquets) {
        if (!this->nomPaquetActif.compare(p->getNomPaquet())) {   // = 0 si les string sont égaux
            numPaquet = i;
            paq = p;
        }
        else {
            i++;        // Incrémentation pour récupérer le numéro du paquet à supprimer
        }
    }
    this->setPaquetActif("");
    std::string pName = this->paquets.at(numPaquet)->getNomPaquet();

    QFile file(QDir::currentPath() + "/" + QString::fromStdString(this->getNomUtilisateurActif()) + "/" + QString::fromStdString(pName) + ".anchii");
    if(file.exists());
    {
        file.remove();
    }
    this->paquets.erase(this->paquets.begin() + numPaquet); // numPaquet ne peut pas être NULL
    delete paq;
    this->updateObservers(1);
}

/**
 * @brief Anchii::ajouterCarte Ajoute une nouvelle carte au paquet actif
 * @param question La question de la nouvelle carte
 * @param reponse La réponse de la nouvelle carte
 */
void Anchii::ajouterCarte(std::string question, std::string reponse, std::string* mediaQuestion, std::string* mediaReponse) {
    this->getPaquetActif()->ajouterCarte(question, reponse, mediaQuestion, mediaReponse);
    this->updateObservers(2);
}

/**
 * @brief Anchii::ajouterCarteASupprimer Ajoute la carte selectionnee a la liste de cartes a supprimer
 * @param question La question de la carte a supprimer
 */
void Anchii::ajouterCarteASupprimer(std::string question) {
    this->getPaquetActif()->ajouterCarteASupprimer(question);
    this->updateObservers(2);

}

/**
 * @brief Anchii::supprimerCartes Supprime les cartes sélectionnees du paquet actif
 */
void Anchii::supprimerCartes() {
    this->getPaquetActif()->supprimerCartes();
    this->updateObservers(2);
}

/**
 * @brief Anchii::setPaquetActif Change le paquet actif de l'application
 * @param nomPaquet Le nom du paquet qui doit être actif
 */
void Anchii::setPaquetActif(std::string nomPaquet) {
    this->nomPaquetActif = nomPaquet;
}

/**
 * @brief Anchii::getNomPaquetActif Récupère le nom du paquet actif de l'application
 * @return Le nom du paquet actif
 */
std::string Anchii::getNomPaquetActif() {
    return this->nomPaquetActif;
}

/**
 * @brief Anchii::getNomPaquetActif Récupère le nom de l'utilisateur actif de l'application
 * Fonction temporaire en attendant qu'un véritable système d'utilisateur soit implémenté
 * @return Le nom de l'utilisateur actif
 */
std::string Anchii::getNomUtilisateurActif(){
    return "user";
}

/**
 * @brief Anchii::getPaquetActif Le paquet actif de l'application par rapport au nom du paquet actif
 * @return Le paquet actif
 */
Paquet* Anchii::getPaquetActif() {
    Paquet *pac;
    for (Paquet *p: this->paquets) {
        if (!getNomPaquetActif().compare(p->getNomPaquet())) {
            pac = p;
        }
    }
    return pac;
}

/**
 * @brief Anchii::getPaquets Retourne la liste des paquets
 * @return Liste des paquets
 */
std::vector<Paquet*> Anchii::getPaquets() {
    return this->paquets;
}

/**
 * @brief Anchii::verifNomPaquet Vérifie que le nom du paquet donné en paramètre n'est pas contenu dans la liste des paquets
 * @param nom Nom du paquet à vérifier
 * @return Nouveau nom
 */
std::string Anchii::verifNomPaquet(std::string nom) {
    for (Paquet *p : this->paquets) {
        if (nom.compare(p->getNomPaquet()) == 0) {
            nom.append("_bis");
        }
    }
    return nom;
}
/**
 * @brief Anchii::getMenuDecksUi Retourne l'inferface graphique du menu de gestion du paquet actif
 * @return L'inferface graphique du menu de gestion du deck actif
 */
Ui::DeckScreen* Anchii::getMenuDecksUi() {
    return this->deckScreen->ui;
}
/**
 * @brief Anchii::getMenuDecksUi Retourne l'inferface graphique du menu d'ajout d'une carte
 * @return L'inferface graphique du menu du menu d'ajout d'une carte
 */
Ui::CardScreen* Anchii::getMenuAddCardUi() {
    return this->cardScreen->ui;
}

/**
 * @brief Anchii::getMainScreenUi Retourne l'inferface graphique du menu des paquets
 * @return
 */
Ui::MainScreen* Anchii::getMainScreenUi() {
    return this->mainScreen->ui;
}
/**
 * @brief Anchii::setScreen Change l'écran actif
 * @param s La valeur déterminant quel écran doit être actif
 */
void Anchii::setScreen(int s) {
    this->screens->setCurrentIndex(s);
}

/**
 * @brief Anchii::sauvegarderPaquet Sauvegarde un paquet sous forme de fichier texte
 * @param s Le paquet à sauvegarder
 * @return Le chemin et nom du fichier.
 */
std::string Anchii::sauvegarderPaquet(Paquet *paquet){
    // On vérifie si le répertoire qui va contenir les images existe, si il n'existe pas, alors on le crée
    if (!QDir(QDir::currentPath() + "/" + QString::fromStdString(this->getNomUtilisateurActif())).exists()) {
        QDir().mkdir(QString::fromStdString(getNomUtilisateurActif()));
    }
    std::string nom = paquet->getNomPaquet()+".anchii";
    std::ofstream fichier(getNomUtilisateurActif() + "/" + nom, std::ios_base::out);
    for(Carte * carte : paquet->getCartes()){
        std::string question = carte->getQuestion();
        std::string mediaQuestion;
        if (carte->getMediaQuestion() != NULL) {
            mediaQuestion = carte->getMediaQuestion()->getMedia();
        }else{
            mediaQuestion = "";
        }
        std::string reponse = carte->getReponse();
        std::string mediaReponse;
        if (carte->getMediaReponse() != NULL) {
            mediaReponse = carte->getMediaQuestion()->getMedia();
        }else{
            mediaReponse = "";
        }
        fichier << question << mediaSeparator << mediaQuestion << qrSeparator << reponse << mediaSeparator << mediaReponse << cardSeparator;
    }
    fichier.close();
    return getNomUtilisateurActif() + std::string("/") + nom;
}

/**
 * @brief Anchii::toutCharger Charge tout les .anchii dans le répertoire de l'utilisateur
 * @param s Nom du répertoire utilisateur
 */
void Anchii::toutCharger(std::string userName){
    // On vérifie si le répertoire qui va contenir les images existe, si il n'existe pas, alors on le crée
    if (!QDir(QDir::currentPath() + "/" + QString::fromStdString(userName)).exists()) {
        QDir().mkdir(QString::fromStdString(userName));
    }
    QDir directory(QString::fromStdString(userName));
    QStringList files = directory.entryList(QStringList() << "*.anchii",QDir::Files);
    foreach(QString filename, files) {
        this->chargerPaquet(QDir::currentPath().toUtf8().constData() + std::string("/") + userName + std::string("/") + filename.toUtf8().constData());
    }
}

/**
 * @brief Anchii::chargerPaquet Importe un paquet depuis un fichier .anchii, si aucun paquet, en crée un nouveau
 * @param s Chemin du paquet à charger
 */
void Anchii::chargerPaquet(std::string path){

    //Trouve le fichier et récupére le nom du paquet
    std::string nomPaquet = path.substr(path.find_last_of("/\\") + 1);
    std::string::size_type p(nomPaquet.find_last_of('.'));
    std::string::size_type q;
    nomPaquet = nomPaquet.substr(0, p);
    this->ajouterPaquet(nomPaquet);
    //Si pas d'extension quand même chercher un .anchii
    if(p==-1){path = path + ".anchii";}

    //Lire le fichier
    std::ifstream fichier;
    fichier.open(path, std::ios_base::in);
    std::string content;
    std::string temp;
    while(fichier >> temp){content = content + "\n" + temp;}
    fichier.close();

    //Enlever le premier retour à la ligne si content n'estp as vide
    if(content != ""){content = content.substr(1, content.size());}

    //Recuperation des données
    std::string question;
    std::string mediaQuestion;
    std::string reponse;
    std::string mediaReponse;
    while((p = content.find(cardSeparator)) != -1){
        //Question
        if((q = content.find(mediaSeparator)) != -1){
            question = content.substr(0, q);
            content = content.substr(q+mediaSeparator.size(), content.size());
        }else{break;
        }
        //Media Question
        if((q = content.find(qrSeparator)) != -1){
            mediaQuestion = content.substr(0, q);
            content = content.substr(q+qrSeparator.size(), content.size());
        }else{break;}

        //Reponse
        if((q = content.find(mediaSeparator)) != -1){
            reponse = content.substr(0, q);
            content = content.substr(q+mediaSeparator.size(), content.size());
        }else{break;}

        //Media Reponse
        if((q = content.find(cardSeparator)) != -1){
            mediaReponse = content.substr(0, q);
            content = content.substr(q+cardSeparator.size(), content.size());
        }else{break;}

        this->ajouterCarte(question, reponse, &mediaQuestion, &mediaReponse);
    }
}
