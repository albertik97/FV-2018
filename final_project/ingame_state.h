

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
#include "Camera.h"
#include "Hud.h"

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
    std::vector<Enemy*> enemys;
    Colisionator colision;
    std::vector<Food*> comidaArray;
    Camera camera;
    Hud hud;
    
    
public:
    static ingame_state* instance();
    
    void Init();
    void HandleInput();
    void Update();
    void Draw();
    Player* getPlayer();
    std::vector<Enemy*>  getEnemys();
    std::vector<Food*> getComida();
};


#endif /* INGAME_STATE_H */

