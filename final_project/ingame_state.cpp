

#include "ingame_state.h"
#include "Motor2D.h"
#include "tinystr.h"
#include "tinyxml.h"
#include "IAPasiva.h"
#include "IAActiva.h"
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
    //j = Game::Instance();
    this->Init();
}
void ingame_state::Init()
{
     srand(time(0));
   mapa.cargarmapa();
   mouse.initMouse("resources/mira.png",0.1,0.1);
   //colocamos los enemigos
   for(int i=0;i<10;i++){
      enemys[i]=new Enemy();
      enemys[i]->chargingTexture();
      enemys[i]->setPosRandom();
   }
    player = new Player();
    player->chargingTexture();
    
    for(int i=0; i<10; i++){  
      Food* comida = new Food();
      comidaArray.push_back(comida);
      comidaArray[i]->setRandomFood();
           
    }
   colision.setPlayer(player);
//   colision.setFood(comidaArray);
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
            if(Keyboard::isKey1Pressed()){
                for(int i=0;i<10;i++)
                    enemys[i]->changeStrategy(new IAActiva());
            }
             if(Keyboard::isKey2Pressed()){
                for(int i=0;i<10;i++)
                    enemys[i]->changeStrategy(new IAPasiva());
            }
            player->input();
        }
}
void ingame_state::Update()
{
   

    player->update();
    mouse.CursorUpdate();
    for(int i=0;i<10;i++)
        enemys[i]->update();
    colision.checkColisionComida(comidaArray);

}
void ingame_state::Draw()
{       
        //texto.draw();
        Motor2D::Instance()->getWindow()->draw(mapa);
          for(int i=0; i<comidaArray.size(); i++){
            comidaArray[i]->getSprite()->draw();
        }
        for(int i=0;i<10;i++)
            enemys[i]->draw();

        player->getSprite()->draw();
        mouse.getCursorSprite()->draw();
       
 
}