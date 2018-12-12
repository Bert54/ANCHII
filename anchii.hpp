#ifndef ANCHII_HPP
#define ANCHII_HPP

#include <QMainWindow>
#include <QStackedWidget>
#include <paquet.hpp>

#include "ecranajoutcartecontroles.hpp"
#include "ecrangestionpaquetcontroles.hpp"
#include "ecranpaquetscontroles.hpp"
#include "vueecranmenupaquet.hpp"

#include "observable.hpp"
#include "deckscreen.hpp"
#include "mainscreen.hpp"
#include "cardscreen.hpp"

namespace Ui {
class Anchii;
}

static const std::string qrSeparator = "_~~_";
static const std::string cardSeparator = "__##__";
static const std::string mediaSeparator = "__--__";

class EcranMenuPaquet;

/**
 * @brief The Anchii class Modèle de l'application. Puisque c'est le modèle, il hérite de Observable.
 */
class Anchii : public QMainWindow, public Observable
{
    Q_OBJECT

public:
    explicit Anchii(QWidget *parent = nullptr);
    ~Anchii();
    void ajouterPaquet(std::string nom);
    void ajouterCarte(std::string question, std::string reponse, std::string* mediaQuestion, std::string* mediaReponse);
    void ajouterCarteASupprimer(std::string question);
    void supprimerCartes();
    std::string getNomPaquetActif();
    std::string getNomUtilisateurActif();
    Paquet* getPaquetActif();
    std::string verifNomPaquet(std::string nom);
    void setPaquetActif(std::string nomPaquet);
    std::vector<Paquet*> getPaquets();
    Ui::DeckScreen* getMenuDecksUi();
    Ui::MainScreen* getMainScreenUi();
    Ui::CardScreen* getMenuAddCardUi();
    void setScreen(int s);
    void supprimerPaquet();
    std::string sauvegarderPaquet(Paquet *paquet);
    void toutCharger(std::string userName);
    void chargerPaquet(std::string path);

private:
    /**
     * @brief ui L'écran principal qui va afficher
     */
    Ui::Anchii *ui;
    /**
     * @brief nomPaquetActif Nom du paquet actif
     */
    std::string nomPaquetActif;
    /**
     * @brief paquets La liste des paquets
     */
    std::vector<Paquet*> paquets;

    /**
     * @brief screens Container servant à switcher l'écran actif
     */
    QStackedWidget *screens;

    EcranPaquetsControles *ecranPaquetsListener;
    EcranGestionPaquetControles *ecranGestionPaquetListener;
    EcranAjoutCarteControles *ecranAjoutCarteListener;

    EcranMenuPaquet *ecranMenuPaquetVue;

    /**
     * @brief deckScreen La classe comportant l'écran de gestion de paquet
     */
    DeckScreen *deckScreen;
    /**
     * @brief mainScreen La classe comportant l'écran des paquets
     */
    MainScreen *mainScreen;

    CardScreen *cardScreen;
};

#endif // ANCHII_HPP
