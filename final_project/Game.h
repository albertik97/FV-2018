/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: blanca
 *
 * Created on 10 de abril de 2018, 12:18
 */





#ifndef GAME_H
#define GAME_H

#include "Sprite.h"
#include "Food.h"

//nuevo añadido de Alberto

#include "Text.h"
#include "states.h"


class Game {
public:
    static Game* instance();
    void run();
    void update();
    void init();
    void setState(state* escena);
    //Sprite *prueba;

private:
    Game();
    Game(const Game& orig);
    Game &operator= (const Game &);
    

    static Game* pinstance;
    Text t;
    state* escena;

    

};

#endif /* GAME_H */

