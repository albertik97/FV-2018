#include "Enemy.h"
#include "IA.h"
#include "IAPasiva.h"
#include "Sprite.h"
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include<iostream>

Enemy::Enemy() {
    sprite=new Sprite();
    strategy=new IAPasiva();
    x=0;
    y=0;
    ylast=0;
    xlast=0;
}

Enemy::Enemy(const Enemy& orig) {
}

Enemy::~Enemy() {
}

void Enemy::chargingTexture(){
    sprite->setSpriteTexture("resources/enemy.png");
    sprite->setTextureRect(0,0,1024,1024);
    sprite->setOrigin(1024/2,1024/2);
    sprite->scale(0.07,0.07);  
    sprite->setAnimationTime(400);
}

void Enemy::setPosRandom(int*** &m){
     bool set=false;
   
    while(!set){
        x = rand() % 229;
        y = rand() % 129;
        x = (x*32)-16;
        y = (y*32)-16;
        xlast = x;
        ylast = y;
       if(m[1][y/32][x/32]==0){
   
            sprite->setPosition(x,y);
        

            set=true;
       }
        
    }
}

void Enemy::draw(){
    sprite->draw();
}

void Enemy::update(){
    xlast =x;
    ylast = y;
    strategy->elegirComportamiento(sprite);
    sprite->animar(0,0,1024,1024, 1026);
    x=sprite->getPosition().x;
    y=sprite->getPosition().y;
}

void Enemy::changeStrategy(IA* a){
    strategy=a;
}

Sprite* Enemy::getSprite(){
    return sprite;
}

IA* Enemy::getStrategy(){
    return strategy;
}

float Enemy::getPositionX()
{
    return x;
}

float Enemy::getPositionY()
{
    return y;
}

void Enemy::setPositionInterpolated(float a,float b){
    sprite->setPosition(a,b);
}

float Enemy::getLastPositionX()
{
    return xlast;
}

float Enemy::getLastPositionY()
{
    return ylast;
}