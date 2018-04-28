
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
    Motor2D::Instance()->resetCamera();
    
    /*menu[0].setPos(Motor2D::Instance()->getWindow()->getSize().x/2,Motor2D::Instance()->getWindow()->getSize().y*0.5);
    menu[0].setColor(255,255,255);
    menu[0].setText("Jugar");
    menu[0].setSize(50);
    menu[0].setOriginCenter();
    
    
    menu[1].setPos(Motor2D::Instance()->getWindow()->getSize().x/2,Motor2D::Instance()->getWindow()->getSize().y*0.6);
    menu[1].setColor(255,0,0);
    menu[1].setText("Opciones");
    menu[1].setSize(50);
    menu[1].setOriginCenter();
   
    
    menu[2].setPos(Motor2D::Instance()->getWindow()->getSize().x/2,Motor2D::Instance()->getWindow()->getSize().y*0.7);
    menu[2].setColor(255,0,0);
    menu[2].setText("Creditos");
    menu[2].setSize(50);
    menu[2].setOriginCenter();
  
    std::cout<<Motor2D::Instance()->getWindow()->getSize().y<<std::endl;
    menu[3].setPos(Motor2D::Instance()->getWindow()->getSize().x/2,Motor2D::Instance()->getWindow()->getSize().y*0.8);
    menu[3].setColor(255,0,0);
    menu[3].setText("Salir");
    menu[3].setSize(50);
    menu[3].setOriginCenter();*/
    
    b[0].getFondoButton()->setSize(200, 50);
    b[0].getFondoButton()->setTextureRect(100, 90);
    b[0].getFondoButton()->setOutlineThickness(5.f);
    b[0].getFondoButton()->setOutlineColor(25, 25, 25);
    b[0].getFondoButton()->setTexture(WOOD_TEXTURE_FILEPATH);
    b[0].getFondoButton()->setOriginCenter();
    b[0].getFondoButton()->setPos(0, WINDOW_HEIGHT / 2);
    
    
    b[0].getTextButton()->setText("Play");
    b[0].getTextButton()->setSize(20);
    b[0].getTextButton()->setColor(255, 222, 173);
    
    b[0].getTextButton()->setOriginCenter();
    b[0].getTextButton()->setPos(0, 540.f);
    
    
    b[1].getFondoButton()->setSize(200, 50);
    b[1].getFondoButton()->setTextureRect(100, 90);
    b[1].getFondoButton()->setOutlineThickness(5.f);
    b[1].getFondoButton()->setOutlineColor(25, 25, 25);
    b[1].getFondoButton()->setTexture(WOOD_TEXTURE_FILEPATH);
    b[1].getFondoButton()->setOriginCenter();
    b[1].getFondoButton()->setPos(0, (WINDOW_HEIGHT / 2) * 1.15);
    b[1].getTextButton()->setText("Options");
    b[1].getTextButton()->setSize(20);
    b[1].getTextButton()->setColor(255, 222, 173);
    
    b[1].getTextButton()->setOriginCenter();
    b[1].getTextButton()->setPos(0, (WINDOW_HEIGHT / 2) * 1.15);
    
    
    b[2].getFondoButton()->setSize(200, 50);
    b[2].getFondoButton()->setTextureRect(100, 90);
    b[2].getFondoButton()->setOutlineThickness(5.f);
    b[2].getFondoButton()->setOutlineColor(25, 25, 25);
    b[2].getFondoButton()->setTexture(WOOD_TEXTURE_FILEPATH);
    b[2].getFondoButton()->setOriginCenter();
    b[2].getFondoButton()->setPos(0, (WINDOW_HEIGHT / 2) * 1.3);
    b[2].getTextButton()->setText("Credits");
    b[2].getTextButton()->setSize(20);
    b[2].getTextButton()->setColor(255, 222, 173);
    
    b[2].getTextButton()->setOriginCenter();
    b[2].getTextButton()->setPos(0, (WINDOW_HEIGHT / 2) * 1.3);
    
    
    
    b[3].getFondoButton()->setSize(200, 50);
    b[3].getFondoButton()->setTextureRect(100, 90);
    b[3].getFondoButton()->setOutlineThickness(5.f);
    b[3].getFondoButton()->setOutlineColor(25, 25, 25);
    b[3].getFondoButton()->setTexture(WOOD_TEXTURE_FILEPATH);
    b[3].getFondoButton()->setOriginCenter();
    b[3].getFondoButton()->setPos(0, (WINDOW_HEIGHT / 2) * 1.45);
    b[3].getTextButton()->setText("Exit");
    b[3].getTextButton()->setSize(20);
    b[3].getTextButton()->setColor(255, 222, 173);
    
    b[3].getTextButton()->setOriginCenter();
    b[3].getTextButton()->setPos(0, (WINDOW_HEIGHT / 2) * 1.45);
  

    selector.setSpriteTexture(SELECTOR_SPRITE_FILEPATH);
    selector.setPosition(WINDOW_WIDTH / 2.6, WINDOW_HEIGHT / 2.15);
    
    fondo.setSpriteTexture(MENU_STATE_BACKGROUND_FILEPATH);
    fondo.setAlpha(0);
    mouse.initMouse("resources/pointer.png",0.1,0.1);
    selected = 0;
    
    //Motor2D::Instance()->getWindow()->setMouseCursorVisible(false);
    
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
            if(menuStart.getSeconds() >= INTRO_STATE_TRANSITION_TIME-0.75)
            switch(selected){
                case 0:
                    if(Keyboard::isKeyEnterPressed() || Mouse::LeftPressed() && b[0].getColision(Mouse::getPosX(),Mouse::getPosY())){
                        std::cout << "Nos pasamos a la escena de juego" << std::endl;
                        if(World::Instance()->getEndGame())
                        {
                            World::Instance()->resetWorld();
                            World::Instance()->setEndGame(false);
                            World::Instance()->CargarNivel(1);
                        }
                            
                        Game::instance()->setState(ingame_state::instance());
                    }
                    break;
                case 1:
                    if(Keyboard::isKeyEnterPressed() || Mouse::LeftPressed() && b[1].getColision(Mouse::getPosX(),Mouse::getPosY())){
                        std::cout << "Segunda opcion" << std::endl;
                        Game::instance()->setState(options_state::Instance());
                    }
                    
                    break;
                case 2: 
                    
                    if(Keyboard::isKeyEnterPressed() || Mouse::LeftPressed() && b[2].getColision(Mouse::getPosX(),Mouse::getPosY())){
                       std::cout << "Tercera opcion" << std::endl;
                       Game::instance()->setState(credits_state::Instance());
                    }                  
                    
                    break;
                case 3: 
                    if(Keyboard::isKeyEnterPressed() || Mouse::LeftPressed() && b[3].getColision(Mouse::getPosX(),Mouse::getPosY())){
                        std::cout << "Nos salimos del juego" << std::endl;
                        Motor2D::Instance()->closeWindow();
                    }
                    
                    
                    break;
            }
                       
                
            
            if(Keyboard::isKeyUpPressed() && menuStart.getSeconds() >= INTRO_STATE_TRANSITION_TIME-0.75)
                Up();
            
             if(Keyboard::isKeyDownPressed() && menuStart.getSeconds() >= INTRO_STATE_TRANSITION_TIME-0.75)
                Down();
              for(int i=0;i<4; i++){
                if(b[i].getColision(Mouse::getPosX(),Mouse::getPosY())){
                        //menu[i].setColor(255,255,255);
                    int res = i - selected;
                    selector.setPosition(selector.getPosition().x,  selector.getPosition().y + (WINDOW_HEIGHT / 2) * (0.15 * res));
                    selected=i;
                }
              }
        }
}
void menu_state::Update()
{
    //std::cout << "se esta actualizando" << std::endl;
    Motor2D::Instance()->resetCamera();
    
    
           
            for(int i=0;i<4; i++){
                if(i!=selected)
                    menu[i].setColor(255,0,0);
            }            
            mouse.CursorUpdate(0, 0);//se actualiza el sprite a la posicion del raton
            std::cout << World::Instance()->getEndGame() << std::endl;
            
}
void menu_state::Draw(float percentTick)
{   
    if(menuStart.getSeconds() < INTRO_STATE_TRANSITION_TIME) 
    {
        beginAlpha(percentTick);
        for(int i = 0; i < 4; i++)
        {
            if(b[i].getTextButton()->getText().getPosition().x < (WINDOW_WIDTH / 2.f))
            {
                b[i].getFondoButton()->setPos(b[i].getFondoButton()->getShape().getPosition().x + 20, b[i].getFondoButton()->getShape().getPosition().y);
                b[i].getTextButton()->setPos(b[i].getTextButton()->getText().getPosition().x + 20, b[i].getTextButton()->getText().getPosition().y);
            }
        }
    }
    fondo.draw();
    selector.draw();
    for(int i=0;i<4;i++){
        b[i].draw();
            
        }

    mouse.getCursorSprite()->draw();
  
}

