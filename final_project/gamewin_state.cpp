
#include "World.h"
#include "menu_state.h"
#include "Keyboard.h"
#include "Sprite.h"
#include "Motor2D.h"
#include "gamewin_state.h"

gamewin_state* gamewin_state::pinstance = 0;
gamewin_state* gamewin_state::Instance()
{
    if(pinstance == 0)
    {
        pinstance = new gamewin_state;
    }
    return pinstance;
}
gamewin_state::gamewin_state(){
    this->Init();
}
void gamewin_state::Init()
{

    fondo.setSpriteTexture("resources/you-win.jpg");
   
    fondo.setPosition(0.f, 0.f);

}
void gamewin_state::HandleInput()
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
void gamewin_state::Update()
{

}
void gamewin_state::Draw(float percentTick)
{      
    fondo.draw();
}
