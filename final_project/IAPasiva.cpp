
#include "IAPasiva.h"
#include "ingame_state.h"
#include<stdlib.h>
#include<time.h>
#include <math.h>

IAPasiva::IAPasiva() {
    move=false;
    comer=false;
    objetivo=-1;
}

IAPasiva::IAPasiva(const IAPasiva& orig) {
}

IAPasiva::~IAPasiva() {
}

void IAPasiva::elegirComportamiento(Sprite *s){
    std::vector<Food*> comida=ingame_state::instance()->getComida();
  
    if(objetivo==-1){
        moverse(comida,s);
    }else
        buscarComida(comida,s);
        
}

 void IAPasiva::moverse(std::vector<Food*> comida,Sprite* s){
     
            if(!move){
                //srand(time(NULL));//activasmmmos el randomizeitor jojo
                mov_dir = (1 + rand() % (4)); //random para elegir la direccion
                dist = (30 + rand() % (100));//ramdom que la distancia que va a recorrer
                move=true;
                wait.reset();
                time = (1 + rand() % (25))*0.1;
            }else{
                if(wait.getSeconds()>time){
                    if(mov_dir==1){//izquierda
                        if(dist_aux<dist)
                           s->move(-2,0);
                    }
                    if(mov_dir==2){//derecha
                        if(dist_aux<dist)
                           s->move(2,0);
                    }
                     if(mov_dir==3 ){//arriba
                        if(dist_aux<dist)
                           s->move(0,-2);
                    }
                    if(mov_dir==4){//abajo
                        if(dist_aux<dist)
                           s->move(0,2);
                    }
                    dist_aux+=5;
                    if(dist_aux>dist){
                        dist_aux=0;
                        move=false;
                    }
                }
            }
            
            //mira si hay comida cerca
            if(!comer){
                for(int i=0;i<comida.size();i++){
                    std::vector<float> pos =distFood(comida[i],s);
                    if(pos[0]<400 &&pos[1]<400){
                       comer=true;
                       objetivo=i;
                    }
                }
        }
}
 
 std::vector<float> IAPasiva::distFood(Food* comida,Sprite* player){
     std::vector<float> pos;
            //se calcula la distacia a la comida
            int ax = comida->getSprite()->getPosition().x;     
            int ay = comida->getSprite()->getPosition().y;
            float pos1= ax-player->getPosition().x;
            float pos2= ay-player->getPosition().y;
            //se hace el modulo de la distacia
                    if(pos1<0)
                        pos1=-1*pos1;
                    if(pos2<0)
                        pos2=-1*pos2;
            //se comprueba la distacia y se selecciona el objetivo;
            pos.push_back(pos1);
            pos.push_back(pos2);
            
            return pos;
 }
 
 
void IAPasiva::buscarComida(std::vector<Food*> comida,Sprite* s){
    if(objetivo<comida.size()){
            int xp= comida[objetivo]->getSprite()->getPosition().x;
            int yp=comida[objetivo]->getSprite()->getPosition().y;;
            int xplayer=s->getPosition().x;
            int yplayer=s->getPosition().y;
            float angle = atan2(yp - yplayer, xp - xplayer);
            s->move(cos(angle)*2,sin(angle)*2);           
            if(s->getSprite()->getGlobalBounds().intersects(comida[objetivo]->getSprite()->getSprite()->getGlobalBounds())){              
                comer=false;
                objetivo=-1;
            }
    }else
        objetivo=-1;
}