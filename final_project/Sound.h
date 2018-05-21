/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sound.h
 * Author: jose
 *
 * Created on 21 de mayo de 2018, 17:27
 */

#ifndef SOUND_H
#define SOUND_H
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

class Sound{
private:
    sf::Sound sonido;
    sf::SoundBuffer buffer;
public:
    void setSound(std::string sonidico);
    void playSound();
    void stopSound();

};

#endif /* SOUND_H */

