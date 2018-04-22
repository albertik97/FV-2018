/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include "Motor2D.h"
#include "Rectangleshape.h"

Rectangleshape::Rectangleshape(){
  ;
}


void Rectangleshape::setSize(float x, float y){
    sf::Vector2f size;
    size.x = x;
    size.y = y;
    rectangleshape->setSize(size);
}

void Rectangleshape::setPosition(float x, float y){
    rectangleshape->setPosition(x, y);
}

void Rectangleshape::setOrigin(int x, int y){
    rectangleshape->setOrigin(x, y);
}

void Rectangleshape::setFillColor(std::string color){
    if(color == "Azul"){
        rectangleshape->setFillColor(sf::Color(25,50,240));
    }else if(color == "Verde"){
        rectangleshape->setFillColor(sf::Color(25,240,30));
    }else{
        rectangleshape->setFillColor(sf::Color(255,255,255));
    }
}

void Rectangleshape::scale(float x, float y){
    rectangleshape->scale(x, y);
}

sf::RectangleShape* Rectangleshape::getRectangleshape(){
    return rectangleshape;
}

void Rectangleshape::draw(){
    Motor2D *motor =  Motor2D::Instance();
    motor->dibujarRectangulo(*rectangleshape);
}