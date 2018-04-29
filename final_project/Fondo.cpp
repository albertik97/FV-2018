

#include "Fondo.h"
#include <iostream>

Fondo::Fondo() 
{
    
}

Fondo::Fondo(const Fondo& orig) {
}

void Fondo::setSize(float x, float y)
{
    shape.setSize(sf::Vector2f(x, y));
}

void Fondo::setColor(int r, int g, int b)
{
    shape.setFillColor(sf::Color(r, g, b));
}

void Fondo::setAlpha(int a)
{
    shape.setFillColor(sf::Color(shape.getFillColor().r, shape.getFillColor().g, shape.getFillColor().b, a));
}

int Fondo::getAlpha()
{
    return static_cast<int>(shape.getFillColor().a);
}

void Fondo::setOutlineThickness(float thick)
{
    shape.setOutlineThickness(thick);
}

void Fondo::setOutlineColor(int r, int g, int b)
{
    shape.setOutlineColor(sf::Color(r, g, b));
}

void Fondo::setOriginCenter()
{
    std::cout << "width: " << shape.getGlobalBounds().width << " height: " << shape.getGlobalBounds().height << std::endl;
    shape.setOrigin(shape.getGlobalBounds().width / 2, shape.getGlobalBounds().height / 2);
}

void Fondo::setPos(float x, float y)
{
    shape.setPosition(x, y);
}

void Fondo::setTexture(std::string path)
{
    textureShape.loadFromFile(path);
    shape.setTexture(&textureShape);
}

void Fondo::setTextureRect(int x, int y)
{
    shape.setTextureRect(sf::IntRect(0, 0, x, y));
}

sf::RectangleShape Fondo::getShape()
{
    return shape;
}

void Fondo::draw()
{
    Motor2D *j = Motor2D::Instance();
    j->dibujar(shape);
}

