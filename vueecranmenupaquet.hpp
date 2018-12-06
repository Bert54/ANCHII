#ifndef VUEECRANMENUPAQUET_HPP
#define VUEECRANMENUPAQUET_HPP

#include "observer.hpp"
#include "anchii.hpp"
#include "ecrangestionpaquetcontroles.hpp"

class VueEcranMenuPaquet : public Observer {
public:
    explicit VueEcranMenuPaquet(Anchii *anchii, EcranGestionPaquetControles* ecranGestionPaquetListener);
    virtual ~VueEcranMenuPaquet() {}
    void update(int code);
private:
    /**
     * @brief anchii Le modèle de l'application
     */
    Anchii *anchii;
    /**
     * @brief ecranGestionPaquetsListener Le listener de cette vue
     */
    EcranGestionPaquetControles *ecranGestionPaquetsListener;
};

#endif // VUEECRANMENUPAQUET_HPP
