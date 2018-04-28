/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: blanca
 * 
 * Created on 10 de abril de 2018, 12:18
 */

#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <SFML/Window/Window.hpp>

#include "Sprite.h"
#include "Game.h"

#include "Motor2D.h"

#include  <iostream>

#define UPDATE_TICK_TIME 1000/15

Game* Game::pinstance=0;
Game* Game::instance(){
    if(pinstance==0){
        pinstance= new Game();
    }
    return pinstance;
    
}

Game::Game(){
    
}


void Game::run(){
    //init();
    
    Motor2D *motor =  Motor2D::Instance();
    motor->setFrameLimit();
    
    Clock updateClock;
    while(motor->openWindow()){
        
        motor->clearWindow();
        
        escena->HandleInput();
        if((updateClock.getSeconds()*1000)>UPDATE_TICK_TIME){
            escena->Update();
            updateClock.reset();
        }
        float percentTick=fmin(1,(updateClock.getSeconds()*1000)/(UPDATE_TICK_TIME));
        
        escena->Draw(percentTick);
        motor->displayWindow();
    }
    
}

void Game::init(){

    
}



void Game::update(){
    
    
}


void Game::setState(state* escena)
{
    this->escena = escena;
    std::cout << "Hacemos el Init() de la escena" << std::endl;
    
}