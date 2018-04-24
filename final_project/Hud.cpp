
#include "Hud.h"
#include "Rectangleshape.h"
#include "Sprite.h"
#include "Motor2D.h"
#include "ingame_state.h"
#include <iostream>
#include <sstream>

Hud::Hud(){
     panel = new Sprite();
     Rectvida = new Sprite();
     Rectexperiencia = new Sprite();
     habilidad_uno = new Sprite();
     habilidad_dos = new Sprite();
     habilidad_tres = new Sprite();
     exp = new Text();
    

}


void Hud::cargarhud(int _tipo){
    tipo = _tipo;
    if(tipo == 1){
        habilidad_uno->setSpriteTexture("resources/Carnivoro/lengua_desactivada.png");
        habilidad_uno->scale(0.025,0.025);

        habilidad_dos->setSpriteTexture("resources/Carnivoro/paraliza_desactivado.png");
        habilidad_dos->scale(0.025,0.025);

        habilidad_tres->setSpriteTexture("resources/Carnivoro/velocidad_desactivado.png");
        habilidad_tres->scale(0.025,0.025);
    }else if(tipo == 2){
        habilidad_uno->setSpriteTexture("resources/Herbivoro/invisible_desactivado.png");
        habilidad_uno->scale(0.025,0.025);

        habilidad_dos->setSpriteTexture("resources/Herbivoro/ralentiza_desactivado.png");
        habilidad_dos->scale(0.025,0.025);

        habilidad_tres->setSpriteTexture("resources/Herbivoro/veneno_desactivado.png");
        habilidad_tres->scale(0.025,0.025);
    }
    
    exp->setText("Experiencia: 0");
    exp->setSize(30);
    exp->setOriginCenter();
    exp->setColor(255,0,0);
    Rectvida->setSpriteTexture("resources/vida.jpg");
    Rectvida->scale(9.3,0.4);
    
    
    Rectexperiencia->setSpriteTexture("resources/experiencia.jpg");
    
    Rectexperiencia->scale(9.3,0.4);
    
    panel->setSpriteTexture("resources/panel.png");
    panel->scale(0.3, 0.3);

}

void Hud::updateHud(float x,float y){
    if(tipo==2 || tipo == 1){
        habilidad_uno->setPosition(40+(x-950),50+(y-530));
        habilidad_dos->setPosition(80+(x-950),50+(y-530));
        habilidad_tres->setPosition(120+(x-950),50+(y-530));
    }
    Rectvida->setPosition(20+(x-950),21+(y-530));
    Rectexperiencia->setPosition(20+(x-950),37+(y-530));
    panel->setPosition(15+(x-950),15+(y-530));

    
    if(ingame_state::instance()->instance()->getPlayer()->getHabilidad() == 1){
        std::cout << "Usamos habilidad numero 1" << std::endl;
    }
    if(ingame_state::instance()->instance()->getPlayer()->getHabilidad() == 2){
        std::cout << "Usamos habilidad numero 2" << std::endl;
    }
    if(ingame_state::instance()->instance()->getPlayer()->getHabilidad() == 3){
        std::cout << "Usamos habilidad numero 3" << std::endl;
    }





    exp->setPos(x+760,y-470);

}

void Hud::sumaexp(int e){
    std::stringstream ss;
    ss<<e;
    std::string str=ss.str();
    exp->setText("Experiencia: "+str);
}
void Hud::draw(){
    //std::cout << "Entramos en el DRAW de HUD" << std::endl;
    Rectexperiencia->draw();
    Rectvida->draw();
    panel->draw();
    habilidad_uno->draw();
    habilidad_dos->draw();
    habilidad_tres->draw();
    exp->draw();
    
    //Rectvida.draw();
    //Rectexperiencia.draw();
}













