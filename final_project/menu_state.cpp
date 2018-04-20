/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   menu_state.cpp
 * Author: blanca
 * 
 * Created on 17 de abril de 2018, 20:21
 */


#include "menu_state.h"
#include "Sprite.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Motor2D.h"
#include "Text.h"
#include "options_state.h"
#include "credits_state.h"

menu_state* menu_state::pinstance = 0;
menu_state* menu_state::Instance()
{
    if(pinstance == 0)
    {
        pinstance = new menu_state;
    }
    return pinstance;
}
menu_state::menu_state()
{
    this->Init();
    std::cout << "Esto deberia de salir al crear el menu en el main" << std::endl;
}
void menu_state::Init()
{
    std::cout << "Entramos al Init()" << std::endl;
    
    menu[0].setPos(Motor2D::Instance()->getWindow()->getSize().x*0.04,Motor2D::Instance()->getWindow()->getSize().y*0.2);
    menu[0].setColor(255,255,255);
    menu[0].setText("Jugar");
    menu[0].setSize(40);
    
    
    menu[1].setPos(Motor2D::Instance()->getWindow()->getSize().x*0.04,Motor2D::Instance()->getWindow()->getSize().y*0.3);
    menu[1].setColor(255,0,0);
     menu[1].setText("Opciones");
    menu[1].setSize(40);
   
    
    menu[2].setPos(Motor2D::Instance()->getWindow()->getSize().x*0.04,Motor2D::Instance()->getWindow()->getSize().y*0.4);
    menu[2].setColor(255,0,0);
      menu[2].setText("Creditos");
    menu[2].setSize(40);
  
    
    menu[3].setPos(Motor2D::Instance()->getWindow()->getSize().x*0.04,Motor2D::Instance()->getWindow()->getSize().y*0.5);
    menu[3].setColor(255,0,0);
    menu[3].setText("Salir");
    menu[3].setSize(40);
  

    
    fondo.setSpriteTexture("resources/fondo.png");
//    mouse.setTexture("resources/pointer.png");
    
    selected=0;
    
    Motor2D::Instance()->getWindow()->setMouseCursorVisible(false);
    
}
void menu_state::HandleInput()
{
    
        sf::Event evento;
        while(Motor2D::Instance()->getWindow()->pollEvent(evento))
        {
            if(Keyboard::isKeyWPressed()) 
                Motor2D::Instance()->closeWindow();
           // if(evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::F5)
            //    Game::Instance()->ToogleFullscreen();
            
            switch(selected){
                case 0:
                    if(Keyboard::isKeyEnterPressed() || Mouse::LeftPressed() && menu[0].getColision(Mouse::getPosX(),Mouse::getPosY())){
                        std::cout << "Nos pasamos a la escena de juego" << std::endl;
                        Game::instance()->setState(ingame_state::instance());
                    }
                    break;
                case 1:
                    if(Keyboard::isKeyEnterPressed() || Mouse::LeftPressed() && menu[1].getColision(Mouse::getPosX(),Mouse::getPosY())){
                        std::cout << "Segunda opcion" << std::endl;
                        Game::instance()->setState(options_state::Instance());
                    }
                    
                    break;
                case 2: 
                    
                    if(Keyboard::isKeyEnterPressed() || Mouse::LeftPressed() && menu[2].getColision(Mouse::getPosX(),Mouse::getPosY())){
                       std::cout << "Tercera opcion" << std::endl;
                       Game::instance()->setState(credits_state::Instance());
                    }
                    
                    
                    break;
                case 3: 
                    if(Keyboard::isKeyEnterPressed() || Mouse::LeftPressed() && menu[3].getColision(Mouse::getPosX(),Mouse::getPosY())){
                        std::cout << "Nos salimos del juego" << std::endl;
                        Motor2D::Instance()->closeWindow();
                    }
                    
                    
                    break;
            }
                       
                
            
            if(Keyboard::isKeyUpPressed())
                Up();
            
             if(Keyboard::isKeyDownPressed())
                Down();
              for(int i=0;i<4; i++){
                if(menu[i].getColision(Mouse::getPosX(),Mouse::getPosY())){
                        menu[i].setColor(255,255,255);
                        selected=i;
                }
              }
        }
}
void menu_state::Update()
{
    //std::cout << "se esta actualizando" << std::endl;
        
    
           
            for(int i=0;i<4; i++){
                if(i!=selected)
                    menu[i].setColor(255,0,0);
            }            
            mouse.CursorUpdate();//se actualiza el sprite a la posicion del raton
            
}
void menu_state::Draw()
{   
    fondo.draw();
    for(int i=0;i<4;i++){
        menu[i].draw();
            
        }

    mouse.getCursorSprite()->draw();
  
}

void menu_state::Up()
{
    if(selected-1 >= 0){
       // menu[selected].setColor(255,0,0);
        selected--;
        menu[selected].setColor(255,255,255);
    }
}

void menu_state::Down()
{
    if(selected+1 <4){
        //menu[selected].setColor(255,0,0);
        selected++;
        menu[selected].setColor(255,255,255);
    }
}