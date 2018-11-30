#ifndef ECRANAJOUTCARTECONTROLES_HPP
#define ECRANAJOUTCARTECONTROLES_HPP

#include <QObject>

class Anchii;

class EcranAjoutCarteControles : public QObject  {
    Q_OBJECT
public:
    EcranAjoutCarteControles(Anchii *anchii);
    void ajouterCarte();
    void returnToDeckScreen();

private:

    Anchii *anchii;
};

#endif // ECRANAJOUTCARTECONTROLES_HPP
