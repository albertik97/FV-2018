
#include "Coords.h"

Coords::Coords() {
}

float Coords::getCoordX(){
    return x;
}

float Coords::getCoordY(){
    return y;
}

void Coords::setCoords(float a, float b){
    x=a;
    y=b;
}