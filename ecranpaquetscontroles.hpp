#ifndef ECRANPAQUETSCONTROLES_HPP
#define ECRANPAQUETSCONTROLES_HPP

#include <QPushButton>
#include <QObject>

class Anchii;

class EcranPaquetsControles : public QObject{
    Q_OBJECT
public:
    explicit EcranPaquetsControles(Anchii *anchii, QPushButton *buttonNewDec);
    virtual ~EcranPaquetsControles() {}
    void ajouterPaquet();
    void setScreenManageDeck();

private:
    Anchii *anchii;
    QPushButton *buttonNewDeck;
};

#endif // ECRANPAQUETSCONTROLES_HPP
