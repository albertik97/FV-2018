

#ifndef BUTTON_H
#define BUTTON_H

#include "Motor2D.h"
#include "Resources.h"
#include "Text.h"
#include "Fondo.h"
#include "Transitions.h"

class Button
{
public:
    Button();
    Button(const Button& orig);
    
    Text* getTextButton();
    Fondo* getFondoButton();
    void alignButton();
    
    void draw();
    bool getColision(float x, float y);

    
private:
    Text text;
    Fondo background;
    
    
};

#endif /* BUTTON_H */
