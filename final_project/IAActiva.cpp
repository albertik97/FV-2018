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
#include <time.h>
#include <iostream>

IAActiva::IAActiva() {
    
    kVel=15;
    t_ataque.reset();
    if((std::rand())%2==0){
        tipo=0;
    }
    else{
        tipo=1;
    }
    srand(time(NULL));
    rand_decision = std::rand()%8;
    
    
    
}

IAActiva::IAActiva(const IAActiva& orig) {
}

IAActiva::~IAActiva() {
}

 void IAActiva::elegirComportamiento(Sprite* &s) {
   float time = 1;
    perseguir(s, time); 
 }
 
 void IAActiva::moverse(std::vector<Food*> f, Sprite* &s){
 
 }
 
 void IAActiva::perseguir(Sprite* enemy, float time){
     if(t_ataque.getSeconds()>0.3){
        Player *player = World::Instance()->getPlayer();
        player->getPositionX();
        int xp, yp;
        //std::cout<<rand_decision<<std::endl;

        switch(rand_decision){
            case 0: //arriba
                 xp=player->getPositionX();
                 yp=player->getPositionY()-100;
            break;
             case 1: //abajo
                 xp=player->getPositionX();
                 yp=player->getPositionY()+100;
            break;
             case 2: //derecha
                 xp=player->getPositionX()+100;
                 yp=player->getPositionY();
            break;
             case 3: //izquierda
                 xp=player->getPositionX()-100;
                 yp=player->getPositionY();
            break;
             case 4: //izquierda
                 xp=player->getPositionX()-100;
                 yp=player->getPositionY()-100;
            break;
             case 5: //izquierda
                 xp=player->getPositionX()-100;
                 yp=player->getPositionY()+100;
            break;
             case 6: //izquierda
                 xp=player->getPositionX()+100;
                 yp=player->getPositionY()+100;
            break;
             case 7: //izquierda
                 xp=player->getPositionX()+100;
                 yp=player->getPositionY()-100;
            break;

        }
 
           int xenemy=enemy->getPosition().x;
           int yenemy=enemy->getPosition().y;
           float angle = atan2(yp - yenemy, xp - xenemy);
           
     
               if(!checkColisionMap(cos(angle)*2*time*kVel,sin(angle)*2*time*kVel,enemy) && (abs(player->getPositionY()-yenemy)>10) && (abs(player->getPositionX()-xenemy)>10)){
                    enemy->move(cos(angle)*2*time*kVel,sin(angle)*2*time*kVel);

               }else if(!checkColisionMap(cos(atan2(player->getPositionY() - yenemy, player->getPositionX() - xenemy))*2*time*kVel,sin(atan2(player->getPositionY() - yenemy, player->getPositionX() - xenemy))*2*time*kVel,enemy)){
                   float angle = atan2(player->getPositionY() - yenemy, player->getPositionX()- xenemy);
                     enemy->move(cos(angle)*2*time*kVel,sin(angle)*2*time*kVel);
                    }else{


                        //enemy->move(-cos(angle)*2*time*kVel,-sin(angle)*2*time*kVel);
                        float x = player->getPositionX();
                        float y = player->getPositionY();
                        float xe =enemy->getPosition().x;
                        float ye =enemy->getPosition().y;
                        if(y-enemy->getPosition().y>0 && x-enemy->getPosition().x>0){
                                    simpleColision(enemy);
                                     if(tipo==0){
                                         enemy->move(-kVel,kVel);
                                     }
                                     else{
                                         enemy->move(kVel,-kVel);
                                     }
                                     //std::cout<<"1ºcuadrante"<<std::endl;

                                 }
                                  if(y-enemy->getPosition().y<0 && x-enemy->getPosition().x>0){
                                   simpleColision(enemy);
                                      if(tipo==0){
                                         enemy->move(kVel,kVel);
                                     }
                                     else{
                                         enemy->move(-kVel,-kVel);
                                     }
                                     //std::cout<<"4ºcuadrante"<<std::endl;

                                 }
                                  if(y-enemy->getPosition().y<0 && x-enemy->getPosition().x<0){
                                   simpleColision(enemy);
                                      if(tipo==0){
                                         enemy->move(-kVel,kVel);
                                     }
                                     else{
                                         enemy->move(kVel,-kVel);
                                     }
                                     //std::cout<<"3ºcuadrante"<<std::endl;

                                 }
                                  if(y-enemy->getPosition().y>0 && x-enemy->getPosition().x<0){
                                    simpleColision(enemy);
                                      if(tipo==0){
                                         enemy->move(kVel,kVel);
                                     }
                                     else{
                                         enemy->move(-kVel,-kVel);
                                     }
                                     //std::cout<<"2ºcuadrante"<<std::endl;

                                 }

                }
           //miramos al personaje
           
            const float PI = 3.14159265;
            float dx = player->getSprite()->getPosition().x - enemy->getPosition().x;
            float dy = player->getSprite()->getPosition().y - enemy->getPosition().y;
            
            float rotation = (atan2(dy, dx)) * 180 / PI;
            
            enemy->getSprite()->setRotation(rotation+90);

           if(enemy->getSprite()->getGlobalBounds().intersects(player->getSprite()->getSprite()->getGlobalBounds())){//si esta cerca del player ataca

                enemy->move(0,0);//se lanza a por el
                t_ataque.reset();
                World::Instance()->getPlayer()->restaVida();
                

             }
     }
            
 }
 
 bool IAActiva::checkColisionMap(int x, int y, Sprite* s){
    
    //COJO LAS CUATRO ESQUINAS DEL BOUNDING BOX
    
    float left = s->getSprite()->getGlobalBounds().left+15+ x;
    float top = s->getSprite()->getGlobalBounds().top+15 + y;
    float right = s->getSprite()->getGlobalBounds().width-60 + left;
    float down = top + s->getSprite()->getGlobalBounds().height-60;

    
    if(World::Instance()->getMapa()._tilemap[1][(int)top/32][(int)left/32]==0 &&
       World::Instance()->getMapa()._tilemap[1][(int)top/32][(int)right/32]==0 &&
       World::Instance()->getMapa()._tilemap[1][(int)down/32][(int)left/32]==0 &&
       World::Instance()->getMapa()._tilemap[1][(int)down/32][(int)right/32]==0){

        
        return false;
   
    }
    return true;
    
}
 
 void IAActiva::simpleColision(Sprite* enemy){
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
 }
 

 int IAActiva::getType(){
     return 0;
 }
 
 void IAActiva::setVelocidad(float velocidad){
     kVel = velocidad;
 }