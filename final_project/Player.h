/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: blanca
 *
 * Created on 19 de abril de 2018, 17:48
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Coords.h"

class Player {
public:
    Player();
    Player(const Player& orig);
    virtual ~Player();
    void draw();
    void lookAtMouse();
    void update();
    void input();
    void moveChar();
    void moveX();
    void moveY();
    bool colisionComida();
    
private:
    
    Coords actual;
    Coords last;
    Sprite* sprite;
    bool left;
    bool up;
    bool down;
    bool right;
    float dir;

};

#endif /* PLAYER_H */

