#include "Sprite.h"
#include "Food.h"
#include <iostream>
#ifndef IA_H
#define IA_H

class IA {
public:
    virtual void moverse(std::vector<Food*> f,Sprite* &s)=0;
    virtual void elegirComportamiento(Sprite* &s)=0;
    virtual int getType() = 0;
    virtual void setVelocidad(float) = 0;
    virtual bool checkColisionMap(int x, int y, Sprite* enemy)=0;

private:
    
protected:
  //void estrategias(Sprite* s);
};

#endif /* IA_H */