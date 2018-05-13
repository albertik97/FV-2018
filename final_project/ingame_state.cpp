

#include "ingame_state.h"
#include "Motor2D.h"
#include "tinystr.h"
#include "tinyxml.h"

#include "Keyboard.h"
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
    this->Init();
}
void ingame_state::Init()
{
    mundo = World::Instance();
    mundo->CargarNivel(1);
   std::cout<<"He hecho el init de ingame"<<std::endl;
}

void ingame_state::HandleInput()
{
     sf::Event evento;
        while(Motor2D::Instance()->getWindow()->pollEvent(evento))
        {
            if(evento.type == sf::Event::Closed)
               Motor2D::Instance()->getWindow()->close();
            if(evento.type == sf::Event::KeyPressed && Keyboard::isKeyEscPressed())
                Game::instance()->setState(menu_state::Instance());
            if(evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Return)
            {
                World::Instance()->setEndGame(true);
            }
            
            if(evento.type == sf::Event::KeyPressed && Mouse::LeftPressed())
            {
                
                //ataque basico
            }
            if(Mouse::RightPressed())
            {
                //Mirar que habilidad hay seleccionada
                switch(World::Instance()->getPlayer()->getHabilidad())
                {
                    case 1: World::Instance()->getPlayer()->lanzarHabilidadUno();
                        break;
                    case 2: World::Instance()->getPlayer()->lanzarHabilidadDos();
                        break;
                    case 3: World::Instance()->getPlayer()->lanzarHabilidadTres();
                        break;
                    default:
                        break;
                }
            }
            
            if(!Mouse::RightPressed()){
                World::Instance()->getPlayer()->setVelocidad(10);
            }
        }
     mundo->getPlayer()->input();
}


void ingame_state::Update()
{
  
    mundo->Update();
    
    
}
void ingame_state::Draw(float percentTick)
{       
    mundo->Draw(percentTick);
}
