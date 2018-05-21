
#include "Game.h"
#include "Motor2D.h"
#include "TileMap.h"
#include "Resources.h"

#include "Player.h"
#include "Hud.h"
#include "Camera.h"
#include "Clock.h"
#include "Fondo.h"
#include "Food.h"
#include "Enemy.h"
#include "IA.h"
#include "IAActiva.h"
#include "IAPasiva.h"
#include "IAStopped.h"
#include "Colisionator.h"
#include "Boss.h"
#include "Music.h"
#include "Sound.h"
#include "states.h"

#include <math.h>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>



#ifndef WORLD_H
#define WORLD_H

class World {
public:
    static World* Instance();
    void CargarNivel(int nivel);
    
    Player* getPlayer();
    TileMap getMapa();
    Camera getCamera();
    Hud getHud();
    bool getEndGame();
    std::vector<Food*> getComida();
    std::vector<Enemy*> getEnemies();
    int getNivelActual();
    Fondo getFondo();
    Clock* getTimeBoss();
    
    /*
    Clock getClockGameStart();
    
    
    */
    void Update();
    void Draw(float percentTick);
    
    void beginAlpha(float percentTick);
    void endAlpha(float percentTick);
    void setEndGame(bool state_game);
    void resetWorld();    
    
    
private:
    
    
    World();
    World(const World &);
    World &operator= (const World &);
    
    static World* pinstance;
    int nivelActual;
    TileMap mapa;
    Sound sonidoComida;
    Sound sonidoLengua;
    Music musicaNiveluno;
    Music musicaNiveldos;
    Music musicaNiveltres;
    Camera camera;
    Player* player;
    std::vector<Food*> comidaArray;
    std::vector<Enemy*> enemys;
    Colisionator colision;
    Hud hud;
    Fondo fondoTransition;
    Clock gameStart;
    Clock *bossTime;
    bool endGame;
    bool nivelico;
    
    Boss* boss;
};

#endif /* WORLD_H */

