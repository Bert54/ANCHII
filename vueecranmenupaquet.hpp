#ifndef VUEECRANMENUPAQUET_HPP
#define VUEECRANMENUPAQUET_HPP

#include "observer.hpp"
#include "anchii.hpp"
#include "ecrangestionpaquetcontroles.hpp"

class VueEcranMenuPaquet : public Observer {
public:
    explicit VueEcranMenuPaquet(Anchii *anchii, EcranGestionPaquetControles* ecranGestionPaquetListener);
    virtual ~VueEcranMenuPaquet() {}
    void update();
private:
    Anchii *anchii;
    EcranGestionPaquetControles *ecranGestionPaquetsListener;
};

#endif // VUEECRANMENUPAQUET_HPP
