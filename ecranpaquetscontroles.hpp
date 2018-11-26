#ifndef ECRANPAQUETSCONTROLES_HPP
#define ECRANPAQUETSCONTROLES_HPP

#include <QPushButton>
#include <QObject>

class Anchii;

/**
 * @brief The EcranPaquetsControles class Hérite de QObject pour qu'il puisse connecter ses boutons à des méthodes appartenant à lui-même
 */
class EcranPaquetsControles : public QObject{
    Q_OBJECT
public:
    explicit EcranPaquetsControles(Anchii *anchii, QPushButton *buttonNewDec);
    virtual ~EcranPaquetsControles() {}
    void ajouterPaquet();
    void setScreenManageDeck();

private:
    /**
     * @brief anchii Le modèle de l'application
     */
    Anchii *anchii;
    /**
     * @brief buttonNewDeck Le bouton de création d"un nouveau paquet
     */
    QPushButton *buttonNewDeck;
};

#endif // ECRANPAQUETSCONTROLES_HPP
