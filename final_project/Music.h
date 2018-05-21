/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Music.h
 * Author: jose
 *
 * Created on 21 de mayo de 2018, 16:29
 */

#ifndef MUSIC_H
#define MUSIC_H
#include <SFML/Audio.hpp>


class Music {
public:
    Music();
    void cargarMusica(std::string musiquilla);
    void pararMusica();
    void musicaBucle();
    void play();
private:
    sf::Music musica;

};







#endif /* MUSIC_H */

