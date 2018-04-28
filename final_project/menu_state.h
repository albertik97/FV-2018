/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   menu_state.h
 * Author: blanca
 *
 * Created on 17 de abril de 2018, 20:21
 */

#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "state.h"
#include "Transitions.h"
#include "ingame_state.h"
#include "Game.h"
#include "Resources.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Text.h"
#include "Mouse.h"
#include "Sprite.h"
#include "Button.h"
#include "Clock.h"
#include "World.h"

class menu_state : public state, transitions
{
private:
    
    menu_state();
    menu_state(const menu_state &);
    menu_state &operator= (const menu_state &);
    
    
    static menu_state* pinstance;
    Text menu[4];
    Button b[4];
    Sprite fondo;
    Sprite selector;
    int selected;
    Clock menuStart;
    Mouse mouse;
    
public:
        
    static menu_state* Instance();
    void Init();
    void HandleInput();
    void Update();
    void Draw(float);
    void Up();
    void Down();
    void beginAlpha(float);
    void endAlpha(float);
};


#endif /* MENU_STATE_H */

