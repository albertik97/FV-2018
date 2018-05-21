/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <SFML/Audio.hpp>
#include "Sound.h"
#include <string>
#include <iostream>

void Sound::setSound(std::string sonidico){
    if(buffer.loadFromFile(sonidico)){
        std::cout << "HEMOS CARGADO EL SONIDO" << sonidico << std::endl;
        sonido.setBuffer(buffer);
    }else{
        std::cout << "NO SE HA PODIDO CARGAR EL SONIDO" << std::endl;
    }
}

void Sound::playSound(){
    sonido.play();
}

