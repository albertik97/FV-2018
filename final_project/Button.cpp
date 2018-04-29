

#include "Button.h"

Button::Button() {
}

Button::Button(const Button& orig) {
}


Text* Button::getTextButton()
{
    return &text;
}

Fondo* Button::getFondoButton()
{
    return &background;
}

void Button::alignButton()
{
    
}

void Button::draw()
{
    background.draw();
    text.draw();
}

bool Button::getColision(float x, float y)
{
    if(
        x >= background.getShape().getGlobalBounds().left &&
        x <= background.getShape().getGlobalBounds().width + background.getShape().getGlobalBounds().left &&
        y >= background.getShape().getGlobalBounds().top &&
        y <= background.getShape().getGlobalBounds().height + background.getShape().getGlobalBounds().top
      )
    {
        return true;
    }
    else 
        return false;
}