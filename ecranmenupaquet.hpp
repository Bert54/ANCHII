#ifndef ECRANMENUPAQUETVUE_HPP
#define ECRANMENUPAQUETVUE_HPP

#include <QGridLayout>

#include "observer.hpp"
#include "anchii.hpp"
#include "ecranpaquetscontroles.hpp"

class EcranMenuPaquet : public Observer {
public :
    explicit EcranMenuPaquet(Anchii *anchii, EcranPaquetsControles* ecranPaquetsListener);
    void update();
private :
    Anchii *anchii;
    EcranPaquetsControles *ecranPaquetsListener;
};

#endif // ECRANMENUPAQUETVUE_HPP
