
#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>


class Camera {
public:
    Camera();
    
    sf::View getView();
    void setCenter(float originX, float originY);
    void centerToPlayer();
    void setSize(float sizeX, float sizeY);
   
private:
    sf::View view;
};

#endif /* CAMERA_H */

