
#include <SFML/Window/Keyboard.hpp>

#include "transition_state.h"
#include <iostream>
#include <sstream>


transition_state* transition_state::pinstance = 0;
transition_state* transition_state::Instance()
{
    if(pinstance == 0)
    {
        pinstance = new transition_state;
    }
    return pinstance;
}


transition_state::transition_state() 
{
    this->Init();
}

void transition_state::Init()
{

 for(int i=0;i<4;i++){
     text[i].setColor(255,255,0);
     text[i].setSize(30);
     text[i].setOriginCenter();
 }   
 text[0].setPos(WINDOW_WIDTH*0.2,WINDOW_HEIGHT * 0.4);
 text[1].setPos(WINDOW_WIDTH*0.2,WINDOW_HEIGHT * 0.5);
 text[2].setPos(WINDOW_WIDTH*0.2,WINDOW_HEIGHT * 0.6);
 text[3].setPos(WINDOW_WIDTH*0.1,WINDOW_HEIGHT * 0.9);
  std::stringstream ss,ss2;
    ss<<World::Instance()->getPlayer()->getVerdura();
    std::string str=ss.str();
 text[0].setText("Verdura obtenida: "+str);
  ss2<<World::Instance()->getPlayer()->getCarne();
    std::string str2=ss2.str();
 text[1].setText("Carne obtenida: "+str2);
 text[2].setText("Has evolucionado a...");
 text[3].setText("Presiona \"espacio\" para continuar al siguiente nivel");
 if(World::Instance()->getPlayer()->getCarne()>World::Instance()->getPlayer()->getVerdura())
        img.setSpriteTexture("resources/carnivoro1.png");
 else
        img.setSpriteTexture("resources/herbivoro2.png");
     
 
 img.setTextureRect(0,0,101,101);
   img.setOrigin(101/2,101/2);
   img.scale(3.5, 3.5);
   img.setPosition(1350, 500);
   
}

void transition_state::HandleInput()
{
    sf::Event event;
    while(Motor2D::Instance()->getWindow()->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            Motor2D::Instance()->closeWindow();
        }
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
        {
           // World::Instance()->resetWorld();
            World::Instance()->CargarNivel(2);
            Game::instance()->setState(ingame_state::instance());
        }
    }
}

void transition_state::Update()
{
    
}

void transition_state::Draw(float percentTick)
{
    for(int i=0;i<4;i++){
        text[i].draw();
    }
    img.draw();
}




