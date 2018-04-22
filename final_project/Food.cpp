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
#include<stdlib.h>
#include<time.h>

Food::Food() {
    sprite = new Sprite();
    int random=rand() % (10);
    if(random>=0&&random<4){
        type=0;
        chargingTexture("resources/food.png",0,128,32,32);
    }else if(random>=4&&random<8){
        type=1;
        chargingTexture("resources/food.png",0,0,32,32);
    }else{
        chargingTexture("resources/food.png",192,0,32,32);
        type=2;
    }
}

Food::Food(const Food& orig) {
}

Food::~Food() {
}

void Food::chargingTexture(std::string s, int a, int b,int c , int d) {	
	sprite->setSpriteTexture(s);                              // Y creo el spritesheet a partir de la imagen anterior
        sprite->getSprite()->setTextureRect(sf::IntRect(a,b,c,d));
	sprite->getSprite()->setOrigin(32/2,32/2);
}


Sprite* Food::getSprite(){
    return sprite;
}

void Food::setRandomFood(){
    int x= (1 + rand() % (1900)); //random para elegir la direccion
    int y= (1 + rand() % (1025));
    sprite->setPosition(x,y);
}



