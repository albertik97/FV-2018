/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   options_state.h
 * Author: blanca
 *
 * Created on 19 de abril de 2018, 9:32
 */

#ifndef OPTIONS_STATE_H
#define OPTIONS_STATE_H

#include "state.h"
#include "menu_state.h"
#include "Game.h"
#include "Resources.h"
#include <SFML/Graphics.hpp>


class options_state : public state
{
public:
    
    static options_state* Instance();
    
    void Init();
    void HandleInput();
    void Update();
    void Draw();
    
private:
    
    options_state();
    options_state(const options_state &);
    options_state &operator= (const options_state &);
    
    static options_state* pinstance;
        
};


#endif /* OPTIONS_STATE_H */

