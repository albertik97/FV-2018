
#include "Motor2D.h"
#include "Game.h"

#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>

Motor2D* Motor2D::pinstance =0;
Motor2D* Motor2D::Instance()
{
    if(pinstance==0){
        pinstance= new Motor2D();
    }
    
    return pinstance;
}

Motor2D::Motor2D()
:window(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "Evohungry", sf::Style::Close  | sf::Style::Titlebar /*| sf::Style::Fullscreen*/)
{
     
}


void Motor2D::dibujar(sf::Sprite a){
    window.draw(a);
  
}
void Motor2D::dibujar(sf::RectangleShape shape)
{
    window.draw(shape);
}

void Motor2D::dibujarTexto(sf::Text t){
 
    window.draw(t);
}

bool Motor2D::openWindow(){
    window.isOpen();
    
}

void Motor2D::clearWindow(){
    
    window.clear();
}

void Motor2D::displayWindow(){
    
    window.display();
    
}

void Motor2D::closeWindow(){   
    window.close();
}

void Motor2D::setCamera(Camera cam)
{
    window.setView(cam.getView());
}

void Motor2D::setFrameLimit()
{
    window.setFramerateLimit(60);
}

void Motor2D::resetCamera()
{
    window.setView(window.getDefaultView());
}

sf::RenderWindow* Motor2D::getWindow()
{
    return &window;
}