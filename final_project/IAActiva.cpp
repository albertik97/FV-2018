/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IAActiva.cpp
 * Author: root
 * 
 * Created on 21 de abril de 2018, 13:06
 */

#include "IAActiva.h"
#include "ingame_state.h"

IAActiva::IAActiva() {
    
    kVel=3;
}

IAActiva::IAActiva(const IAActiva& orig) {
}

IAActiva::~IAActiva() {
}

 void IAActiva::elegirComportamiento(Sprite* &s) {
   float time = 1;
    perseguir(s, time); 
 }
 
 void IAActiva::moverse(std::vector<Food*> f, Sprite* s){
 
 }
 
 void IAActiva::perseguir(Sprite* enemy, float time){
     Player *player = ingame_state::instance()->getPlayer();
     player->getPositionX();
     
     
        int xp=player->getPositionX();
        int yp=player->getPositionY();
        int xenemy=enemy->getPosition().x;
        int yenemy=enemy->getPosition().y;
        float angle = atan2(yp - yenemy, xp - xenemy);
        if(checkColisionMap(-kVel,0, enemy)){
            enemy->move(kVel, 0);               
        }
        if(checkColisionMap(kVel,0, enemy)){
            enemy->move(-kVel, 0);               
        }
        if(checkColisionMap(0,-kVel, enemy)){
            enemy->move(0, kVel);               
        }
        if(checkColisionMap(0,kVel, enemy)){
            enemy->move(0, -kVel);               
        }
        else{
          enemy->move(cos(angle)*2*time,sin(angle)*2*time);

        }

        //NO VA!!!!!!
        if(enemy->getSprite()->getGlobalBounds().intersects(player->getSprite()->getSprite()->getGlobalBounds())){//si esta cerca del player ataca
              std::cout<<"Hay colision"<<std::endl;
              enemy->move(cos(angle)*4,sin(angle)*4);//se lanza a por el
              //t_ataque.reset();
          }
            
 }
 
 bool IAActiva::checkColisionMap(int x, int y, Sprite* s){
    
    //COJO LAS CUATRO ESQUINAS DEL BOUNDING BOX
    
    float left = s->getSprite()->getGlobalBounds().left+15 + x;
    float top = s->getSprite()->getGlobalBounds().top+15 + y;
    float right = s->getSprite()->getGlobalBounds().width-60 + left;
    float down = top + s->getSprite()->getGlobalBounds().height-60;

    
    if(ingame_state::instance()->instance()->getMapa()._tilemap[1][(int)top/32][(int)left/32]==0 &&
      ingame_state::instance()->instance()->getMapa()._tilemap[1][(int)top/32][(int)right/32]==0 &&
      ingame_state::instance()->instance()->getMapa()._tilemap[1][(int)down/32][(int)left/32]==0 &&
      ingame_state::instance()->instance()->getMapa()._tilemap[1][(int)down/32][(int)right/32]==0){

        
        return false;
   
    }
    return true;
    
}
