/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sprite.h
 * Author: blanca
 *
 * Created on 10 de abril de 2018, 11:51
 */

#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>
#include "Sprite.h"



    class Food {
public:
    Food();
    Food(const Food& orig);
    virtual ~Food();
    void draw( );
    //metodos
    void chargingTexture();
    bool colisionComida();
    
    Sprite* getSprite();


    
    
private:
    Sprite *sprite;
};

#endif /* SPRITE_H */

