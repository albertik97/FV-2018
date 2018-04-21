#include "IA.h"

#ifndef IAACTIVA_H
#define IAACTIVA_H

class IAActiva : public IA {
public:
    IAActiva();
    IAActiva(const IAActiva& orig);
    virtual ~IAActiva();
    int recalcularEstrategia(Sprite* s);
    void estrategia(Sprite* s);
private:

};

#endif /* IAACTIVA_H */

