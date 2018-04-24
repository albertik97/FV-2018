/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Keyboard.cpp
 * Author: blanca
 * 
 * Created on 17 de abril de 2018, 20:07
 */

#include <SFML/Window/Keyboard.hpp>

#include "Keyboard.h"

Keyboard::Keyboard() {
}

Keyboard::Keyboard(const Keyboard& orig) {
}

Keyboard::~Keyboard() {
}






bool Keyboard::isKeyWPressed(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        return true;
    }else
        return false;
}

bool Keyboard::isKeyAPressed(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        return true;
    }else
        return false;
}

bool Keyboard::isKeySPressed(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        return true;
    }else
        return false;
}

bool Keyboard::isKeyDPressed(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        return true;
    }else
        return false;
}

bool Keyboard::isKeyPPressed(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
        return true;
    }else
        return false;
}

 bool Keyboard::isKeyUpPressed(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        return true;
    }else
        return false;
}


bool Keyboard::isKeyDownPressed(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        return true;
    }else
        return false;
}


bool Keyboard::isKeyEscPressed(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        return true;
    }else
        return false;
}

bool Keyboard::isKey1Pressed(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
        return true;
    }else
        return false;
}

bool Keyboard::isKey2Pressed(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
        return true;
    }else
        return false;
}

bool Keyboard::isKey3Pressed(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)){
        return true;
    }else
        return false;
}

bool Keyboard::isKeyEnterPressed(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        return true;
    }else
        return false;
}
bool Keyboard::isKeySpacePressed()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        return true;
    return false;
}
