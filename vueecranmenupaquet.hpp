#ifndef VUEECRANMENUPAQUET_HPP
#define VUEECRANMENUPAQUET_HPP

#include <QSignalMapper>

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

    /**
     * @brief mapper Permet au controleur d'appeler une méthode avec un paramètre
     */
    QSignalMapper mapper;
};

#endif // VUEECRANMENUPAQUET_HPP
