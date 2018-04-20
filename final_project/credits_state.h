/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   credits_state.h
 * Author: blanca
 *
 * Created on 19 de abril de 2018, 9:33
 */

#ifndef CREDITS_STATE_H
#define CREDITS_STATE_H


#include "state.h"
#include "menu_state.h"
#include "Game.h"
#include "Resources.h"
#include <SFML/Graphics.hpp>


class credits_state : public state
{
public:
    
    static credits_state* Instance();    
    
    void Init();
    void HandleInput();
    void Update();
    void Draw();
    
private:
    
    credits_state();
    credits_state(const credits_state &);
    credits_state &operator= (const credits_state &);
    
    static credits_state* pinstance;
    Text texto[6];
            
};
#endif /* CREDITS_STATE_H */

