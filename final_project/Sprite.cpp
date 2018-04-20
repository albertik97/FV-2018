/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sprite.cpp
 * Author: blanca
 * 
 * Created on 10 de abril de 2018, 11:51
 */

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Motor2D.h"
#include "Sprite.h"
#include <string>
#include <iostream>

Sprite::Sprite(){
    //setSpriteTexture();
}

void Sprite::setSpriteTexture(std::string ruta){
sprite= new sf::Sprite(); 
if(!texture.loadFromFile(ruta))
    std::cout<<"error textura"<<std::endl;
sprite->setTexture(texture);
 
}

void Sprite::draw(){
   
    Motor2D *motor =  Motor2D::Instance();
    motor->dibujar(*sprite);
    
}


void Sprite::scale(float x, float y){
    sprite->scale(x,y);
}


void Sprite::moving(float dir, float v){
    
    sprite->move(dir,v);
}

void Sprite::rotate(float a){
    sprite->setRotation(a);
    
}

void Sprite::setOrigin(int x, int y){
    sprite->setOrigin(x,y);
}

void Sprite::setPosition(float x, float y){
    sprite->setPosition(x,y);
}

sf::Vector2f Sprite::getPosition(){
    return sprite->getPosition();
}


sf::Sprite* Sprite::getSprite(){
    return sprite;
}



