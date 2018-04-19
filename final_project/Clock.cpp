/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clock.cpp
 * Author: blanca
 * 
 * Created on 17 de abril de 2018, 20:07
 */

#include<iostream>
#include <SFML/System/Clock.hpp>

#include "Clock.h"

Clock::Clock() {
    time.restart();
}

Clock::Clock(const Clock& orig) {
}

Clock::~Clock() {
}

void Clock::reset(){
    time.restart();
}

float Clock::getSeconds(){
    return time.getElapsedTime().asSeconds();
}

float Clock::getMiliseconds(){
    return time.getElapsedTime().asMilliseconds();
}