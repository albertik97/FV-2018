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

void Sprite::setAnimationTime(int t){
    animationTime = t;
}

void Sprite::animar(int a, int b, int c, int d, int factor){ //TODO cuando tengamos todos los sprites pasarlos o algo por parametro
   
        if(tiempo.getElapsedTime().asMilliseconds()<animationTime){
            sprite->setTextureRect(sf::IntRect(a+(factor*0),b, c, d)); 
        }
        if(tiempo.getElapsedTime().asMilliseconds()>animationTime && tiempo.getElapsedTime().asMilliseconds()<animationTime*2){
            sprite->setTextureRect(sf::IntRect(a+(factor*1),b, c, d));
        }
        if(tiempo.getElapsedTime().asMilliseconds()>animationTime*2 && tiempo.getElapsedTime().asMilliseconds()<animationTime*3){
            sprite->setTextureRect(sf::IntRect(a+(factor*2),b, c, d));
        }
        if(tiempo.getElapsedTime().asMilliseconds()>animationTime*3 && tiempo.getElapsedTime().asMilliseconds()<animationTime*4){
            sprite->setTextureRect(sf::IntRect(a+(factor*1),b, c, d));
        }

        if(tiempo.getElapsedTime().asMilliseconds()>animationTime*4){
            tiempo.restart();
        }      
    
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


void Sprite::setTextureRect(int a, int b, int c, int d){
    sprite->setTextureRect(sf::IntRect(a,b, c, d));
}

void Sprite::move(int a,int b){
    sprite->move(a,b);
}

