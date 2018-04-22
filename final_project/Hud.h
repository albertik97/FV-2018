/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hud.h
 * Author: jose
 *
 * Created on 19 de abril de 2018, 12:00
 */

#ifndef HUD_H
#define HUD_H
#include <SFML/Graphics.hpp>
#include <strings.h>
#include "Rectangleshape.h"
#include "Sprite.h"
#include "Player.h"
#include <iostream>


class Hud{
public:
    
    int vida;
    int experiencia;
    Sprite* Rectvida;
    //sf::Texture t_vida;
    Sprite* Rectexperiencia;
    //sf::Sprite t_experiencia;
    //Habilidades
    Sprite* panel;
    Sprite* habilidad_uno;
    Sprite* habilidad_dos;
    Sprite* habilidad_tres;
    //Habilidades 3er nivel
    Sprite* h_especial_c;
    Sprite* h_especial_h;
    //Tipo de player (Carnivoro o Herbivoro);
    int tipo;// 0 canrivoro, 1 herb, 2 celu
    
    Hud();
    void cargarhud(int a);
    void updateHud(float x,float y);
    void aumentavida();
    void draw();
    //virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void restarvida();
    void sumarvida();
    void restaexp();
    void sumaexp();
    //void tipo();
    
};


#endif /* HUD_H */

