
#ifndef IAPASIVA_H
#define IAPASIVA_H
#include "Sprite.h"
#include "IA.h"
#include "Clock.h"
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include<iostream>
#include "Food.h"
#include "Player.h"
#include <vector>
#include "Sprite.h"

class IAPasiva : public IA {
public:
    IAPasiva();
    IAPasiva(const IAPasiva& orig);
    virtual ~IAPasiva();
    void moverse(std::vector<Food*> f,Sprite* s);
    void buscarComida(std::vector<Food*> f,Sprite* player);
    void elegirComportamiento(Sprite *s);
    std::vector<float> distFood(Food* comida,Sprite* player);
private:
    int mov_dir,dist,dist_aux;
    float time;//tiempo que se mueve
    Clock wait;
    bool move,comer;
    int objetivo;
    int mode;//0 buscar comida
};

#endif /* IAPASIVA_H */

