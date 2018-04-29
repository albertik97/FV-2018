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

}

Mouse::Mouse(const Mouse& orig) {
}

Mouse::~Mouse() {
}

void Mouse::initMouse(std::string a, float s1, float s2){
    cursor= new Sprite();
    cursor->setSpriteTexture(a);
    cursor->scale(s1,s2);
    cursor->setOrigin(cursor->getSprite()->getGlobalBounds().width/2,cursor->getSprite()->getGlobalBounds().height/2);
   // cursor->setPosition(500, 500);
}

void Mouse::setTexture(std::string route){
    
    cursor->setSpriteTexture(route);
}

void Mouse::setPositionInterpolated(float x, float y)
{
    /*std::cout << "x interpolado: " << x << std::endl;
    std::cout << "y interpolado: " << y << std::endl;*/
    cursor->setPosition(x, y);
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

float Mouse::getPosX()
{
    return sf::Mouse::getPosition().x;
}

float Mouse::getPosY(){
    return sf::Mouse::getPosition().y;
}

float Mouse::getLastPositionX()
{
    return xlast;
}

float Mouse::getLastPositionY()
{
    return ylast;
}

void Mouse::CursorUpdate(int x, int y){
    xlast = cursor->getPosition().x;
    ylast = cursor->getPosition().y;
    /*std::cout << "DespX: " << xlast << std::endl;
    std::cout << "DespY: " << ylast  << std::endl;*/
    
        cursor->setPosition(sf::Mouse::getPosition(*(Motor2D::Instance()->getWindow())).x + x, sf::Mouse::getPosition(*(Motor2D::Instance()->getWindow())).y + y);
        /*std::cout << "MouseX: " << cursor->getPosition().x << std::endl;
        std::cout << "MouseY: " << cursor->getPosition().y << std::endl;*/
}   

Sprite* Mouse::getCursorSprite(){
    return cursor;
}

sf::Mouse Mouse::getMouse()
{
    return mouse;
}