/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Food.cpp
 * Author: blanca
 * 
 * Created on 17 de abril de 2018, 12:26
 */

#include "Food.h"

Food::Food() {
    sprite = new Sprite();
    chargingTexture();
}

Food::Food(const Food& orig) {
}

Food::~Food() {
}

void Food::chargingTexture() {
    

	
	sprite->setSpriteTexture("resources/sprites.png");                              // Y creo el spritesheet a partir de la imagen anterior
        sprite->getSprite()->setTextureRect(sf::IntRect(278,238, 40, 64));
	sprite->getSprite()->setOrigin(75/2,75/2);
      
	
}


Sprite* Food::getSprite(){
    return sprite;
}



