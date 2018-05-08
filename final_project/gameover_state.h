/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gameover_state.h
 * Author: jose
 *
 * Created on 28 de abril de 2018, 17:00
 */

#ifndef GAMEOVER_STATE_H
#define GAMEOVER_STATE_H
#include "state.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Sprite.h"

class gameover_state : public state
{
private:
    
    gameover_state();
    gameover_state(const gameover_state &);
    gameover_state &operator= (const gameover_state &);
    
    static gameover_state* pinstance;
    
    Sprite fondo;
    int vida;
    
    

public:
    static gameover_state* Instance();
    
    void Init();
    void HandleInput();
    void Update();
    void Draw(float);
};

#endif /* GAMEOVER_STATE_H */