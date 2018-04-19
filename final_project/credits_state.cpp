/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   credits_state.cpp
 * Author: blanca
 * 
 * Created on 19 de abril de 2018, 9:33
 */



#include "credits_state.h"
#include "Motor2D.h"

credits_state* credits_state::pinstance = 0;
credits_state* credits_state::Instance()
{
    if(pinstance == 0)
    {
        pinstance = new credits_state;
    }
    return pinstance;
}
credits_state::credits_state()
{
    this->Init();
}
void credits_state::Init()
{
    texto.setSize(20);
    texto.setText("Credits");
    texto.setText("Alberto Berenguer");

    texto.setPos(Motor2D::Instance()->getWindow()->getSize().x / 2,Motor2D::Instance()->getWindow()->getSize().y / 2);
   
    
}
void credits_state::HandleInput()
{
 
}
void credits_state::Update()
{
    sf::Event event;
    while(Motor2D::Instance()->getWindow()->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            Motor2D::Instance()->closeWindow();
        }
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
             Game::instance()->setState(menu_state::Instance());
        }
    }
}
void credits_state::Draw()
{
 //Motor2D::Instance()->getWindow()->draw(mapa);
 
}