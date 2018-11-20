#ifndef ECRANGESTIONPAQUETCONTROLES_HPP
#define ECRANGESTIONPAQUETCONTROLES_HPP

#include <QPushButton>
#include <QObject>

class Anchii;

class EcranGestionPaquetControles : public QObject {
    Q_OBJECT
public:
    explicit EcranGestionPaquetControles(Anchii *anchii, QPushButton *buttonReturn);
    virtual ~EcranGestionPaquetControles() {}
    void returnToMainScreen();

private:
    Anchii *anchii;
    QPushButton *buttonReturn;
};

#endif // ECRANGESTIONPAQUETCONTROLES_HPP
