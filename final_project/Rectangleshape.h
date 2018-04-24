/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rectangleshape.h
 * Author: jose
 *
 * Created on 21 de abril de 2018, 10:29
 */

#ifndef RECTANGLESHAPE_H
#define RECTANGLESHAPE_H
#include <SFML/Graphics.hpp>

class Rectangleshape{
public:
    Rectangleshape();
    void draw();
    void scale(float x, float y);
    void setPosition(float x, float y);
    void setOrigin(int x, int y);
    void setSize(float x, float y);
    void setFillColor(std::string);
    sf::RectangleShape* getRectangleshape();
    sf::Vector2f tamanio;

    
private:
    sf::RectangleShape *rectangleshape;
};


#endif /* RECTANGLESHAPE_H */

