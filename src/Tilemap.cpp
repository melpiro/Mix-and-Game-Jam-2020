//
// Created by Alarm on 13/11/2020.
//

#include "Tilemap.h"

#include <utility>
#include <iostream>
#include "Omega/Graphics/RessourceManager.h"
#include "JsonData.hpp"
#include <algorithm>

Tilemap::Tilemap(sf::Vector2i dimensions, std::vector<Tile> tileset,sf::RenderWindow &fen): m_dimensions(dimensions),m_tileSet(std::move(tileset)){
    m_tileSize = m_tileSet[0].getTextureSize();
    m_fen = &fen;
}

Tilemap::Tilemap(std::vector<Tile> tileset, sf::RenderWindow &fen, std::string path):m_tileSet(std::move(tileset)){
    m_tileSize = m_tileSet[0].getTextureSize();
    m_fen = &fen;
    //TODO : Faire la lecture dans le fichier demandé
    loadlevelFromFile(path);

    m_rects = getColliders();

    for(auto r : m_rects){
        std::cout << "Rect a x:" << r.left << " y:" << r.top << " avec h:" << r.height << " et w:" << r.width << std::endl;
    }

}

void Tilemap::draw() {

    for(int y = 0; y < m_dimensions.y ; y++ ){
        for(int x = 0; x < m_dimensions.x; x++){
            m_tileSet[m_map[y][x]].draw(x*m_tileSize,y*m_tileSize,m_fen);
        }
    }

    sf::RectangleShape rc = sf::RectangleShape(sf::Vector2f(0,0));
    rc.setFillColor(sf::Color(255,0,0,100));

    for(auto r : m_rects){
        rc.setSize(sf::Vector2f(r.width,r.height));
        rc.setPosition(r.left,r.top);
        m_fen->draw(rc);
    }

}

void Tilemap::update() {
    for(Tile &t : m_tileSet){
        t.update();
    }
}

Tilemap::Tilemap() {

}

void Tilemap::setTMap(std::vector<std::vector<int>> tmap) {
    m_map = tmap;
}


std::vector<sf::FloatRect> Tilemap::getColliders() {

    std::vector<line*> lignes = cutLines(m_map);
    std::vector<line*> excluded;
    std::vector<sf::FloatRect> rects;

    for(line* l : lignes){
        /*if(std::find(excluded.begin(),excluded.end(),l) == excluded.end())
            rects.push_back(*getRect(l,&lignes,&excluded));*/
        rects.emplace_back(l->x*m_tileSize,l->y*m_tileSize,l->size*m_tileSize,m_tileSize);
    }
    return rects;
}

void Tilemap::loadlevelFromFile(std::string path) {
    JsonData j;
    j.readFile(path);
    m_dimensions.x = *((double *)j["mapSize"]["x"].getValue());
    m_dimensions.y = *((double *)j["mapSize"]["y"].getValue());

    std::cout << *((double *)j["mapSize"]["x"].getValue()) << "   " << m_dimensions.y << std::endl;

    for(int y = 0; y < m_dimensions.y ; y++){
        m_map.emplace_back(std::vector<int>());
        for(int x = 0; x < m_dimensions.x ; x++){
            m_map[y].emplace_back( *((double*)j["mapData"][y][x].getValue()));
        }
    }
}


line* Tilemap::getLineUnder(line* ligne, std::vector<line*>* lignes,std::vector<line*> *excluded) {

    if(ligne == nullptr) return nullptr;

    for(line* l : *lignes){
        if( l->y == ligne->y + 1 && l->x == ligne->x && l->size == ligne->size){
            excluded->push_back(l);
            return l;
        }
    }
    return nullptr;
}

std::vector<line*>* Tilemap::getLinesUnder(line* ligne, std::vector<line*>* lignes,
                                        std::vector<line*> *excluded) {
    if(ligne == nullptr) return nullptr;

    line* lastLine = getLineUnder(ligne,lignes,excluded);
    std::vector<line*>* t_lines = new std::vector<line*>();

    if(lastLine == nullptr) return nullptr;
    else t_lines->push_back(lastLine);

    while(lastLine != nullptr){
        lastLine = getLineUnder(lastLine,lignes,excluded);
        if(lastLine != nullptr) t_lines->push_back(lastLine);
    }

    return t_lines;
}


sf::FloatRect* Tilemap::getRect(line* ligne, std::vector<line*>* lignes,
                                  std::vector<line*>* excluded) {
    if(ligne == nullptr) return nullptr;
    std::vector<line*>* tab = new std::vector<line*>();
    tab->push_back(ligne);

    std::vector<line*>* linesUnder = getLinesUnder(ligne,lignes,excluded);

    if(linesUnder == nullptr)
        return new sf::FloatRect(ligne->y,ligne->x,1,ligne->size);
    for(line* l : *linesUnder){
        tab->push_back(l);
    }
    return new sf::FloatRect(ligne->y,ligne->x,(tab->at(tab->size()-1)->y +1) - ligne->y,ligne->size);
}

std::vector<line*> Tilemap::cutLines(std::vector<std::vector<int>> map) {

    std::vector<line*> lignes;

    for(int y = 0; y < map.size(); y++){
        int first = 0;
        int streak = 0;
        bool lb = false;
        for(int x = 0; x < map[0].size();x++){

            if(!lb){//si on a pas peter la ligne

                if( m_tileSet.at(map[y][x]).isSolid()){
                    streak++;
                }

                if(!m_tileSet.at(map[y][x]).isSolid() && streak > 0){
                    lb = true;
                    lignes.push_back(new line{y,first,streak});
                    first = x;
                    streak = 0;
                }
            }else{
                if(m_tileSet.at(map[y][x]).isSolid()){
                    lb = false;
                    streak = 1;
                    first = x;
                }
            }
        }

        if(m_tileSet.at(map[y][map[y].size()-1]).isSolid()){
            lignes.push_back(new line{y,first,streak});
        }
    }

    return lignes;
}