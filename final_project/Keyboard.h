/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Keyboard.h
 * Author: blanca
 *
 * Created on 17 de abril de 2018, 20:07
 */

#ifndef KEYBOARD_H
#define KEYBOARD_H

class Keyboard {
public:
    Keyboard();
    Keyboard(const Keyboard& orig);
    virtual ~Keyboard();
   static bool isKeyWPressed();
   static bool isKeyAPressed();
   static bool isKeySPressed();
   static bool isKeyDPressed();
   static bool isKeyPPressed();//tecla para activar trucos
   static bool isKeyUpPressed();
   static bool isKeyDownPressed();
   static bool isKeyEscPressed();//para el menu
   static bool isKey1Pressed();//para el menu
   static bool isKey2Pressed();//para el menu
   static bool isKey3Pressed();//para el menu
   static bool isKeyEnterPressed();//para el menu
private:

};

#endif /* KEYBOARD_H */
