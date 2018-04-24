/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Resources.h
 * Author: blanca
 *
 * Created on 17 de abril de 2018, 20:32
 */

#ifndef RESOURCES_H
#define RESOURCES_H

#include <string>


// Window things
const int WINDOW_WIDTH                                  = 1920;
const int WINDOW_HEIGHT                                 = 1080;


// Times for things
const float INTRO_STATE_TIME                            = 8.f;
const float INTRO_STATE_TRANSITION_SPEED                = 1.f;
const float INTRO_STATE_TRANSITION_TIME                 = 2.f;


// Sprites and img's
const std::string SELECTOR_SPRITE_FILEPATH              = "resources/flechaa.png";
const std::string WOOD_TEXTURE_FILEPATH                 = "resources/wood.jpg";
const std::string MENU_STATE_BACKGROUND_FILEPATH        = "resources/fondo.jpg";
const std::string INTRO_STATE_BACKGROUND_FILEPATH       = "resources/CHOP-CODERS.jpg";
const std::string ruta                                  = "resources/sprites.png";
const std::string ENEMY_SPRITE_FILEPATH                 = "resources/enemy.png";
const std::string PLAYER_SPRITE_FILEPATH                = "resources/player.png";


const std::string GAME_MENU_FONT_FILEPATH               = "resources/prstart.ttf";
const std::string SCORE_FONT_FILEPATH                   = "resources/font.ttf";

#endif /* RESOURCES_H */
