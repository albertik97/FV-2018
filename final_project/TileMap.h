/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TileMap.h
 * Author: blanca
 *
 * Created on 19 de abril de 2018, 9:59
 */

#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>


class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    sf::Texture _tileSetTexture;
    sf::Sprite**** _tileMapSprite;
    sf::Sprite *_tileSetImagen;
    int*** _tilemap;
    int anchoTile;
    int altoTile;
    int anchoMapa;
    int altoMapa;
    int anchoImagen;
    int altoImagen;
    int numeroCapas;
    int capaActiva ;
    const char* tilesetname;
    
  
    void cargarmapa(std::string path);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void setCapaActiva(int layer);  
};



#endif /* TILEMAP_H */

