
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
     Rectenergia = new Sprite();
     //Rectexperiencia = new Sprite();
     habilidad_uno = new Sprite();
     habilidad_dos = new Sprite();
     habilidad_tres = new Sprite();
     exp = new Text();
     exp->setFont(SCORE_FONT_FILEPATH);
    
     vida = 100;
     energia = 0;
     habilidadActiva = 0;
     
}


void Hud::cargarhud(int _tipo){
    tipo = _tipo;
    if(tipo == 1){
        habilidad_uno->setSpriteTexture("resources/Carnivoro/lengua_desactivada.png");
        habilidad_uno->scale(0.033,0.033);

        habilidad_dos->setSpriteTexture("resources/Carnivoro/paraliza_desactivado.png");
        habilidad_dos->scale(0.033,0.033);

        habilidad_tres->setSpriteTexture("resources/Carnivoro/velocidad_desactivado.png");
        habilidad_tres->scale(0.033,0.033);
    }else if(tipo == 2){
        habilidad_uno->setSpriteTexture("resources/Herbivoro/invisible_desactivado.png");
        habilidad_uno->scale(0.033,0.033);

        habilidad_dos->setSpriteTexture("resources/Herbivoro/ralentiza_desactivado.png");
        habilidad_dos->scale(0.033,0.033);

        habilidad_tres->setSpriteTexture("resources/Herbivoro/veneno_desactivado.png");
        habilidad_tres->scale(0.033,0.033);
    }
    
    exp->setText("Experiencia: 0");
    exp->setSize(30);
    exp->setOriginCenter();
    exp->setColor(255,0,0);
    Rectvida->setSpriteTexture("resources/vida.jpg");
    Rectvida->scale(12.4,0.4);
    
    
    panel->setSpriteTexture("resources/panel.png");
    panel->scale(0.4, 0.4);

    
    habilidad_uno->setPosition(55+(-950),63+(-530));
    habilidad_dos->setPosition(105+(-950),63+(-530));
    habilidad_tres->setPosition(155+(-950),63+(-530));
}

void Hud::activaHabilidad(int _hab, int _tipo){
    if(_tipo == 1){
        if(_hab == 1){
            habilidad_uno->setSpriteTexture("resources/Carnivoro/lengua_activada.png");
            habilidad_uno->scale(0.033,0.033);
        }
        if(_hab == 2){
            habilidad_dos->setSpriteTexture("resources/Carnivoro/paraliza_activado.png");
            habilidad_dos->scale(0.033,0.033);
        }
        if(_hab == 3){
            habilidad_tres->setSpriteTexture("resources/Carnivoro/velocidad_activado.png");
            habilidad_tres->scale(0.033,0.033);
        }
    }else if(_tipo == 2){
        if(_hab == 1){
            habilidad_uno->setSpriteTexture("resources/Herbivoro/invisible_activado.png");
            habilidad_uno->scale(0.033,0.033);
        }
        if(_hab == 2){
            habilidad_dos->setSpriteTexture("resources/Herbivoro/ralentiza.png");
            habilidad_dos->scale(0.033,0.033);
        }
        if(_hab == 3){
            habilidad_tres->setSpriteTexture("resources/Herbivoro/veneno.png");
            habilidad_tres->scale(0.033,0.033);
        }
    }
}

void Hud::desactivaHabilidad(int _hab, int _tipo){
    if(_hab != 0){
        if(_tipo == 1){
            if(_hab == 1){
                habilidad_uno->setSpriteTexture("resources/Carnivoro/lengua_desactivada.png");
                habilidad_uno->scale(0.033,0.033);
            }
            if(_hab == 2){
                habilidad_dos->setSpriteTexture("resources/Carnivoro/paraliza_desactivado.png");
                habilidad_dos->scale(0.033,0.033);
            }
            if(_hab == 3){
                habilidad_tres->setSpriteTexture("resources/Carnivoro/velocidad_desactivado.png");
                habilidad_tres->scale(0.033,0.033);
            }
        }else if(_tipo == 2){
            if(_hab == 1){
                habilidad_uno->setSpriteTexture("resources/Herbivoro/invisible_desactivado.png");
                habilidad_uno->scale(0.033,0.033);
            }
            if(_hab == 2){
                habilidad_dos->setSpriteTexture("resources/Herbivoro/ralentiza_desactivado.png");
                habilidad_dos->scale(0.033,0.033);
            }
            if(_hab == 3){
                habilidad_tres->setSpriteTexture("resources/Herbivoro/veneno_desactivado.png");
                habilidad_tres->scale(0.033,0.033);
            }
        }
    }
}

void Hud::updateHud(float x,float y){
    if(tipo==2 || tipo == 1){
        habilidad_uno->setPosition(55+(x-950),63+(y-530));
        habilidad_dos->setPosition(105+(x-950),63+(y-530));
        habilidad_tres->setPosition(155+(x-950),63+(y-530));
        
    }
    
    energia = World::Instance()->getPlayer()->getEnergia();
    if(energia > 0 && energia < maxenergia){
        rellenoenergia = (energia*12.4)/maxenergia;
        //aumentamos la energia
       // std::cout<<"energia: "<<energia<<std::endl;
        Rectenergia->setSpriteTexture("resources/experiencia.jpg");
        Rectenergia->scale(rellenoenergia,0.4);
    }
    
    Rectvida->setPosition(20+(x-950),25+(y-530));
    Rectenergia->setPosition(20+(x-950),47+(y-530));
    panel->setPosition(15+(x-950),15+(y-530));

    
    if(World::Instance()->getPlayer()->getHabilidad() == 1){
        //std::cout << "Usamos habilidad numero 1" << std::endl;
        activaHabilidad(1, tipo);
        if(habilidadActiva != 1){
            desactivaHabilidad(habilidadActiva, tipo);
        }
        habilidadActiva = 1;
    }
    if(World::Instance()->getPlayer()->getHabilidad() == 2){
        //std::cout << "Usamos habilidad numero 2" << std::endl;
        activaHabilidad(2, tipo);
         if(habilidadActiva != 2){
            desactivaHabilidad(habilidadActiva, tipo);
        }
        habilidadActiva = 2;
    }
    if(World::Instance()->getPlayer()->getHabilidad() == 3){
        //std::cout << "Usamos habilidad numero 3" << std::endl;
        activaHabilidad(3, tipo);
         if(habilidadActiva != 3){
            desactivaHabilidad(habilidadActiva, tipo);
        }
        habilidadActiva = 3;
    }

    float scale=(12.3 * World::Instance()->getPlayer()->getVida()/100);
    Rectvida->scale2(scale,0.4);
    exp->setPos(x+760,y-470);

}

void Hud::sumaexp(int e){
    std::stringstream ss;
    ss<<e;
    std::string str=ss.str();
    exp->setText("Experiencia: "+str);
}
void Hud::draw(){

    Rectenergia->draw();
    Rectvida->draw();
    panel->draw();
    habilidad_uno->draw();
    habilidad_dos->draw();
    habilidad_tres->draw();
    exp->draw();
    
}












