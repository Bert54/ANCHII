#ifndef ECRANMENUPAQUET_H
#define ECRANMENUPAQUET_H

#include <string>
#include "observateur.h"

class EcranMenuPaquet : public Observateur
{
public :
    EcranMenuPaquet EcranMenuPaquet(Anchii _anchii);
    EcranMenuPaquet ~EcranMenuPaquet();
    void supprimerCarte(); //A peut etre besoin d'un parametre pour savoir quel paquet supprimer
    void supprimerPaquet();

    void::refresh(Event<std::string>* e);
private :
    Anchii _anchii;
};

#endif // ECRANMENUPAQUET_H
