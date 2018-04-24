/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mouse.h
 * Author: blanca
 *
 * Created on 17 de abril de 2018, 20:08
 */

#include<SFML/Graphics.hpp>

#ifndef MOUSE_H
#define MOUSE_H

#include "Sprite.h"
#include "Motor2D.h"

class Mouse {
public:
    Mouse();
    Mouse(const Mouse& orig);
    virtual ~Mouse();
   static bool LeftPressed();
   static bool RightPressed();
   static float getPosX();
   static float getPosY();
   void setTexture(std::string);
   void CursorUpdate(int x, int y);
   Sprite* getCursorSprite();
   void initMouse(std::string a,float s1,float s2);
   sf::Mouse getMouse();
private:
    Sprite* cursor;
    sf::Mouse mouse;
};

#endif /* MOUSE_H */
