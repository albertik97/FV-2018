
#ifndef IAPASIVA_H
#define IAPASIVA_H
#include "Sprite.h"
#include "IA.h"
#include "Clock.h"
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include<iostream>

class IAPasiva : public IA {
public:
    IAPasiva();
    IAPasiva(const IAPasiva& orig);
    virtual ~IAPasiva();
    int recalcularEstrategia(Sprite* s);
    void estrategia(Sprite* s);
private:
    int mov_dir,dist,dist_aux=0;
    float time;//tiempo que se mueve
    Clock wait;
    bool move;
};

#endif /* IAPASIVA_H */

