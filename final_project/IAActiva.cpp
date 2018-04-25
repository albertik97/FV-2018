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
    
   /* kVel=3;
    dir=false;
    paralizado=false;
    pillado=false;
    mode=false;
    moviendose=false;
    comer=false;
    mov_dir=0;
    dist=0;
    dist_aux=0;
    tiempo=0;*/
}

IAActiva::IAActiva(const IAActiva& orig) {
}

IAActiva::~IAActiva() {
}

 void IAActiva::elegirComportamiento(Sprite* &s) {
   /* float time = 1;
    perseguir(s, time);
 */
 
 }
 
 void IAActiva::moverse(std::vector<Food*> f, Sprite* s){
 
 }
 
 /*
 void IAActiva::perseguir(Sprite* enemy, float time){
     Player *player = ingame_state::instance()->getPlayer();
     player->getPositionX();
     
     
     int xp=player->getPositionX();
            int yp=player->getPositionY();
            int xshape=enemy->getPosition().x;
            int yshape=enemy->getPosition().y;
            float angle = atan2(yp - yshape, xp - xshape);
          
            enemy->move(cos(angle)*2*time,sin(angle)*2*time);
    
            if(enemy->getSprite()->getGlobalBounds().intersects(player->getSprite()->getSprite()->getGlobalBounds())&&t_ataque.getElapsedTime().asSeconds()>0.4){//si esta cerca del player ataca
                std::cout<<"La IA usó mordisco!!!"<<std::endl;
                enemy->move(cos(angle)*20,sin(angle)*20);//se lanza a por el
                t_ataque.restart();
            }
 }
*/