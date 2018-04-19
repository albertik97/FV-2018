/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mouse.cpp
 * Author: blanca
 * 
 * Created on 17 de abril de 2018, 20:08
 */


#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>
#include<iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Mouse.h"

Mouse::Mouse() {
    cursor= new Sprite();
    cursor->setSpriteTexture("resources/pointer.png");
    cursor->scale(0.1,0.1);
    cursor->setOrigin(cursor->getSprite()->getGlobalBounds().width/2,cursor->getSprite()->getGlobalBounds().height/2);
}

Mouse::Mouse(const Mouse& orig) {
}

Mouse::~Mouse() {
}

bool Mouse::RightPressed(){
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
        return true;
    }else
        return false;
}

bool Mouse::LeftPressed(){
    
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        return true;
    }else
        return false;
}

float Mouse::getPosX(){
    return sf::Mouse::getPosition().x;
}

float Mouse::getPosY(){
    return sf::Mouse::getPosition().y;
}

void Mouse::CursorUpdate(){
    cursor->setPosition(mouse.getPosition().x,mouse.getPosition().y);
}

Sprite* Mouse::getCursorSprite(){
    return cursor;
}