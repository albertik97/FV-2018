

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
    : endGame(false)
{
    std::cout << "Esto deberia salir al crearse la escena de ingame" << std::endl;
    //j = Game::Instance();
    this->Init();
}
void ingame_state::Init()
{
     srand(time(0));
   mapa.cargarmapa("nivel1.tmx");
   //mouse.initMouse("resources/mira.png",0.1,0.1);
   //colocamos los enemigos

   for(int i=0; i<22; i++){  
      Enemy* e = new Enemy();
      e->chargingTexture();
      e->setPosRandom(mapa._tilemap);
      enemys.push_back(e);
           
    }
    player = new Player();
    player->chargingTexture();
    
    camera.setCenter(player->getPositionX(), player->getPositionY());
    camera.setSize(1920, 1080);
    
    Motor2D::Instance()->setCamera(camera);
    
    for(int i=0; i<60; i++){  
      Food* comida = new Food();
      comidaArray.push_back(comida);
      comidaArray[i]->setRandomFood(mapa._tileMapSprite);
           
    }
   colision.setPlayer(player);
   hud.cargarhud(2);
//   colision.setFood(comidaArray);
   
   fondoTransition.setSize(WINDOW_WIDTH * 2, WINDOW_HEIGHT * 2);
   fondoTransition.setColor(0, 0, 0);
   fondoTransition.setOriginCenter();
   fondoTransition.setPos(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
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
                endGame = true;
                //Motor2D::Instance()->resetCamera();
               // Game::instance()->setState(menu_state::Instance());
                               
            }
            if(Keyboard::isKey1Pressed()){
                //for(int i=0;i<enemys.size();i++)
                   // enemys[i]->changeStrategy(new IAActiva());
            }
             if(Keyboard::isKey2Pressed()){
                for(int i=0;i<enemys.size();i++)
                    enemys[i]->changeStrategy(new IAPasiva());
            }
            player->input();
        }
}
void ingame_state::Update()
{
   if(gameStart.getSeconds() < 6)
    {
        endAlpha();
    }
    //std::cout << fondoTransition.getAlpha() << std::endl;
    if(endGame)
    {
        beginAlpha();
    }
    if(endGame && fondoTransition.getAlpha() == 255)
    {
        endGame = false;
        Motor2D::Instance()->resetCamera();
        Game::instance()->setState(menu_state::Instance());
    }
    if(fondoTransition.getAlpha() == 255)
    {
        gameStart.reset();
    }

     player->update();
    //mouse.CursorUpdate();
    for(int i=0;i<enemys.size();i++)
        enemys[i]->update();
    if(colision.checkColisionComida(comidaArray))
        hud.sumaexp(player->getExperiencia());
    for(int i=0;i<comidaArray.size();i++)
        comidaArray[i]->update();
    camera.setCenter(player->getPositionX(), player->getPositionY());
    Motor2D::Instance()->setCamera(camera);
    hud.updateHud(player->getPositionX(),player->getPositionY());

}
void ingame_state::Draw()
{       mapa.setCapaActiva(0);
        Motor2D::Instance()->getWindow()->draw(mapa);
        mapa.setCapaActiva(1);
        Motor2D::Instance()->getWindow()->draw(mapa);
            mapa.setCapaActiva(2);
        Motor2D::Instance()->getWindow()->draw(mapa);
          for(int i=0; i<comidaArray.size(); i++){
            comidaArray[i]->getSprite()->draw();
        }
        for(int i=0;i<enemys.size();i++)
            enemys[i]->draw();

        player->draw();
        //mouse.getCursorSprite()->draw();

        hud.draw();
        if(fondoTransition.getAlpha() != 0)
            fondoTransition.draw();
        

       

}

Player* ingame_state::getPlayer(){
    return player;

}

std::vector<Food*> ingame_state::getComida(){
    return comidaArray;

}

void ingame_state::beginAlpha()
{
    fondoTransition.setPos(player->getPositionX(), player->getPositionY());
    int alpha = fondoTransition.getAlpha() + (INTRO_STATE_TRANSITION_SPEED * 2);
    
    if(alpha >= 255)
    {
        alpha = 255;
    }
    fondoTransition.setAlpha(alpha);
}
void ingame_state::endAlpha()
{
    fondoTransition.setPos(player->getPositionX(), player->getPositionY());
    int alpha = fondoTransition.getAlpha() - (INTRO_STATE_TRANSITION_SPEED * 2);
        
    if(alpha <= 0)
    {
        alpha = 0;
    }
    /*for(int i = 0; i < 4; i++)
    {
        b[i].getFondoButton()->setAlpha(alpha);
        b[i].getTextButton()->setAlpha(alpha);
    }*/
    fondoTransition.setAlpha(alpha);
}