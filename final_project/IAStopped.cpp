/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "IAStopped.h"
#include "ingame_state.h"
#include <time.h>
#include <iostream>

IAStopped::IAStopped() {
    
}

IAStopped::IAStopped(const IAStopped& orig) {
}

IAStopped::~IAStopped() {
}

 void IAStopped::elegirComportamiento(Sprite* &s) {
     s->move(0,0);
 }
 
 void IAStopped::moverse(std::vector<Food*> f, Sprite* &s){
 
 }
 
void IAStopped::setVelocidad(float){
     
 }
 
int IAStopped::getType(){
     return 2;
 }



