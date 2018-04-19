/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: blanca
 *
 * Created on 27 de marzo de 2018, 10:38
 */

#include <cstdlib>
#include "Motor2D.h"
#include "Game.h"
#include "states.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Motor2D* motor = Motor2D::Instance();
    state* menu = menu_state::Instance();
    Game* j = Game::instance();
    j->setState(menu);
    j->run();
    
    return 0;
}

