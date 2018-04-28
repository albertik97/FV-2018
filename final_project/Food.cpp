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
    if(random>=0&&random<5){//verdura
        type=0;
        chargingTexture("resources/food.png",96,192,32,32);
    }else if(random>=5&&random<9){
        type=1;
        chargingTexture("resources/food.png",96,64,32,32);
    }else{
        chargingTexture("resources/food.png",288,64,32,32);
        type=2;
    }
}

Food::Food(const Food& orig) {
}

Food::~Food() {
}

int Food::getType(){
    return type;
}

void Food::update(){
    sprite->animar(primer, segundo, tercero, cuarto, 32);
}

void Food::chargingTexture(std::string s, int a, int b,int c , int d) {	
    primer=a;
    segundo=b;
    tercero=c;
    cuarto=d;
        sprite->setSpriteTexture(s);                              // Y creo el spritesheet a partir de la imagen anterior
        sprite->getSprite()->setTextureRect(sf::IntRect(a,b,c,d));
	sprite->getSprite()->setOrigin(32/2,32/2);
        sprite->getSprite()->setScale(1.3,1.3);
        sprite->setAnimationTime(150);
}


Sprite* Food::getSprite(){
    return sprite;
}

void Food::setRandomFood(sf::Sprite**** &m){
    bool set=false;
    while(!set){
        int x= (rand() % (229)); //random para elegir la direccion
        int y= (rand() % (129));
        if(m[1][y][x]==NULL && m[1][y+1][x+1]==NULL && m[1][y][x+1]==NULL && m[1][y+1][x]==NULL && m[1][y-1][x-1]==NULL && m[1][y-1][x]==NULL && m[1][y][x-1]==NULL && m[1][y+1][x-1]==NULL & m[1][y-1][x+1]==NULL){
             sprite->setPosition(x*32-16,y*32-16);
             set=true;
        }
    }
}


