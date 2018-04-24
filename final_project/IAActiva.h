#include "IA.h"

#ifndef IAACTIVA_H
#define IAACTIVA_H

class IAActiva : public IA {
public:
    IAActiva();
    IAActiva(const IAActiva& orig);
    virtual ~IAActiva();
    void elegirComportamiento(Sprite* s);
    void moverse(std::vector<Food*> f,Sprite* s);
private:

};

#endif /* IAACTIVA_H */

