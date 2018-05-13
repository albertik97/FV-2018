#include "Player.h"
#include <iostream>
#include <math.h>  
#include "Motor2D.h"
#include "Sprite.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "ingame_state.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>




Player::Player() 
    : movX(0), movY(0) ,kVel(20)
{
    
    sprite = new Sprite();
    lengua = new Sprite();
    lengua->setSpriteTexture("resources/Lengua.png");
    lengua->setOrigin(10,-40);
  
    x = 1920 / 2;
    y = 1080 / 2;
    xlast = 1920 / 2;
    ylast = 1080 / 2;
    up = false;
    left = false;
    down = false;
    right = false;

    habuno = true;
    habdos = false;
    habtres = false;
    h1 = false;
    h2 = false;
    h3 = false;

    exp=0;
    carne=0;
    verdura=0;

    eliminoComida = 0;
    vida=100;
    mouse= new Mouse();
    mouse->initMouse("resources/mira.png",0.1,0.1);
    mouse->getCursorSprite()->setPosition(x+50, y+50);

    energia = 1;
    
    tipoPlayer = 0;
    tam=150;
    estado_lengua=false;

}

void Player::cambiarSprite(std::string s){
        sprite->setSpriteTexture(s);                              // Y creo el spritesheet a partir de la imagen anterior
        sprite->setTextureRect(1,1, 100, 105);
	sprite->setOrigin(100/2,105/2);
        sprite->scale(0.8,0.8);
        sprite->setPosition(1160,860);
        x = 1160;
        y = 860;
        xlast = 1160;
        ylast = 860;
        
}
int Player::getVida(){
    return vida;
}

void Player::anyadirRaton(){
    mouse= new Mouse();
    mouse->initMouse("resources/mira.png",0.1,0.1);
}

void Player::restaVida(){
    if(vida>=10)
         vida-=10;
}

void Player::aumentaVida(){
    if(vida<=95)
         vida+=5;
}
void Player::aumenteCarne(){
    carne++;
}
void Player::aumentaVerdura(){
    verdura++;
}

int Player::getTipo(){
    return tipoPlayer;
}

void Player::setTipo(int i){
    tipoPlayer=i;
}

int Player::getCarne(){
    return carne;
}

int Player::getVerdura(){
    return verdura;
}

void Player::setExperiencia(int e){
    exp+=e;
}
void Player::chargingTexture() {
	
	sprite->setSpriteTexture("resources/spritesheet.png");                              // Y creo el spritesheet a partir de la imagen anterior
        sprite->setTextureRect(7,1, 112, 173);
	sprite->setOrigin(112/2,173/2);
        sprite->scale(0.5,0.5);
	sprite->setPosition(x, y);                               // Lo dispongo en el centro de la pantalla                            // Lo dispongo en el centro de la pantalla
}
int Player::getExperiencia(){
    return exp;
}

void Player::draw() {
    sprite->draw();
    mouse->getCursorSprite()->draw();
    lengua->draw();
    
}

void Player::aumentaEnergia(float _tiempo){
    if(static_cast<int>(_tiempo)%2 == 0 && energia < maxenergia){
        energia++;
    }
}

float Player::getEnergia(){
    return energia;
}

void Player::input(){
        
   // if(sf::Event::KeyPressed){

                    if(Keyboard::isKeyDPressed()){				
                            
                        right = true;
                    }
                    
                    if(Keyboard::isKeyAPressed()){
                        
                        left=true;
                        
                    }
                    
                    if(Keyboard::isKeyWPressed()){
                        
                        up=true;
                    }
                    
                    if(Keyboard::isKeySPressed()){
                        
                        down=true;
                    }
                    
                    if(Keyboard::isKey1Pressed()){
                        habuno = true;
                         habdos = false;
                         habtres = false;
                       // std::cout << "HABILIDAD 1" << std::endl;
                    }
                    
                    if(Keyboard::isKey2Pressed()){
                        habuno = false;
                        habdos = true;
                        habtres =false;
                        //std::cout << "HABILIDAD 2" << std::endl;
                    }
                    
                    if(Keyboard::isKey3Pressed()){
                        habuno = false;
                        habdos = false;
                        habtres = true;
                        //std::cout << "HABILIDAD 3" << std::endl;
                    }
	
                    if(!Keyboard::isKeyDPressed()){				

                        right = false;
                    }
                    
                    if(!Keyboard::isKeyAPressed()){
                        
                        left=false;
                        
                    }
                    
                    if(!Keyboard::isKeyWPressed()){
                        
                        up=false;
                    }
                    
                    if(!Keyboard::isKeySPressed()){
                        
                        down=false;
                    }
}

int Player::getHabilidad(){
    int numHabilidad = 0;
    
    if(habuno){
        numHabilidad = 1;
    } 
    
    if(habdos){
        numHabilidad = 2;
    }
    
    if(habtres){
        numHabilidad = 3;
    }
   
    return numHabilidad;
}



void Player::lookAtMouse(){
    
    sf::Vector2f curPos = sprite->getPosition();
    //(std::cout<<sprite->getPosition().x;
    //std::cout<<sprite->getPosition().y;
    sf::Vector2f position(mouse->getCursorSprite()->getPosition().x, mouse->getCursorSprite()->getPosition().y); 
    const float PI = 3.14159265;
    float dx = curPos.x - position.x;
    float dy = curPos.y - position.y;
    rotation = (atan2(dy, dx)) * 180 / PI;
    sprite->rotate(rotation-90);

}



