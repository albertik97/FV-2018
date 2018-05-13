
#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>



class Sprite {
public:
    Sprite();


    void draw( );
    void scale(float x, float y);
    void scale2(float x, float y);
    void moving(float x, float y);
    void rotate(float angle);
    sf::Vector2f getPosition();
    void setPosition(float x, float y);
    void setOrigin(int x, int y);
    sf::Sprite* getSprite();
    int getAlpha();
    void setAlpha(int a);
    void setSpriteTexture(std::string je);
    void setTextureRect(int a,int b,int c,int d);
    void move(int a,int b);
    void setAnimationTime(int t);
    void animar(int a, int b, int c, int d, int factor);
    void transparente();
    void opaco();
    void setLastAlpha(int a);
    int getLastAlpha();
private:
   sf::Sprite *sprite;
   sf::Texture texture;
   sf::Clock tiempo;
   int animationTime;
   int lastAlpha;

};

#endif /* SPRITE_H */

