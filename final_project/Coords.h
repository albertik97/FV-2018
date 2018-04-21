
#ifndef COORDS_H
#define COORDS_H

class Coords {
public:
    Coords();
    float getCoordX();
    float getCoordY();
    void setCoords(float x,float y);

private:
    float x;
    float y;
};

#endif /* COORDS_H */

