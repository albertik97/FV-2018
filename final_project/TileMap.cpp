/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TileMap.cpp
 * Author: blanca
 * 
 * Created on 19 de abril de 2018, 9:59
 */

#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include "tinystr.h"
#include "tinyxml.h"
#include "iostream"
#include "ingame_state.h"

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    
    
    /*for(int i = 0; i < 256; i++){
        target.draw(_tileSetImagen[i]);
    }*/
    
    
    for(int i = 0; i < altoMapa; i++){
        for(int j = 0; j< anchoMapa; j++){
            if(_tileMapSprite[capaActiva][i][j] != NULL){
                target.draw(*(_tileMapSprite[capaActiva][i][j]));
            }
        }
    }
}

void TileMap::cargarmapa(){
    TiXmlDocument doc;
    doc.LoadFile("oceano_nivel1.tmx");
    TiXmlElement *map = doc.FirstChildElement("map");
    
    //Recogemos los atributos del mapa
    map->QueryIntAttribute("width", &anchoMapa); //100
    map->QueryIntAttribute("height", &altoMapa); //100
    map->QueryIntAttribute("tilewidth", &anchoTile); //Ancho del tile en px = 32
    map->QueryIntAttribute("tileheight", &altoTile); //Ancho del tile en px = 32
       
    TiXmlElement *layer = map->FirstChildElement("layer");
   
    //Recogemos la imagen del tileset
    TiXmlElement *img = map->FirstChildElement("tileset")->FirstChildElement("image");
    tilesetname = img->Attribute("source");
    //Imprimimos el nombre o ruta del tileset
    std::cout << "Nombre del tileset: " << tilesetname << std::endl;
  
    while(layer != NULL){
        /*if(numeroCapas < 1)*/
        numeroCapas++; //Si tenemos solo una capa entonces numeroCapas es 0 y si son dos capas 1 etc...
        layer = layer->NextSiblingElement("layer");
    }
    
    numeroCapas=1; ///linea que hay que borrar pero que es porvisional para que se puedan hacer pruebas
    
    TiXmlElement *data[numeroCapas];
    data[0] = map->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
    _tilemap = new int**[numeroCapas]; 
    //int numeraso = 0;
    // _tilemap = Matriz que contendrá el ID de cada tile.
    //tilemap es un puntero a un array con el numero de capas el cual cada numero del array apunta 
    //a un array [height] que contiene la altura del mapa y cada elemento del array altura
    //apunta al primer ID de cada fila, luego para acceder al resto sumamos una posicion de memoria
    for(int i = 0; i < numeroCapas; i++){
        _tilemap[i] = new int*[altoMapa];
    }
    for(int l = 0; l < numeroCapas; l++){
        for(int y = 0; y < altoMapa; y++){
            _tilemap[l][y] = new int[anchoMapa];
            for(int x = 0; x < anchoMapa; x++){
               // std::cout<<l<<","<<y<<","<<x<<std::endl;
                data[l]->QueryIntAttribute("gid", &_tilemap[l][y][x]);
                data[l] = data[l]->NextSiblingElement("tile");            
            }
        }
    }

    /*
    for(int i = 0; i < numeroCapas-2; i++){
        for(int j = 0; j < altoMapa; j++){
            for(int x = 0; x < anchoMapa; x++){
                std::cout << _tilemap[i][j][x] << std::endl;
            }
        }
    }
    */
    
    
    
    //Recortamos y añadimos el tileset al array
    //Primero sacamos las columnas y la altura del tileset
    img->QueryIntAttribute("width", &anchoImagen);
    img->QueryIntAttribute("height", &altoImagen);
    int columnas = anchoImagen/anchoTile;  //512px/32px;
    int filas = altoImagen/altoTile;    //512px/32px;
    _tileSetImagen = new sf::Sprite[columnas*filas+1];
    int posicion = 0;
    _tileSetTexture.loadFromFile(tilesetname);//Cargamos el tileset 
    //Rellenamos un array unidimensional con cada uno de los Sprites del tileset
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            posicion++;
            _tileSetImagen->setTexture(_tileSetTexture);
            _tileSetImagen[posicion].setTextureRect(sf::IntRect(32*j,32*i,32,32));
        }
    }
    
    
    
    //AQUI TENEMOS DOS VARIABLES tileset y tilesetTexture, la primera tiene los IDS de cada una
    //de las posiciones del mapa y la otra tiene cargadas una tras otra los tiles(imagenes)
    //ahora hay que relacionarlas jejejejejejejejej que guay 
    _tileMapSprite = new sf::Sprite***[numeroCapas];
    
    for(int l = 0; l < numeroCapas; l++){
        _tileMapSprite[l] = new sf::Sprite**[altoMapa];
    }
    for(int l = 0; l < numeroCapas; l++){
        for(int y = 0; y < altoMapa; y++){
            _tileMapSprite[l][y] = new sf::Sprite*[anchoMapa];
            for(int x = 0; x < anchoMapa; x++){
                _tileMapSprite[l][y][x] = new sf::Sprite();
            }
        }
    }
     
    
    for(int l=0; l<numeroCapas; l++){
        for(int y=0; y<altoMapa; y++){
            for(int x=0; x<anchoMapa; x++){
                int gid = _tilemap[l][y][x];
                if(gid >= anchoTile*altoTile){
                    std::cout << "Error, gid at (l,x,y) = (" << l << "," << x << "," << y << "): "
                            << gid << " fuera del rango del tileset ("<<anchoTile*altoTile<<")" << std::endl;
                }
                else if(gid > 0){
                    //std::cout << "_tileMapSprite[" << l << "][" << y << "][" << x << "]" << std::endl;
                    //_tileMapSprite[l][y][x] = _tileSetImagen[gid];
                    _tileMapSprite[l][y][x] = new sf::Sprite(_tileSetTexture, _tileSetImagen[gid].getTextureRect());
                    _tileMapSprite[l][y][x]->setPosition(x*anchoTile, y*altoTile);
                    //if(l == 2)
                    //std::cout << "[" << l << "][" << y << "][" << x << "] -- " << gid << std::endl;
                }
                else{
                    _tileMapSprite[l][y][x] = NULL;
                }
            }
        }
    }
}

