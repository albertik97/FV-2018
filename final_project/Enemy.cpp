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
}

void Enemy::setPosRandom(){
    int x = rand() % 1900;
    int y = rand() % 1810;
    
    std::cout<<x<<","<<y<<std::endl;
    sprite->setPosition(x,y);
}

void Enemy::draw(){
    sprite->draw();
}

void Enemy::update(){
    strategy->recalcularEstrategia(sprite);
}

void Enemy::changeStrategy(IA* a){
    strategy=a;
}