void Player::update(){
         ylast=y;
         xlast=x;
       moveChar();
       mouse->CursorUpdate(movX, movY);
       lookAtMouse();
       if(tipoPlayer==0)
            sprite->animar(7,1, 112, 173, 134);
       else if(tipoPlayer==1){
           sprite->animar(1,1, 100, 105, 100);
       }else{
           sprite->animar(1,1, 100, 105, 100);
       }
       if(!left && !right && !up && !down){
           if(tipoPlayer==0){
             sprite->setAnimationTime(500);  
           } 
            if(tipoPlayer==1){
                sprite->setAnimationTime(0);
            }
            if(tipoPlayer==2){
                sprite->setAnimationTime(200);
            }
        }
       
       if(h1){
            kVel=0;     
            if(tam>=0){
                tam-=20;
                 estado_lengua=true;
            }else if(!estado_lengua&&tam<=149){               
                tam+=15;
              
           }else{
               tam=0;      
               kVel=5;
               h1=false;
               estado_lengua=false;
           }
        
        lengua->setTextureRect(0, 0,23.0,tam);
        lengua->getSprite()->setRotation(rotation+90);
        lengua->setPosition(sprite->getPosition().x,sprite->getPosition().y);
       }
}

void Player::moveChar(){
    
	if(left || right){
            moveX();
        }
        
        
        
        if(up || down){
            moveY();
        }
}

void Player::setVelocidad(int v){
    kVel = v;
}

void Player::moveX(){
if(left){
       
        if(!checkColisionMap(-kVel, 0)){
            movX += -kVel;
             sprite->moving(-kVel, 0);
             sprite->setAnimationTime(100);
             x -= kVel;
        }
             
    }
    if(right){
        
         if(!checkColisionMap(kVel, 0)){
             movX += kVel;
            sprite->moving(kVel, 0);
            sprite->setAnimationTime(100);
            x += kVel;
         }
    }
       
}

void Player::moveY(){
    if(up){
           
             if(!checkColisionMap(0, -kVel)){
            movY += -kVel;
            sprite->moving(0, -kVel);
            sprite->setAnimationTime(100);
             y -= kVel;
             }
    }
    if(down){
           
            if(!checkColisionMap(0, +kVel)){
            movY += kVel;
             sprite->moving(0, kVel);
             sprite->setAnimationTime(100);
             y += kVel;
            }
    }
}

bool Player::checkColisionMap(int x, int y){
    
    //COJO LAS CUATRO ESQUINAS DEL BOUNDING BOX  
    
    float left = World::Instance()->getPlayer()->getSprite()->getSprite()->getGlobalBounds().left+15 + x;
    float top = World::Instance()->getPlayer()->getSprite()->getSprite()->getGlobalBounds().top+15 + y;
    float right = World::Instance()->getPlayer()->getSprite()->getSprite()->getGlobalBounds().width-60 + left;
    float down = top + World::Instance()->getPlayer()->getSprite()->getSprite()->getGlobalBounds().height-60;

    
    if(World::Instance()->getMapa()._tilemap[1][(int)top/32][(int)left/32]==0 &&
      World::Instance()->getMapa()._tilemap[1][(int)top/32][(int)right/32]==0 &&
      World::Instance()->getMapa()._tilemap[1][(int)down/32][(int)left/32]==0 &&
      World::Instance()->getMapa()._tilemap[1][(int)down/32][(int)right/32]==0){
        
        return false;
   
    }
    return true;
    
}

Sprite* Player::getSprite(){
    return sprite;
}

Mouse* Player::getMouse()
{
    return mouse;
}

float Player::getPositionX()
{
    return x;
}

float Player::getPositionY()
{
    return y;
}

void Player::setPositionInterpolated(float a,float b){
    sprite->setPosition(a,b);
}

float Player::getLastPositionX()
{
    return xlast;
}

float Player::getLastPositionY()
{
    return ylast;
}


void Player::lanzarHabilidadUno()
{
    if(tipoPlayer == 2)
    {
        std::cout << "Lanzamos la habilidad 1 del herbivoro" << std::endl;
        
    }
    if(tipoPlayer == 1)
    {
        std::cout << "Lanzamos la habilidad 1 del carnivoro" << std::endl;
        // Lanzamos la habilidad 1 del carnivoro
        h1 = true;
    }
}
void Player::lanzarHabilidadDos()
{
    if(tipoPlayer == 2)
    {
        std::cout << "Lanzamos la habilidad 2 del herbivoro" << std::endl;
        // Lanzamos la habilidad 2 del herbivoro
    }
    if(tipoPlayer == 1)
    {
        std::cout << "Lanzamos la habilidad 2 del carnivoro" << std::endl;
        // Lanzamos la habilidad 2 del carnivoro
    }
}
void Player::lanzarHabilidadTres()
{
    if(tipoPlayer == 2)
    {
        std::cout << "Lanzamos la habilidad 3 del herbivoro" << std::endl;
        // Lanzamos la habilidad 3 del herbivoro
    }
    if(tipoPlayer == 1)
    {
        std::cout << "Lanzamos la habilidad 3 del carnivoro" << std::endl;
        if(energia>=1){
            energia-=1;
            if(energia <= 10){
                kVel = 10;
            }else{
                kVel = 20;
            }
        }
    }  
}
