/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   state.h
 * Author: blanca
 *
 * Created on 17 de abril de 2018, 20:20
 */

#ifndef STATE_H
#define STATE_H


class state
{
public:
    virtual void Init() = 0;
    virtual void HandleInput() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
private:
    
};




#endif /* STATE_H */

