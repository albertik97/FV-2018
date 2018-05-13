

#include "World.h"
#include "gameover_state.h"

World* World::pinstance = 0;
World* World::Instance()
{
    if(pinstance == 0)
    {
        pinstance = new World();
        std::cout << "Instancia de mundo creada" << std::endl;
    }
    return pinstance;
}

World::World() 
    : nivelActual(0), endGame(false)
{
    std::cout << "Hemos creado el mundo y parace que no ha petado " << std::endl;
    nivelico=false;
}

void World::CargarNivel(int nivel)
{
    std::cout << "cargamos el nivel " << nivel << std::endl;
    
    if(nivel == 1)
    {
        nivelActual = nivel;
        
        srand(time(0));
        mapa.cargarmapa(LEVEL1_MAP_FILEPATH);
        
        for(int i=0; i<1; i++)
        {  
            Enemy* e = new Enemy();
            e->chargingTexture("resources/enemy.png",1024,1024,0.06,0.07);
            e->setPosRandom(mapa._tilemap);
            enemys.push_back(e);
        }
        
        player = new Player();
        player->chargingTexture();
        
        camera.setCenter(player->getPositionX(), player->getPositionY());
        camera.setSize(1920, 1080);
        
              
        hud.cargarhud(1);
        
        for(int i=0; i<160; i++)
        {  
            Food* comida = new Food();
            comidaArray.push_back(comida);
            comidaArray[i]->setRandomFood(mapa._tileMapSprite);
        }
              
        colision.setPlayer(player);
        colision.setEnemies(enemys);
       
        fondoTransition.setSize(WINDOW_WIDTH * 2, WINDOW_HEIGHT * 2);
        fondoTransition.setColor(0, 0, 0);
        fondoTransition.setOriginCenter();
        fondoTransition.setPos(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
        
    }
    else
        if(nivel == 2)
        {
            resetWorld();
            nivelActual = nivel;
            srand(time(0));
            mapa.cargarmapa(LEVEL2_MAP_FILEPATH);
            
            for(int i=0; i<30; i++)
            {  
                Enemy* e = new Enemy();
                e->chargingTexture("resources/carnivoro.png",100,100,0.6,0.6);
               // e->getSprite()->setSpriteTexture("resources/carnivoro.png");
                e->setPosRandom(mapa._tilemap);
                enemys.push_back(e);
            }

            
            player->anyadirRaton();
            if(player->getCarne()>player->getVerdura()){
                player->cambiarSprite("resources/carnivoro.png");
                player->setTipo(1);
            }else{
                player->cambiarSprite("resources/bicho.png");
                player->setTipo(2);
            }

            camera.setCenter(player->getPositionX(), player->getPositionY());
            camera.setSize(1920, 1080);


            if(player->getTipo()==1)
                hud.cargarhud(1);
            else
                hud.cargarhud(2);

            for(int i=0; i<100; i++)
            {  
                Food* comida = new Food();
                comidaArray.push_back(comida);
                comidaArray[i]->setRandomFood(mapa._tileMapSprite);
            }


            colision.setPlayer(player);
            colision.setEnemies(enemys);




            fondoTransition.setSize(WINDOW_WIDTH * 2, WINDOW_HEIGHT * 2);
            fondoTransition.setColor(0, 0, 0);
            fondoTransition.setOriginCenter();
            fondoTransition.setPos(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
            fondoTransition.setAlpha(0);
        }
        else
            if(nivel == 3)
            {
                nivelActual = nivel;
                // carga el nivel del jefe final
            }
    
    
    std::cout << "Se ha cargado todo lo del nivel " << nivel << std::endl;
                
}

void World::Update()
{

    if(player->getExperiencia() >= 30 && !nivelico)
    {
        nivelico=true;
        Game::instance()->setState(transition_state::Instance());
        Motor2D::Instance()->resetCamera();
       //CargarNivel(2);
    }
    
    
    if(endGame && fondoTransition.getAlpha() == 255)
    {
        //endGame = false;
        Motor2D::Instance()->resetCamera();
        Game::instance()->setState(menu_state::Instance());
    }
    if(fondoTransition.getAlpha() == 255)
    {
        gameStart.reset();
    }
    
    
    for(int i=0; i<enemys.size(); i++){
        //OPTIMIZACION DE CALCULO DE COLISIONES
        int x = player->getPositionX();
        int y = player->getPositionY();
        int xEnemy = enemys[i]->getSprite()->getPosition().x;
        int yEnemy = enemys[i]->getSprite()->getPosition().y;
        int mitadPantallaX = Motor2D::Instance()->getWindow()->getView().getSize().x/2;
        int mitadPantallaY = Motor2D::Instance()->getWindow()->getView().getSize().y/2;
        if(xEnemy<x+mitadPantallaX && xEnemy>x-mitadPantallaX && yEnemy<y+mitadPantallaY && yEnemy>y-mitadPantallaY){
            colision.checkColisionComidaEnemy(comidaArray);
            //std::cout<<"Entro"<<i<<std::endl;          
        }
    }
    
   
    
    player->update();
    
    for(int i=0;i<enemys.size();i++)
    {
        enemys[i]->update();
        float x = enemys[i]->getSprite()->getPosition().x-player->getPositionX();
        float y = enemys[i]->getSprite()->getPosition().y-player->getPositionY();
        float resultado = sqrt((x*x)+(y*y));
        //std::cout << "ESTAMOS DENTRO DE ENEMIGOS" << std::endl;
        if(resultado<400){
            
            if(resultado>400 && enemys[i]->getStrategy()->getType() != 1){
                enemys[i]->changeStrategy(new IAPasiva());
                std::cout << "IA PASIVA" << std::endl;
            }else if(!player->transparente() && enemys[i]->getStrategy()->getType() != 0){
                std::cout << "IA ACTIVA" << std::endl;
                enemys[i]->changeStrategy(new IAActiva());
            }
            if(resultado<300 && player->getHabilidad()==2 && enemys[i]->getStrategy()->getType() != 2){
                enemys[i]->changeStrategy(new IAStopped());
            }

        }
        if(resultado>400 && enemys[i]->getStrategy()->getType() != 1){
            enemys[i]->changeStrategy(new IAPasiva());
            std::cout << "IA PASIVA" << std::endl;
        }
        
        
    }
    
    if(colision.checkColisionComida(comidaArray))
        hud.sumaexp(player->getExperiencia());
    
    
    hud.updateHud(player->getPositionX(), player->getPositionY());
    
    for(int i=0;i<comidaArray.size();i++)
        comidaArray[i]->update();
    
    player->aumentaEnergia(gameStart.getSeconds());
    
    if(player->getVida() == 0){
        std::cout << "Has muerto bandido" << std::endl;
        Motor2D::Instance()->Instance()->resetCamera();
        Game::instance()->setState(gameover_state::Instance());
    }
    
    
}

void World::Draw(float percentTick)
{
    if(gameStart.getSeconds() < 10)
    {
        endAlpha(percentTick);
    }
    if(endGame)
    {
        beginAlpha(percentTick);
    }
    player->setPositionInterpolated(player->getLastPositionX()*(1-percentTick)+player->getPositionX()*percentTick,player->getLastPositionY()*(1-percentTick)+player->getPositionY()*percentTick);
    
    hud.panel->setPosition(((player->getLastPositionX()*(1-percentTick)+player->getPositionX()*percentTick)-950)+15,15+((player->getLastPositionY()*(1-percentTick)+player->getPositionY()*percentTick)-530));
    hud.Rectenergia->setPosition(((player->getLastPositionX()*(1-percentTick)+player->getPositionX()*percentTick)-950)+20,47+((player->getLastPositionY()*(1-percentTick)+player->getPositionY()*percentTick)-530));
    hud.Rectvida->setPosition(((player->getLastPositionX()*(1-percentTick)+player->getPositionX()*percentTick)-950)+20,25+((player->getLastPositionY()*(1-percentTick)+player->getPositionY()*percentTick)-530));
    hud.habilidad_uno->setPosition(((player->getLastPositionX()*(1-percentTick)+player->getPositionX()*percentTick)-950)+55,63+((player->getLastPositionY()*(1-percentTick)+player->getPositionY()*percentTick)-530));
    hud.habilidad_dos->setPosition(((player->getLastPositionX()*(1-percentTick)+player->getPositionX()*percentTick)-950)+105,63+((player->getLastPositionY()*(1-percentTick)+player->getPositionY()*percentTick)-530));
    hud.habilidad_tres->setPosition(((player->getLastPositionX()*(1-percentTick)+player->getPositionX()*percentTick)-950)+155,63+((player->getLastPositionY()*(1-percentTick)+player->getPositionY()*percentTick)-530));
    hud.exp->setPos((player->getLastPositionX()*(1-percentTick)+player->getPositionX()*percentTick)+760,(player->getLastPositionY()*(1-percentTick)+player->getPositionY()*percentTick)-470);
    player->getMouse()->setPositionInterpolated(player->getMouse()->getLastPositionX()*(1-percentTick)+player->getMouse()->getPositionX()*percentTick,player->getMouse()->getLastPositionY()*(1-percentTick)+player->getMouse()->getPositionY()*percentTick);

    
    camera.setCenter(player->getSprite()->getPosition().x, player->getSprite()->getPosition().y);
    Motor2D::Instance()->setCamera(camera);
    mapa.setCapaActiva(0);
    Motor2D::Instance()->getWindow()->draw(mapa);
    mapa.setCapaActiva(1);
    Motor2D::Instance()->getWindow()->draw(mapa);
    mapa.setCapaActiva(2);
    Motor2D::Instance()->getWindow()->draw(mapa);
    
    for(int i=0; i<comidaArray.size(); i++)
    {
        comidaArray[i]->getSprite()->draw();
    }
    
    for(int i=0;i<enemys.size();i++)
        enemys[i]->setPositionInterpolated(enemys[i]->getLastPositionX()*(1-percentTick)+enemys[i]->getPositionX()*percentTick,enemys[i]->getLastPositionY()*(1-percentTick)+enemys[i]->getPositionY()*percentTick);
    
    for(int i=0;i<enemys.size();i++)
        enemys[i]->draw();
    
    
    
    player->draw();
    
    hud.draw();
    
    if(fondoTransition.getAlpha() != 0)
            fondoTransition.draw();
}

void World::beginAlpha(float percentTick)
{
    fondoTransition.setPos(player->getPositionX(), player->getPositionY());
    int alpha = fondoTransition.getAlpha() + (INTRO_STATE_TRANSITION_SPEED * 4 * percentTick);
    
    if(alpha >= 255)
    {
        alpha = 255;
    }
    fondoTransition.setAlpha(alpha);
}

void World::endAlpha(float percentTick)
{
    fondoTransition.setPos(player->getPositionX(), player->getPositionY());
    int alpha = fondoTransition.getAlpha() - (INTRO_STATE_TRANSITION_SPEED * 4 * percentTick);
        
    if(alpha <= 0)
    {
        alpha = 0;
    }
    fondoTransition.setAlpha(alpha);
}


void World::resetWorld()
{
    mapa.deleteMap();
    for(int x = 0;  x < comidaArray.size(); x++)
    {
        delete comidaArray[x];
        comidaArray[x] = NULL;
        comidaArray.erase(comidaArray.begin() + x);
    }
    comidaArray.clear();
    for(int i = 0; i < enemys.size(); i++)
    {
        delete enemys[i];
        enemys[i] = NULL;
        enemys.erase(enemys.begin() + i);
    }
    enemys.clear();
    delete player->getMouse();
    
}


Player* World::getPlayer()
{
    return player;
}


std::vector<Enemy*> World::getEnemies()
{
    return enemys;
}


TileMap World::getMapa()
{
    return mapa;
}

Camera World::getCamera()
{
    return camera;
}

Hud World::getHud()
{
    return hud;
}

Fondo World::getFondo()
{
    return fondoTransition;
}

void World::setEndGame(bool state_game)
{
    endGame = state_game;
}
bool World::getEndGame()
{
    return endGame;
}

std::vector<Food*> World::getComida()
{
    return comidaArray;
}

int World::getNivelActual()
{
    return nivelActual;
}
