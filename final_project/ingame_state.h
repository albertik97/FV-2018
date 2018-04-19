/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ingame_state.h
 * Author: blanca
 *
 * Created on 17 de abril de 2018, 20:22
 */

#ifndef INGAME_STATE_H
#define INGAME_STATE_H
#include "state.h"
#include "menu_state.h"
#include "Game.h"
#include "TileMap.h"
#include "Text.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class ingame_state : public state
{
private:
    
    ingame_state();
    ingame_state(const ingame_state &);
    ingame_state &operator= (const ingame_state &);
    
    static ingame_state* pinstance;
//    Game* j;
    
    Text texto;
    TileMap mapa;
    

    
public:
    static ingame_state* instance();
    
    void Init();
    void HandleInput();
    void Update();
    void Draw();
};


#endif /* INGAME_STATE_H */

