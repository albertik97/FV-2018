/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Text.cpp
 * Author: blanca
 * 
 * Created on 17 de abril de 2018, 20:07
 */

#include "Text.h"
#include<iostream>
#include "Motor2D.h"

Text::Text() {
    //se asigna la fuente
    if(!font.loadFromFile(GAME_MENU_FONT_FILEPATH))
        std::cout<<"error al cargar la fuente"<<std::endl;
    text.setFont(font);
}

void Text::draw(sf::RenderWindow &a){
    a.draw(text);
}

sf::Text Text::getText(){
    return text;
}
void Text::setColor(int r,int g,int b){
    text.setColor(sf::Color(r,g,b));
}
void Text::setFont(std::string fonts)
{
    if(!font.loadFromFile(fonts))
        std::cout<<"error al cargar la fuente"<<std::endl;
    text.setFont(font);
}

void Text::setText(std::string s){
    text.setString(s);
}

void Text::setPos(int x, int y){
    text.setPosition(sf::Vector2f(x,y));
    
}
void Text::setOriginCenter(){
    text.setOrigin(text.getGlobalBounds().width/2.0f,text.getGlobalBounds().height/2.0f);
}
void Text::setSize(int a){
    text.setCharacterSize(a);
}

bool Text::getColision(float x, float y){
    if(x>=text.getGlobalBounds().left&&x<=text.getGlobalBounds().width
     + text.getGlobalBounds().left &&
     y>=text.getGlobalBounds().top &&
     y<=text.getGlobalBounds().height + text.getGlobalBounds().top){
        return true;
    }else 
        return false;
}

void Text::draw(){
    Motor2D *motor =  Motor2D::Instance();
    motor->dibujarTexto(text);   
}

Text::Text(const Text& orig) {
}

Text::~Text() {
}
void Text::setAlpha(int a)
{
    text.setColor(sf::Color(text.getColor().r, text.getColor().g, text.getColor().b, a));
}
int Text::getAlpha()
{
    return static_cast<int>(text.getColor().a);
}
