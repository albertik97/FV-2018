#include"Sprite.h"
#include "Coords.h"
#include "IA.h"
#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
public:
    Enemy();
    Enemy(const Enemy& orig);
    virtual ~Enemy();
    void chargingTexture();
    void setPosRandom(int*** &m);
    void draw();
    void update();//actualiza el movimiento
    void changeStrategy(IA* a);
    Sprite* getSprite();
    IA* getStrategy();
private:
    Sprite* sprite;
    Coords actual,last;
    float kVel;
    IA* strategy;
};

#endif /* ENEMY_H */
