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

#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>



class Sprite {
public:
    Sprite();


    void draw( );
    void scale(float x, float y);
    void moving(float x, float y);
    void rotate(float angle);
    sf::Vector2f getPosition();
    void setPosition(float x, float y);
    void setOrigin(int x, int y);
    //metodos
    sf::Sprite* getSprite();
    void setSpriteTexture(std::string je);
    

    
    
private:
   sf::Sprite *sprite;
   sf::Texture texture;

};

#endif /* SPRITE_H */

