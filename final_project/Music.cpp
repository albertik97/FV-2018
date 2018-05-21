/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Music.h"
#include <string>
#include <iostream>

Music::Music(){
    
}

void Music::cargarMusica(std::string musiquilla){
    if(!musica.openFromFile(musiquilla)){
        std::cout << "EROR, NO SE HA ENCONTRADO EL ARCHIVO MUSICAL" << std::endl;
    }else{
        std::cout <<"SE HA CARGADO EL ARCHIVO DE AUDIO" << musiquilla << std::endl;
    }
}

void Music::pararMusica(){
    musica.stop();
}

void Music::play(){
    musica.play();
}

void Music::musicaBucle(){
    musica.setLoop(true);
}

