#ifndef ECRANMENUPAQUETVUE_HPP
#define ECRANMENUPAQUETVUE_HPP

#include <QGridLayout>
#include <QSignalMapper>

#include "observer.hpp"
#include "anchii.hpp"
#include "ecranpaquetscontroles.hpp"

class EcranMenuPaquet : public Observer {
public :
    explicit EcranMenuPaquet(Anchii *anchii, EcranPaquetsControles* ecranPaquetsListener);
    virtual ~EcranMenuPaquet() {}
    void update(int code);
private :
    /**
     * @brief anchii Le modèle de l'application
     */
    Anchii *anchii;
    /**
     * @brief ecranPaquetsListener Le listener de cette vue
     */
    EcranPaquetsControles *ecranPaquetsListener;
    /**
     * @brief mapper Permet au controleur d'appeler une méthode avec un paramètre
     */
    QSignalMapper mapper;
};

#endif // ECRANMENUPAQUETVUE_HPP
