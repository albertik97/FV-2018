/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   options_state.cpp
 * Author: blanca
 * 
 * Created on 19 de abril de 2018, 9:33
 */


#include "options_state.h"
#include "Motor2D.h"

options_state* options_state::pinstance = 0;
options_state* options_state::Instance()
{
    if(pinstance == 0)
    {
        pinstance = new options_state;
    }
    return pinstance;
}
options_state::options_state()
{
    this->Init();
}
void options_state::Init()
{
    
}
void options_state::HandleInput()
{
  
}
void options_state::Update()
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
void options_state::Draw()
{
 //Motor2D::Instance()->getWindow()->draw(mapa);
}