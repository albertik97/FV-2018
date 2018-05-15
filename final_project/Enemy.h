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
    void chargingTexture(std::string s,int a,int b,float c, float d);
    void setPosRandom(int*** &m);
    void draw();
    void update();//actualiza el movimiento
    void changeStrategy(IA* a);
    Sprite* getSprite();
    IA* getStrategy();
    float getPositionX();
    float getPositionY();
    float getLastPositionX();
    float getLastPositionY();
    void setPositionInterpolated(float a,float b);
    void colisionLengua(Sprite *s);
    
    void restarVida(int v);
    int getVida();
    
    
private:
    Sprite* sprite;
    float kVel;
    IA* strategy;
    int x,y,ylast,xlast;
    int vida;
};

#endif /* ENEMY_H */