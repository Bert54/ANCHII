#ifndef ECRANMENUPRINCIPAL_H
#define ECRANMENUPRINCIPAL_H

#include <string>
#include "observateur.hpp"

class EcranMenuPrincipal : public Observateur
{
public:
    EcranMenuPrincipal::EcranMenuPrincipal(Anchii anchii);
    EcranMenuPrincipal::~EcranMenuPrincipal();
    void::ajouterPaquet();

    void::refresh(Event<std::string>* e);
};

#endif // ECRANMENUPRINCIPAL_H
