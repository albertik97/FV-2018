

#ifndef FONDO_H
#define FONDO_H

#include "Motor2D.h"

class Fondo {
public:
    Fondo();
    Fondo(const Fondo& orig);
    void setSize(float x, float y);
    void setColor(int r, int g, int b);
    void setAlpha(int a);
    void setOutlineThickness(float thick);
    void setOutlineColor(int r, int g, int b);
    int getAlpha();
    void setOriginCenter();
    void setPos(float x, float y);
    void setTexture(std::string path);
    void setTextureRect(int x, int y);
    sf::RectangleShape getShape();
    
    
    void draw();
    

private:
    sf::RectangleShape shape;
    sf::Texture textureShape;
    
};

#endif /* FONDO_H */
