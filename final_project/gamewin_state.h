

#include "state.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Sprite.h"

#ifndef GAMEWIN_STATE_H
#define GAMEWIN_STATE_H

class gamewin_state : public state
{
public:
    static gamewin_state* Instance();
    
    void Init();
    void HandleInput();
    void Update();
    void Draw(float);
    
private:
    
    gamewin_state();
    gamewin_state(const gamewin_state &);
    gamewin_state &operator= (const gamewin_state &);
    
    
    static gamewin_state* pinstance;
    
    Sprite fondo;

};

#endif /* GAMEWIN_STATE_H */