/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Motor2D.h
 * Author: blanca
 *
 * Created on 27 de marzo de 2018, 10:39
 */

#ifndef MOTOR2D_H
#define MOTOR2D_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Motor2D {
public:
    static Motor2D* Instance();
    sf::RenderWindow* getWindow();
    void dibujar(sf::Sprite );
    void dibujarTexto(sf::Text);
    void clearWindow();
    bool openWindow();
    void displayWindow();
    void closeWindow();
    
private:
    Motor2D();
    Motor2D(const Motor2D& );
    Motor2D &operator= (const Motor2D &);
    static Motor2D* pinstance;
    sf::RenderWindow window;
};

#endif /* MOTOR2D_H */

