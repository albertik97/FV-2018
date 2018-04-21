
#include "IAPasiva.h"
#include<stdlib.h>
#include<time.h>

IAPasiva::IAPasiva() {
    move=false;
}

IAPasiva::IAPasiva(const IAPasiva& orig) {
}

IAPasiva::~IAPasiva() {
}

int IAPasiva::recalcularEstrategia(Sprite* s){
    
    if(true)
        estrategia(s);
}

 void IAPasiva::estrategia(Sprite* s){
     
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
 }