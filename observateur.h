#ifndef OBSERVATEUR_H
#define OBSERVATEUR_H

#include "event.h"

template<typename Object>
class Observateur{
public:
    virtual void refresh(Event<Object>* e) = 0;
};

#endif // OBSERVATEUR_H
