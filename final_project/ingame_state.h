

#ifndef INGAME_STATE_H
#define INGAME_STATE_H
#include "state.h"

#include "World.h"

#include "menu_state.h"
#include "Game.h"

#include "Text.h"
#include "Mouse.h"


#include <iostream>
#include <SFML/Graphics.hpp>

class ingame_state : public state
{
private:
    
    ingame_state();
    ingame_state(const ingame_state &);
    ingame_state &operator= (const ingame_state &);
    
    static ingame_state* pinstance;
    
    World* mundo;
    
    
    
public:
    static ingame_state* instance();
    
    void Init();
    void HandleInput();
    void Update();
    void Draw(float);


};


#endif /* INGAME_STATE_H */

