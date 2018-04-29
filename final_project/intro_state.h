

#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include <SFML/Graphics.hpp>
#include "state.h"
#include "Transitions.h"
#include "Game.h"
#include "Motor2D.h"
#include "Resources.h"
#include "Clock.h"
#include "Keyboard.h"
#include "Fondo.h"
#include "Button.h"


class intro_state : public state, transitions
{
public:
    static intro_state* Instance();
    void Init();
    void HandleInput();
    void Update();
    void Draw(float);
    
    void beginAlpha(float);
    void endAlpha(float);
private:
    intro_state();
    intro_state(const intro_state &);
    intro_state &operator= (const intro_state &);
    
    static intro_state* pinstance;
    
    Clock stateTimer;
    Clock skipTextTimer;
    Sprite background;
    Text skipText;
    Button b;
    
    Fondo f;
};

#endif /* INTRO_STATE_H */
