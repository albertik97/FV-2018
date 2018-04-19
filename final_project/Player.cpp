#include "Player.h"
#include <iostream>
#include <math.h>  
#include "Motor2D.h"
#include "Sprite.h"
#include "Mouse.h"
#include "Keyboard.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

#define kVel 5

#define kSalto 20

Player::Player() {
    
    sprite = new Sprite();
    
    up = false;
    left = false;
    down = false;
    right = false;
    dir = 1;
}
/*
void Player::chargingTexture() {
	//Cargo la imagen donde reside la textura del sprite
	if (!tex.loadFromFile("resources/sprites.png")){
		std::cerr << "Error cargando el sprite del personaje";
		exit(0);
	}
	
	sprite= sf::Sprite(tex);                                // Y creo el spritesheet a partir de la imagen anterior
        sprite.setTextureRect(sf::IntRect(4,238, 58, 64));
	sprite.setOrigin(58/2,64/2);
	sprite.setPosition(x, y);                               // Lo dispongo en el centro de la pantalla
}
*/

void Player::draw() {
    
    sprite->draw();
}

void Player::input(){
        
    if(sf::Event::KeyPressed){

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

		}
	
	
	else{
	
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

}



void Player::lookAtMouse(){
    
    sf::Vector2f curPos = sprite->getPosition();
    sf::Vector2i position= (Mouse::getPosX(), Mouse::getPosY());    
    const float PI = 3.14159265;
    float dx = curPos.x - position.x;
    float dy = curPos.y - position.y;
    float rotation = (atan2(dy, dx)) * 180 / PI;
    sprite->rotate(rotation-90);

}



void Player::update(){
        lookAtMouse();
	moveChar();
}

// Si pulsamos IZDA, intentamos ir a la IZDA
// Si pulsamos DCHA, intentamos ir a la DCHA
void Player::moveChar(){
    
	if(left){
            moveX(-1);
            dir=-1;
            
        }
	else{
             if(right){      
             moveX(1);
             dir=1;
             }
        }
        
        if(up){
            
            moveY(-1);
            dir=-1;
            
        }
        else{
            if(down){
                
            moveY(1);
            dir=1;
            
            }
        }
   
}


void Player::moveX(){

             sprite->moving(dir * kVel, 0);
       
}

void Player::moveY(){

             sprite->moving(0, dir * kVel);
      
}
/*
bool Player::colisionComida(){
   
        if(comida->sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())){
            std::cout<<"Colisiona"<<std::endl;
            return true;
        }
    return false;
  
}

*/