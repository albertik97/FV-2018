#include "IA.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Colisionator.h"
#ifndef IAACTIVA_H
#define IAACTIVA_H

class IAActiva : public IA {
public:
    IAActiva();
    IAActiva(const IAActiva& orig);
    virtual ~IAActiva();
    void elegirComportamiento(Sprite* &s);
    void moverse(std::vector<Food*> f,Sprite* s);
    void perseguir(Sprite* s, float time);
    bool checkColisionMap(int x, int y, Sprite* enemy);
private:
   int kVel,mousex,mousey,mov_dir,dist,objetivo;
   float dist_aux, tiempo;
   bool dir,paralizado,pillado, mode,moviendose,comer;
   sf::Clock tm,clockParalisis,espera_movimiento,t_ataque;
   Colisionator collision;
};

#endif /* IAACTIVA_H */


