#ifndef ECRANGESTIONPAQUETCONTROLES_HPP
#define ECRANGESTIONPAQUETCONTROLES_HPP

#include <QPushButton>
#include <QObject>

class Anchii;

/**
 * @brief EcranGestionPaquetControles class Hérite de QObject pour qu'il puisse connecter ses boutons à ses propres méthodes
 */
class EcranGestionPaquetControles : public QObject {
    Q_OBJECT
public:
    explicit EcranGestionPaquetControles(Anchii *anchii, QPushButton *buttonReturn);
    virtual ~EcranGestionPaquetControles() {}
    void setAddCardMode();
    void returnToMainScreen();
    void supprimerPaquet();
    void sauvegarder();

private:
    /**
     * @brief anchii Modèle de l'application
     */
    Anchii *anchii;
    QPushButton *buttonReturn;
    QPushButton *buttonDeleteDeck;
};

#endif // ECRANGESTIONPAQUETCONTROLES_HPP
