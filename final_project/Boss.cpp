

#include "Boss.h"
#include "Sprite.h"
#include <math.h>

#define pi 3.14159265358979323846

Boss::Boss() {
     sprite = new Sprite();
     sprite->setSpriteTexture("resources/boss.png");
     sprite->setOrigin(sprite->getSprite()->getGlobalBounds().width / 2, sprite->getSprite()->getGlobalBounds().height / 2);
     sprite->setPosition(1700,700);
     sprite->scale2(0.15,0.15);
     rotationx=0;
     rotationy=0;
     x=1700;
     y=700;
     lasty=y;
     lastx=x;
     
}

Boss::Boss(const Boss& orig) {
}

Boss::~Boss() {
}
void Boss::update(){
    
    if(time.getSeconds()>4){
        lastx = sprite->getSprite()->getPosition().x;
        lasty = sprite->getSprite()->getPosition().y;
        sprite->move(cos(rotationx)*60,sin(rotationy)*60);
        rotationx+=pi/2;
        rotationy+=pi/2;
        x= sprite->getSprite()->getPosition().x;
        y= sprite->getSprite()->getPosition().y;
    }
    
    
}

void Boss::draw(){
    sprite->draw();
}


float Boss::getPositionX(){
    return x;
}

float Boss::getPositionY(){
    return y;
}

float Boss::getLastPositionX(){
    return lastx;
}

float Boss::getLastPositionY(){
    return lasty;
}

void Boss::setPosition(float x, float y){
    sprite->setPosition(x,y);
}