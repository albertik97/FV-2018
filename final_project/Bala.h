
#ifndef BALA_H
#define BALA_H

#include "Sprite.h"
#include "Clock.h"
class Bala {
public:
    Bala(int,int);
    Bala(const Bala& orig);
    virtual ~Bala();
    void setDirection();
    void update();
    void draw();
    Sprite* getSprite();
private:
    Sprite* sprite;
    float direction;
    Clock time;
    
};

#endif /* BALA_H */

