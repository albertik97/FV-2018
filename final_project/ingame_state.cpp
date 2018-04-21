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
#include <vector>


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

    texto.setPos(Motor2D::Instance()->getWindow()->getSize().x / 2,Motor2D::Instance()->getWindow()->getSize().y / 2);
    player = new Player();
    player->chargingTexture();
    
    int x=70;
    int y=70;
    

    
    for(int i=0; i<10; i++){
        
      Food* comida = new Food();
      comidaArray.push_back(comida);
      comidaArray[i]->getSprite()->setPosition(x,y);
      
           
            x=x+75;
            y=y+75;
      
    }
    
    
    
   //carga del mapa
    
   mapa.cargarmapa();
   mouse.initMouse("resources/mira.png",0.1,0.1);
   colision.setPlayer(player);
   colision.setFood(comidaArray);
    
    
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
            player->input();
        }
}
void ingame_state::Update()
{
   

    player->update();
    mouse.CursorUpdate();
    colision.update();

}
void ingame_state::Draw()
{       
        //texto.draw();
        Motor2D::Instance()->getWindow()->draw(mapa);
        player->getSprite()->draw();
        mouse.getCursorSprite()->draw();
         for(int i=0; i<comidaArray.size(); i++){
            comidaArray[i]->getSprite()->draw();
        }
 
}