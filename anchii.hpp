#ifndef ANCHII_HPP
#define ANCHII_HPP

#include <QMainWindow>
#include <QStackedWidget>
#include <paquet.hpp>

#include "ecrangestionpaquetcontroles.hpp"
#include "ecranpaquetscontroles.hpp"
#include "observable.hpp"
#include "deckscreen.hpp"
#include "mainscreen.hpp"

namespace Ui {
class Anchii;
}

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
    Paquet getPaquetActif();
    std::string getNomPaquetActif();
    std::string verifNomPaquet(std::string nom);
    void setPaquetActif(std::string nomPaquet);
    std::vector<Paquet> getPaquets();
    Ui::DeckScreen* getMenuDecksUi();
    Ui::MainScreen* getMainScreenUi();
    void setScreen(int s);

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
    std::vector<Paquet> paquets;

    /**
     * @brief screens Container servant à switcher l'écran actif
     */
    QStackedWidget *screens;

    EcranPaquetsControles *ecranPaquetsListener;
    EcranGestionPaquetControles *ecranGestionPaquetListener;

    EcranMenuPaquet *ecranMenuPaquetVue;

    /**
     * @brief deckScreen La classe comportant l'écran de gestion de paquet
     */
    DeckScreen *deckScreen;
    /**
     * @brief mainScreen La classe comportant l'écran des paquets
     */
    MainScreen *mainScreen;
};

#endif // ANCHII_HPP
