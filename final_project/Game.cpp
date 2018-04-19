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
#include "Food.h"
#include "Motor2D.h"

#include  <iostream>



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
    while(motor->openWindow()){
        
        motor->clearWindow();
        
        escena->HandleInput();
        escena->Update();
        escena->Draw();
        motor->displayWindow();
    }
    
}

void Game::init(){
    prueba = new Food();
    
}



void Game::update(){
    
    
}


void Game::setState(state* escena)
{
    this->escena = escena;
    std::cout << "Hacemos el Init() de la escena" << std::endl;
    
}