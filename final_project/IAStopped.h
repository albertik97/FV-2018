#include "IA.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Colisionator.h"
#ifndef IASTOPPED_H
#define IASTOPPED_H

class IAStopped : public IA {
public:
    IAStopped();
    IAStopped(const IAStopped& orig);
    virtual ~IAStopped();
    void elegirComportamiento(Sprite* &s);
    void moverse(std::vector<Food*> f,Sprite* &s);
   // void setVelocidad(float velocidad);
    void setVelocidad(float);

    bool checkColisionMap(int x, int y, Sprite* enemy);

    int getType();
private:
   
};

#endif /* IASTOPPED_H */
