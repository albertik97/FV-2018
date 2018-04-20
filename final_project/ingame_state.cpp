/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ingame_state.cpp
 * Author: blanca
 * 
 * Created on 17 de abril de 2018, 20:22
 */

#include "ingame_state.h"
#include "Motor2D.h"
#include "tinystr.h"
#include "tinyxml.h"
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <ctype.h>


ingame_state* ingame_state::pinstance = 0;
ingame_state* ingame_state::instance()
{
    if(pinstance == 0)
    {
        pinstance = new ingame_state;
    }
    return pinstance;
}
ingame_state::ingame_state()
{
    std::cout << "Esto deberia salir al crearse la escena de ingame" << std::endl;
    //j = Game::Instance();
    this->Init();
}
void ingame_state::Init()
{
    texto.setSize(20);
    texto.setText("Esta es la escena 'ingame_state'.");
        
    Motor2D::Instance()->getWindow()->setMouseCursorVisible(true);

    texto.setPos(Motor2D::Instance()->getWindow()->getSize().x / 2,Motor2D::Instance()->getWindow()->getSize().y / 2);
    player.chargingTexture();
    
    //mouse.setTexture("resources/pointer.png");
    //carga del mapa
    
    //mapa.cargarmapa();
    
    
    
    
}
void ingame_state::HandleInput()
{
     sf::Event evento;
        while(Motor2D::Instance()->getWindow()->pollEvent(evento))
        {
            if(evento.type == sf::Event::Closed)
               Motor2D::Instance()->getWindow()->close();
           // if(evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::F5)
               // j->ToogleFullscreen();
            if(evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Return)
            {
                 Game::instance()->setState(menu_state::Instance());
                 
                 
            }
            player.input();
        }
}
void ingame_state::Update()
{
   
    
    player.update();
    mouse.CursorUpdate();
    
    
}
void ingame_state::Draw()
{
       
        //texto.draw();
         //Motor2D::Instance()->getWindow()->draw(mapa);
         player.getSprite()->draw();
        
       
  
}