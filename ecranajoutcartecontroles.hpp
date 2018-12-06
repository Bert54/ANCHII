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
    void chargerMediaQuestion();
    void chargerMediaReponse();
    QString chargerMedia();

private:

    Anchii *anchii;
};

#endif // ECRANAJOUTCARTECONTROLES_HPP
