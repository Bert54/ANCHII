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

class Anchii : public QMainWindow, public Observable
{
    Q_OBJECT

public:
    explicit Anchii(QWidget *parent = nullptr);
    ~Anchii();
    void ajouterPaquet(std::string nom);
    std::string getPaquetActif();
    std::string verifNomPaquet(std::string nom);
    void setPaquetActif(std::string nomPaquet);
    std::vector<Paquet> getPaquets();
    Ui::DeckScreen* getMenuDecksUi();
    Ui::MainScreen* getMainScreenUi();
    void setScreen(int s);

private:
    Ui::Anchii *ui;
    std::string nomPaquetActif; // Nom du paquet actif
    std::vector<Paquet> paquets; // La liste des paquets

    QStackedWidget *screens;

    EcranPaquetsControles *ecranPaquetsListener;
    EcranGestionPaquetControles *ecranGestionPaquetListener;

    EcranMenuPaquet *ecranMenuPaquetVue;

    DeckScreen *deckScreen;
    MainScreen *mainScreen;
};

#endif // ANCHII_HPP
