
#include "IAPasiva.h"
#include "ingame_state.h"
#include<stdlib.h>
#include<time.h>
#include <math.h>

#define kVel 10

IAPasiva::IAPasiva() {
    move=false;
    comer=false;

}

IAPasiva::IAPasiva(const IAPasiva& orig) {
}

IAPasiva::~IAPasiva() {
}

void IAPasiva::elegirComportamiento(Sprite *&s){

        moverse(World::Instance()->getComida(),s);

}

 void IAPasiva::moverse(std::vector<Food*> comida,Sprite* &s){
    
            if(!move && !comer){
                //srand(time(NULL));//activasmmmos el randomizeitor jojo
                mov_dir = (1 + rand() % (4)); //random para elegir la direccion
                dist = (30 + rand() % (100));//ramdom que la distancia que va a recorrer
                move=true;
                wait.reset();
                time = (1 + rand() % (25))*0.1;
            }else if(!comer){
                if(wait.getSeconds()>time){
                     if(mov_dir==1){//izquierda
                     if(!checkColisionMap(-kVel,0,s)){    
                        if(dist_aux<dist )
                           s->move(-kVel,0);
                         }
                    }
                    if(mov_dir==2){//derecha
                     if(!checkColisionMap(kVel,0,s)){
                        if(dist_aux<dist)
                           s->move(kVel,0);
                       }
                    }
                     if(mov_dir==3 ){//arriba
                     if(!checkColisionMap(0,-kVel,s)){
                        if(dist_aux<dist)
                           s->move(0,-kVel);
                        }
                    }
                    if(mov_dir==4){//abajo
                        if(!checkColisionMap(0,kVel,s)){
                        if(dist_aux<dist)
                           s->move(0,kVel);
                        }
                     }
                    dist_aux+=5;
                    if(dist_aux>dist){
                        dist_aux=0;
                        move=false;
                    }
                }
            }
            
            //mira si hay comida cerca
            
                int i=0;
                int minima=100000;
                int select=-1;
                while(i<comida.size()){
                    std::vector<float> pos =distFood(comida[i],s);
                  
                    if(pos[0]<400 &&pos[1]<400){
                       comer=true;
                       move=true;
                      
                       if((sqrt(pow((int)pos[0],2)+(pow((int)pos[1],2),2))) < minima){
                        minima = sqrt(pow((int)pos[0],2)+(pow((int)pos[1],2),2));
                        select = i;
                        }
                    }       
                    i++;
                }
                if(comer&&select!=-1)
                    buscarComida(World::Instance()->getComida(),s,select);
           
                if(i==comida.size()&&select==-1){
                    comer=false;
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
 
 
void IAPasiva::buscarComida(std::vector<Food*> comida,Sprite* s,int i){
    
            int xp= World::Instance()->getComida()[i]->getSprite()->getSprite()->getPosition().x;
            int yp=World::Instance()->getComida()[i]->getSprite()->getSprite()->getPosition().y;
            int xplayer=s->getPosition().x;
            int yplayer=s->getPosition().y;
            float angle = atan2(yp - yplayer, xp - xplayer);
            if(!checkColisionMap(cos(angle)*2, sin(angle)*2, s)){
                s->move(cos(angle)*2*kVel,sin(angle)*2*kVel);
                if(collision.checkColisionSprite(comida,s)){              
                    comer=false;
         
                     
                }
            }           
}


bool IAPasiva::checkColisionMap(int x, int y, Sprite* s){
    
    //COJO LAS CUATRO ESQUINAS DEL BOUNDING BOX
    
    float left = s->getSprite()->getGlobalBounds().left+15 + x;
    float top = s->getSprite()->getGlobalBounds().top+15 + y;
    float right = s->getSprite()->getGlobalBounds().width-60 + left;
    float down = top + s->getSprite()->getGlobalBounds().height-60;
    if(World::Instance()->getMapa()._tilemap[1][(int)top/32][(int)left/32]==0 &&
       World::Instance()->getMapa()._tilemap[1][(int)top/32][(int)right/32]==0 &&
       World::Instance()->getMapa()._tilemap[1][(int)down/32][(int)left/32]==0 &&
       World::Instance()->getMapa()._tilemap[1][(int)down/32][(int)right/32]==0){
        return false;
    }
    return true;
}


int IAPasiva::getType(){
    return 1;
}

 void IAPasiva::setVelocidad(float){
     
 }
