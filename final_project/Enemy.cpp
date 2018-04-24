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
        int x = rand() % 159;
        int y = rand() % 89;
       if(m[1][y][x]==0){
            sprite->setPosition(x*32-16,y*32-16);
            set=true;
       }
    }
}

void Enemy::draw(){
    sprite->draw();
}

void Enemy::update(){
    strategy->elegirComportamiento(sprite);
    sprite->animar(0,0,1024,1024, 1026);
}

void Enemy::changeStrategy(IA* a){
    strategy=a;
}