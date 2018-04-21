/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Colisionator.h
 * Author: blanca
 *
 * Created on 21 de abril de 2018, 13:34
 */

#ifndef COLISIONATOR_H
#define COLISIONATOR_H

#include "Motor2D.h"
#include "Player.h"
#include "Food.h"

class Colisionator {
public:
    Colisionator();
    Colisionator(const Colisionator& orig);
    virtual ~Colisionator();
    void setPlayer(Player* p);
    void setFood(std::vector<Food*>);
    bool checkColisionComida();
    void update();
private:
    Player* player;
    std::vector<Food*> comidaArray;

};

#endif /* COLISIONATOR_H */

