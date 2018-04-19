/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clock.h
 * Author: blanca
 *
 * Created on 17 de abril de 2018, 20:07
 */
#ifndef CLOCK_H
#define CLOCK_H

class Clock {
public:
    Clock();
    Clock(const Clock& orig);
    virtual ~Clock();
    void reset();
    float getSeconds();
    float getMiliseconds();
private:
    sf::Clock time;
};

#endif /* CLOCK_H */
