
#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>



class Sprite {
public:
    Sprite();


    void draw( );
    void scale(float x, float y);
    void moving(float x, float y);
    void rotate(float angle);
    sf::Vector2f getPosition();
    void setPosition(float x, float y);
    void setOrigin(int x, int y);
    sf::Sprite* getSprite();
    void setSpriteTexture(std::string je);
    void setTextureRect(int a,int b,int c,int d);
    void move(int a,int b);
private:
   sf::Sprite *sprite;
   sf::Texture texture;

};

#endif /* SPRITE_H */

