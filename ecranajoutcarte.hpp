#ifndef ECRANAJOUTCARTE_H
#define ECRANAJOUTCARTE_H

#include <string>
#include "observateur.h"

class EcranAjoutCarte : public Observateur
{
public:
    EcranAjoutCarte EcranAjoutCarte(Anchii _anchii);
    EcranAjoutCarte ~EcranAjoutCarte();
    void AjouterCarte();

    void::refresh(Event<std::string>* e);
private :
    Anchii _anchii;
};

#endif // ECRANAJOUTCARTE_H
