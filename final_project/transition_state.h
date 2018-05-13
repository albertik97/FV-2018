/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   transition_state.h
 * Author: root
 *
 * Created on 30 de abril de 2018, 11:32
 */

#ifndef TRANSITION_STATE_H
#define TRANSITION_STATE_H

#include "state.h"
#include "World.h"
#include "Game.h"
#include "Motor2D.h"

class transition_state : public state
{
public:
    static transition_state* Instance();
    
    void Init();
    void HandleInput();
    void Update();
    void Draw(float percentTick);
private:
    
    static transition_state* pinstance;
    
    transition_state();
    transition_state(const transition_state & );
    transition_state &operator= (const transition_state & );
    Text text[4];
    Sprite img;

};

#endif /* TRANSITION_STATE_H */

