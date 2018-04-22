/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Text.h
 * Author: blanca
 *
 * Created on 17 de abril de 2018, 20:07
 */

#include<SFML/Graphics.hpp>
#include<string>
#ifndef TEXT_H
#define TEXT_H

class Text {
public:
    Text();
    Text(const Text& orig);
    virtual ~Text();
    void draw(sf::RenderWindow &a);
    void setText(std::string s);
    void setPos(int x, int y);
    void setColor(int r, int g, int b);
    void setSize(int a);
    sf::Text getText();
    bool getColision(float x,float y);
    void draw();
    void setOriginCenter();
    
private:
    sf::Text text;
    sf::Font font;
};

#endif /* TEXT_H */
