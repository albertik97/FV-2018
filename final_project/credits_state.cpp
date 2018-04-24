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
   texto[0].setText("Credits: ");
   texto[0].setSize(50);
   texto[0].setOriginCenter();
   texto[0].setPos(WINDOW_WIDTH * 0.15, WINDOW_HEIGHT * 0.1);
   texto[0].setColor(255, 255, 255);
   
   texto[1].setText("Alejandro Domenech Vicedo");
   texto[1].setSize(25);
   texto[1].setPos(WINDOW_WIDTH * 0.05, WINDOW_HEIGHT * 0.25);
   texto[1].setColor(255, 255, 255);
   
   
   texto[2].setText("Alberto Berenguer Pastor");
   texto[2].setSize(25);
   texto[2].setPos(WINDOW_WIDTH * 0.05, WINDOW_HEIGHT * 0.35);
   texto[2].setColor(255, 255, 255);
   
   texto[3].setText("Blanca Vazquez Paredes");
   texto[3].setSize(25);
   texto[3].setPos(WINDOW_WIDTH * 0.05, WINDOW_HEIGHT * 0.45);
   texto[3].setColor(255, 255, 255);
   
   texto[4].setText("Carlos Aracil Perez");
   texto[4].setSize(25);
   texto[4].setPos(WINDOW_WIDTH * 0.05, WINDOW_HEIGHT * 0.55);
   texto[4].setColor(255, 255, 255);
   
   texto[5].setText("Jose Garcia Parrenyo");
   texto[5].setSize(25);
   texto[5].setPos(WINDOW_WIDTH * 0.05, WINDOW_HEIGHT * 0.65);
   texto[5].setColor(255, 255, 255);
   
   for(int i = 0; i < sizeof(texto) / sizeof(texto[0]); i++)
        texto[i].setAlpha(0);
   
   img[0].setSpriteTexture(PLAYER_SPRITE_FILEPATH);
   img[0].setTextureRect(0,0,1024,1024);
   img[0].setOrigin(1024/2,1024/2);
   img[0].scale(0.5, 0.5);
   img[0].setAnimationTime(400);
   img[0].setPosition(WINDOW_WIDTH * 0.7, WINDOW_HEIGHT / 2);
   
   img[1].setSpriteTexture(PLAYER_SPRITE_FILEPATH);
   img[1].setTextureRect(0,0,1024,1024);
   img[1].setOrigin(1024/2,1024/2);
   img[1].scale(0.2, 0.2);
   img[1].setAnimationTime(400);
   img[1].setPosition(WINDOW_WIDTH * 0.9, WINDOW_HEIGHT / 1.5);
   
   img[2].setSpriteTexture(PLAYER_SPRITE_FILEPATH);
   img[2].setTextureRect(0,0,1024,1024);
   img[2].setOrigin(1024/2,1024/2);
   img[2].scale(0.35, 0.35);
   img[2].setAnimationTime(400);
   img[2].setPosition(WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.8);
   
   
}
void credits_state::HandleInput()
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
            for(int i = 0; i < sizeof(texto) / sizeof(texto[0]); i++)
                texto[i].setAlpha(0);
            creditsTimer.reset();
            Game::instance()->setState(menu_state::Instance());
        }
    }
}
void credits_state::Update()
{
   if(creditsTimer.getSeconds() < INTRO_STATE_TRANSITION_TIME) 
   {
       beginAlpha();
   }
   
}
void credits_state::Draw()
{
    for(int i = 0; i < sizeof(texto) / sizeof(texto[0]); i++)
        texto[i].draw();
    for(int i = 0; i < sizeof(img) / sizeof(img[0]); i++)
        img[i].draw();
}

void credits_state::beginAlpha()
{
    int alpha = texto[0].getAlpha() + INTRO_STATE_TRANSITION_SPEED;
    
    if(alpha >= 255)
    {
        alpha = 255;
    }
    for(int i = 0; i < sizeof(texto) / sizeof(texto[0]); i++)
        texto[i].setAlpha(alpha);
}
void credits_state::endAlpha()
{
    
}