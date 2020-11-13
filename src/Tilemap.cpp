//
// Created by Alarm on 13/11/2020.
//

#include "Tilemap.h"

#include <utility>
#include <iostream>
#include "Omega/Graphics/RessourceManager.h"

Tilemap::Tilemap(sf::Vector2i dimensions, std::vector<Tile> tileset,sf::RenderWindow &fen): m_dimensions(dimensions),m_tileSet(std::move(tileset)){
    m_tileSize = m_tileSet[0].getTextureSize();
    m_fen = &fen;
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
