

#ifndef INGAME_STATE_H
#define INGAME_STATE_H
#include "state.h"
#include "menu_state.h"
#include "Game.h"
#include "TileMap.h"
#include "Player.h"
#include "Colisionator.h"
#include "Text.h"
#include "Mouse.h"
#include "Enemy.h"

#include <iostream>
#include <SFML/Graphics.hpp>

class ingame_state : public state
{
private:
    
    ingame_state();
    ingame_state(const ingame_state &);
    ingame_state &operator= (const ingame_state &);
    
    static ingame_state* pinstance;
    
    TileMap mapa;
    Player* player;
    Mouse mouse;
    Enemy* enemys[10];
    Colisionator colision;
    std::vector<Food*> comidaArray;
    
public:
    static ingame_state* instance();
    
    void Init();
    void HandleInput();
    void Update();
    void Draw();
};


#endif /* INGAME_STATE_H */

