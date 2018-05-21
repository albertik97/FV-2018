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
    : movX(0), movY(0) ,kVel(50)
{
    
    sprite = new Sprite();
    lengua = new Sprite();
    lengua->setSpriteTexture("resources/Lengua.png");
    lengua->setOrigin(10,-40);
    veneno = new Sprite();
    veneno->setSpriteTexture("resources/veneno.png");
    veneno->setOrigin(veneno->getSprite()->getGlobalBounds().width / 2, veneno->getSprite()->getGlobalBounds().height / 2);
  
    x = 1920 / 2;
    y = 1080 / 2;
    xlast = 1920 / 2;
    ylast = 1080 / 2;
    up = false;
    left = false;
    down = false;
    right = false;
    
    habbas = false;
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
    invisible = false;
    
    lanzando_veneno = false;

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

void Player::cambiarSprite2(std::string s){
        sprite->setSpriteTexture(s);                              // Y creo el spritesheet a partir de la imagen anterior
        sprite->setTextureRect(1,1, 100, 105);
	sprite->setOrigin(100/2,105/2);
        sprite->scale(0.8,0.8);        
}
int Player::getVida(){
    return vida;
}

void Player::anyadirRaton(){
    mouse= new Mouse();
    mouse->initMouse("resources/mira.png",0.1,0.1);
}

void Player::restaVida(){
    vida-=10;
    if(vida<=10)
         vida=0;
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
    
    if(World::Instance()->getNivelActual() >= 2 && lanzando_veneno)
        veneno->draw();
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
                       
                    }
                    
                    if(Keyboard::isKey2Pressed()){
                        habuno = false;
                        habdos = true;
                        habtres =false;
                         chab2.reset();
                    }
                    
                    if(Keyboard::isKey3Pressed()){
                        habuno = false;
                        habdos = false;
                        habtres = true;
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
                    if(Mouse::LeftPressed()){
                        
                    }
                    if(!Mouse::LeftPressed()){
                        
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
    sf::Vector2f position(mouse->getCursorSprite()->getPosition().x, mouse->getCursorSprite()->getPosition().y); 
    const float PI = 3.14159265;
    float dx = curPos.x - position.x;
    float dy = curPos.y - position.y;
    
    rotation = (atan2(dy, dx)) * 180 / PI;
    sprite->rotate(rotation-90);

}



void Player::update(){

               //HABILIDAD BASICA DEL HERVIBORO DE MOMENTO
           if(habbas && tipoPlayer == 2){
           //sprite
                if(chab.getSeconds() > 0.75){
                   // cambiarSprite2("resources/bicho.png");

                     habbas = false;


                }
           }
    
         ylast=y;
         xlast=x;
         if(tipoPlayer==2 ||tipoPlayer==0 ||(tipoPlayer==1 && !h1)){
            moveChar();
            lookAtMouse();
           
         }
          mouse->CursorUpdate(movX, movY);
       
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
        

       //INVISIBLE DEL HERVIBORO
       if(h1 && tipoPlayer == 2){
           //sprite
           if(!invisible){
                chab1.reset();
           }
           if(chab1.getSeconds() < 5 && energia > 0){
                sprite->transparente();
                invisible = true;
                energia -= 2;
           }else if(chab1.getSeconds() > 6){
               sprite->opaco();
               invisible = false;
               h1 = false;
           }
           
       }
       
       if(h1 && tipoPlayer == 1){
              if(tam<149 && !estado_lengua){
                tam+=75;
                
            }else if(tam>=20){               
                tam-=20;
                estado_lengua=true;
           }else{
               tam=0;      
               h1=false;
               estado_lengua=false;
           }
        
        lengua->setTextureRect(0, 0,23.0,tam);
        lengua->getSprite()->setRotation(rotation+90);
        lengua->setPosition(sprite->getPosition().x,sprite->getPosition().y);
       }
       if(chab2.getSeconds()>5){
           habdos = false;
           habuno = true;
       }
       if(lanzando_veneno && chab2.getSeconds() < 2)
        {
           vxlast=vx;
           vylast=vy;
        veneno->getSprite()->move(cos(dir_veneno * M_PI/180) * 80,sin(dir_veneno * M_PI/180) * 80);
         vx=veneno->getPosition().x;
          vy=veneno->getPosition().y;
     
        }
        else
        {
            lanzando_veneno = false;
            vxlast=vx;
            vylast=vy;
            veneno->setPosition(sprite->getSprite()->getPosition().x, sprite->getSprite()->getPosition().y);
             vx=veneno->getPosition().x;
            vy=veneno->getPosition().y;
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

bool Player::transparente(){
    return invisible;
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

float Player::getPositionVX()
{
    return vx;
}

float Player::getPositionVY()
{
    return vy;
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

float Player::getLastPositionVX()
{
    return vxlast;
}

float Player::getLastPositionVY()
{
    return vylast;
}

void Player::lanzarHabilidadBasica(){
    
    
    if(tipoPlayer ==  2  && !habbas){
        chab.reset();
       // cambiarSprite2("resources/mordisco.png");
        habbas = true;   
    }    
}

void Player::lanzarHabilidadUno()
{
    if(tipoPlayer == 2)
    {
       
        h1 = true;
    }
    if(tipoPlayer == 1)
    {
        // Lanzamos la habilidad 1 del carnivoro
        h1 = true;
    }
}
void Player::lanzarHabilidadDos()
{
    if(tipoPlayer == 2)
    {
      
    }
    if(tipoPlayer == 1)
    {
       
    }
}
void Player::lanzarHabilidadTres()
{
    if(tipoPlayer == 2)
    {
       
        
        if(energia>=30){
            energia-=30;
            lanzarVeneno();
        }
    }
    if(tipoPlayer == 1)
    {
   
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

Sprite* Player::getLengua(){
    return lengua;
}

void Player::lanzarVeneno()
{
    if(!lanzando_veneno)
    {
        lanzando_veneno = true;
        chab2.reset();
        calcDirVeneno();
    }
}


void Player::calcDirVeneno()
{
    const float PI = 3.14159265;

    
    float x = mouse->getCursorSprite()->getSprite()->getPosition().x - sprite->getPosition().x; //mouse.x - _sprite.getPosition().x;
    float y = mouse->getCursorSprite()->getSprite()->getPosition().y - sprite->getPosition().y;//mouse.y - _sprite.getPosition().y;
    
    float hipp = sqrt(pow(x, 2) + pow(y, 2));
    
    float dx = mouse->getCursorSprite()->getSprite()->getPosition().x - sprite->getPosition().x;
    float dy = mouse->getCursorSprite()->getSprite()->getPosition().y - sprite->getPosition().y;
    
    float angulo = (atan2(dy, dx) * 180 / PI);
    if(mouse->getCursorSprite()->getSprite()->getPosition().y > sprite->getPosition().y)
    {
        float aux = (180 - angulo) + 180;
        angulo = -aux;
    }
    dir_veneno = angulo;
    hip = hipp;
}

Sprite* Player::getVeneno()
{
    return veneno;
}

bool Player::getLanzandoVeneno(){
    return lanzando_veneno;
}
