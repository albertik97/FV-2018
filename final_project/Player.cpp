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

#define kVel 20

#define kSalto 20

Player::Player() 
    : movX(0), movY(0)
{
    
    sprite=new Sprite();
    x = 1920 / 2;
    y = 1080 / 2;
    xlast = 1920 / 2;
    ylast = 1080 / 2;
    up = false;
    left = false;
    down = false;
    right = false;

    habuno = false;
    habdos = false;
    habtres = false;
    
    

    exp=0;
    carne=0;
    verdura=0;

    eliminoComida = 0;
    vida=100;
    
    mouse.initMouse("resources/mira.png",0.1,0.1);
    mouse.getCursorSprite()->setPosition(x+50, y+50);

    energia = 1;
    
    tipoPlayer = 1;



}

int Player::getVida(){
    return vida;
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
    mouse.getCursorSprite()->draw();
    
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
                       // std::cout << "HABILIDAD 1" << std::endl;
                    }
                    
                    if(Keyboard::isKey2Pressed()){
                        habdos = true;
                        //std::cout << "HABILIDAD 2" << std::endl;
                    }
                    
                    if(Keyboard::isKey3Pressed()){
                        habtres = true;
                        //std::cout << "HABILIDAD 3" << std::endl;
                    }

		//}
	
	
	//else{
	
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
                        
                        //std::cout << "ABAJOOOOOOOOOOOOOOOOO FALSE" << std::endl;
                    }
                    
                    if(!Keyboard::isKey1Pressed()){
                        habuno = false;
                        //std::cout << "HABILIDAD 1 FALSE" << std::endl;
                    }
                    
                    if(!Keyboard::isKey2Pressed()){
                        habdos = false;
                        //std::cout << "HABILIDAD 2 FALSE" << std::endl;
                    }
                    
                    if(!Keyboard::isKey3Pressed()){
                        habtres = false;
                        //std::cout << "HABILIDAD 3 FALSE" << std::endl;
                    }
		
	//}  

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
    sf::Vector2f position(mouse.getCursorSprite()->getPosition().x, mouse.getCursorSprite()->getPosition().y); 
    const float PI = 3.14159265;
    float dx = curPos.x - position.x;
    float dy = curPos.y - position.y;
    float rotation = (atan2(dy, dx)) * 180 / PI;
    sprite->rotate(rotation-90);

}



void Player::update(){
         ylast=y;
         xlast=x;
       moveChar();
       mouse.CursorUpdate(movX, movY);
       lookAtMouse();
       sprite->animar(7,1, 112, 173, 134);
       if(!left && !right && !up && !down){
            sprite->setAnimationTime(500);
        }
}

// Si pulsamos IZDA, intentamos ir a la IZDA
// Si pulsamos DCHA, intentamos ir a la DCHA
void Player::moveChar(){
    
	if(left || right){
            moveX();
        }
        
        
        
        if(up || down){
            moveY();
        }
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

Mouse Player::getMouse()
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