void menu_state::Up()
{
    if(selected-1 >= 0){
       // menu[selected].setColor(255,0,0);
        selected--;
        //menu[selected].setColor(255,255,255);
        selector.setPosition(selector.getPosition().x,  selector.getPosition().y - (WINDOW_HEIGHT / 2) * 0.15);
    }
}

void menu_state::Down()
{
    if(selected+1 <4){
        //menu[selected].setColor(255,0,0);
        selected++;
        //menu[selected].setColor(255,255,255);
        selector.setPosition(selector.getPosition().x,  selector.getPosition().y + (WINDOW_HEIGHT / 2) * 0.15);
    }
}


void menu_state::beginAlpha(float percentTick)
{
    int alpha = fondo.getAlpha() + INTRO_STATE_TRANSITION_SPEED;
    
    if(alpha >= 255)
    {
        alpha = 255;
    }
    /*for(int i = 0; i < 4; i++)
    {
        b[i].getFondoButton()->setAlpha(alpha);
        b[i].getTextButton()->setAlpha(alpha);
    }*/
    fondo.setAlpha(alpha);
}
void menu_state::endAlpha(float percentTick)
{
    int alpha = fondo.getAlpha() - (INTRO_STATE_TRANSITION_SPEED);
        
    if(alpha <= 0)
    {
        alpha = 0;
    }
    for(int i = 0; i < 4; i++)
    {
        b[i].getFondoButton()->setAlpha(alpha);
        b[i].getTextButton()->setAlpha(alpha);
    }
    fondo.setAlpha(alpha);
}