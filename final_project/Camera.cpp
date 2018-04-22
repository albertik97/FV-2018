

#include "Camera.h"

Camera::Camera() 
{
    
}
void Camera::setCenter(float originX, float originY)
{
    view.setCenter(sf::Vector2f(sf::Vector2f(originX, originY)));
    
}

void Camera::setSize(float sizeX, float sizeY)
{
    view.setSize(sf::Vector2f(sizeX, sizeY));
}

sf::View Camera::getView()
{
    return view;
}