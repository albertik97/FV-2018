/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Colisionator.cpp
 * Author: blanca
 * 
 * Created on 21 de abril de 2018, 13:34
 */

#include <vector>

#include "Colisionator.h"
#include <iostream>

Colisionator::Colisionator() {
   
}

Colisionator::Colisionator(const Colisionator& orig) {
}

Colisionator::~Colisionator() {
}


void Colisionator::setPlayer(Player* &p){
    player = p;
}

bool Colisionator::checkColisionComida(std::vector<Food*> &comidaArray){
    
   // std::cout<<"LLAMADA AL METODO";

    for(int i=0; i<comidaArray.size(); i++){
        if(comidaArray[i]->getSprite()->getSprite()->getGlobalBounds().intersects(player->getSprite()->getSprite()->getGlobalBounds())){
                 if(comidaArray[i]->getType()==0){
                     player->setExperiencia(10);
                     player->aumentaVerdura();
                 }
                 if(comidaArray[i]->getType()==1){
                     player->setExperiencia(10);
                     player->aumenteCarne();
                 }
                 if(comidaArray[i]->getType()==2){
                     player->setExperiencia(-30);
                 } 
              delete comidaArray[i]; //liberas memoria
                comidaArray[i]=NULL;
                comidaArray.erase(comidaArray.begin() + i); 
               //eliminas la posición del vector
                
                return true;
       }
    }
     return false;
    
}
 