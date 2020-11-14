//
// Created by Alarm on 13/11/2020.
//

#include "Tilemap.h"

#include <utility>
#include <iostream>
#include "Omega/Graphics/RessourceManager.h"
#include "JsonData.hpp"

Tilemap::Tilemap(sf::Vector2i dimensions, std::vector<Tile> tileset,sf::RenderWindow &fen): m_dimensions(dimensions),m_tileSet(std::move(tileset)){
    m_tileSize = m_tileSet[0].getTextureSize();
    m_fen = &fen;
}

Tilemap::Tilemap(std::vector<Tile> tileset, sf::RenderWindow &fen, std::string path):m_tileSet(std::move(tileset)){
    m_tileSize = m_tileSet[0].getTextureSize();
    m_fen = &fen;
    //TODO : Faire la lecture dans le fichier demandé
    loadlevelFromFile(path);
}

void Tilemap::draw() {

    for(int y = 0; y < m_dimensions.y ; y++ ){
        for(int x = 0; x < m_dimensions.x; x++){
            m_tileSet[m_map[y][x]].draw(x*m_tileSize,y*m_tileSize,m_fen);
        }
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
    return std::vector<sf::FloatRect>();
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
}

/*def getLinesUnder(a_line,a_lines,a_excludeList):
    if a_line == None:
        return None

    lastLine = getLineUnder(a_line,a_lines,a_excludeList)
    lines = []

    if lastLine == None:
        return None
    else:
        lines.append(lastLine)

    while lastLine != None:
        lastLine = getLineUnder(lastLine,a_lines,a_excludeList)
        if lastLine != None: lines.append(lastLine)
    return lines*/
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

/*def getRect(a_line,a_lines,a_excludedLines):
    if a_line == None: return None
    tab = []
    tab.append(a_line)
    linesUnders = getLinesUnder(a_line,a_lines,a_excludedLines)

    if linesUnders == None:
        return (a_line[0],a_line[1],1,a_line[2])

    for line in linesUnders:
        tab.append(line)
    return (a_line[0],a_line[1],(tab[len(tab)-1][0]+1) - a_line[0],a_line[2])*/

sf::FloatRect* Tilemap::getRect(line* ligne, std::vector<line*>* lignes,
                                  std::vector<line*>* excluded) {
    if(ligne == nullptr) return nullptr;
    std::vector<line*>* tab = new std::vector<line*>();
    tab->push_back(ligne);

    std::vector<line*>* linesUnder = getLinesUnder(ligne,lignes,excluded);

    /*if(linesUnder == nullptr)
        return new sf::FloatRect(ligne->y,ligne->x,ligne->size);*/
}
