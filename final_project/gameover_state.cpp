/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "gameover_state.h"
#include "World.h"
#include "menu_state.h"
#include "Keyboard.h"
#include "Sprite.h"
#include "Motor2D.h"



gameover_state* gameover_state::pinstance = 0;
gameover_state* gameover_state::Instance()
{
    if(pinstance == 0)
    {
        pinstance = new gameover_state;
    }
    return pinstance;
}
gameover_state::gameover_state(){
    this->Init();
}
void gameover_state::Init()
{

    fondo.setSpriteTexture("resources/gameover.jpg");
   
    fondo.setPosition(0.f, 0.f);

}
void gameover_state::HandleInput()
{
    sf::Event evento;
        while(Motor2D::Instance()->getWindow()->pollEvent(evento))
        {
            if(Keyboard::isKeyWPressed()) {
                Motor2D::Instance()->closeWindow();
            // if(evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::F5)
            //    Game::Instance()->ToogleFullscreen();
            }
            if(Keyboard::isKeyEnterPressed()){
                //World::Instance()->resetWorld();
                World::Instance()->setEndGame(true);
                Game::instance()->setState(menu_state::Instance());
            }
        }
}
void gameover_state::Update()
{

}
void gameover_state::Draw(float percentTick)
{      
    fondo.draw();
}

