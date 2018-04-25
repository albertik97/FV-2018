#include "Sprite.h"
#include "Food.h"
#ifndef IA_H
#define IA_H

class IA {
public:
    virtual void moverse(std::vector<Food*> f,Sprite* s)=0;
    virtual void elegirComportamiento(Sprite* &s)=0;
private:
    
protected:
  //void estrategias(Sprite* s);
};

#endif /* IA_H */
