#include "vueecranmenupaquet.hpp"
#include "paquet.hpp"
#include "anchii.hpp"
#include "observer.hpp"

#include <ui_anchii.h>
#include <ui_mainscreen.h>


VueEcranMenuPaquet::VueEcranMenuPaquet(Anchii *anchii, EcranGestionPaquetControles* ecranGestionPaquetListener) : Observer () {
    this->anchii = anchii;
    this->ecranGestionPaquetsListener = ecranGestionPaquetListener;
    this->anchii->addObserver(this);
}

void VueEcranMenuPaquet::update() {

}
