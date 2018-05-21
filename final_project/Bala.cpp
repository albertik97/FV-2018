
#include "Bala.h"
#include "World.h"


Bala::Bala(int x, int y) {
    sprite = new Sprite();
    sprite->setSpriteTexture("resources/tauro.png");
    sprite->setOrigin(sprite->getSprite()->getGlobalBounds().width / 2, sprite->getSprite()->getGlobalBounds().height / 2);
    sprite->setPosition(x,y);
    sprite->scale2(0.1,0.1);
}

Bala::Bala(const Bala& orig) {
}

Bala::~Bala() {
}

void Bala::setDirection(){
        const float PI = 3.14159265;

        Sprite* player=World::Instance()->getPlayer()->getSprite();
    float x = player->getPosition().x - sprite->getPosition().x; //mouse.x - _sprite.getPosition().x;
    float y = player->getPosition().y - sprite->getPosition().y;//mouse.y - _sprite.getPosition().y;
    
    float hipp = sqrt(pow(x, 2) + pow(y, 2));
    
    float angulo = (atan2(y, x) * 180 / PI);
    if(player->getPosition().y > sprite->getPosition().y)
    {
        float aux = (180 - angulo) + 180;
        angulo = -aux;
    }
    direction = angulo;
    sprite->getSprite()->setRotation(direction-90);

}

void Bala::update(){

    sprite->move(cos( direction * M_PI/180) * 80,sin( direction * M_PI/180) * 80);
        
}

void Bala::draw(){
    sprite->draw();
}

Sprite* Bala::getSprite(){
    return sprite;
}
