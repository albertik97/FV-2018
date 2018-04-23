
#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>
#include "Sprite.h"
#include "Clock.h"
#include<stdlib.h>
#include<time.h>
#include<string>
#include<iostream>



    class Food {
public:
    Food();
    Food(const Food& orig);
    virtual ~Food();
    void draw( );
    //metodos
    void chargingTexture(std::string s,int a,int b,int c, int d);
    bool colisionComida();
    void setRandomFood(sf::Sprite**** &a);
    Sprite* getSprite();
        void update();//actualiza el movimiento
    
private:
    Sprite *sprite;
    int type;
    Clock clock;
    int primer, segundo, tercero, cuarto;
};

#endif /* SPRITE_H */

