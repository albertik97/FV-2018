/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: blanca
 *
 * Created on 19 de abril de 2018, 17:48
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Coords.h"
#include "Sprite.h"
#include "Mouse.h"

class Player {
public:
    Player();
    void draw();
    void lookAtMouse();
    void update();
    void input();
    void moveChar();
    void moveX();
    void moveY();
    bool colisionComida();
    void chargingTexture();
    Sprite* getSprite();
    float getPositionX();
    float getPositionY();
    void setPositionInterpolated(float x,float y);
    float getLastPositionX();
    float getLastPositionY();
    int getHabilidad();
    void setExperiencia(int exp);
    int getExperiencia();
    int getVida();
    void aumenteCarne();
    void aumentaVerdura();

    void restaVida();
    void aumentaVida();
    bool checkColisionMap(int, int);

    void aumentaEnergia(float _tiempo);
    float getEnergia();
    int getTipo();
    void setTipo(int i);
    void cambiarSprite(std::string);
    int getCarne();
    int getVerdura();    

    Mouse* getMouse();
    
    void anyadirRaton();

    
private:
    sf::Texture tex;
    Coords actual;
    Coords last;
    Sprite* sprite;
    bool left;
    bool up;
    bool down;
    bool right;
    bool habuno;
    bool habdos;
    bool habtres;
    int energia; // minimo 0 maximo 1000;
    int maxenergia = 1000;
    int vida;
    int experiencia;
    float dir;
    int x,xlast,y,ylast;
    int exp,carne,verdura;//la experciencia y la cantidad de comida de cada tipo
    int eliminoComida;
    Mouse* mouse;
    int movX;
    int movY;

    int tipoPlayer;



};

#endif /* PLAYER_H */
