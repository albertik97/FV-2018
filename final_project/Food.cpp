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

Food::Food() {
    foodSprite = new Sprite();
}

Food::Food(const Food& orig) {
}

Food::~Food() {
}

Sprite* Food::getSprite(){
    return foodSprite;
}

