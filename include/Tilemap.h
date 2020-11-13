//
// Created by Alarm on 13/11/2020.
//

#ifndef MIXGAMEJAM2020_TILEMAP_H
#define MIXGAMEJAM2020_TILEMAP_H

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Tile.h"

class Tilemap {

public:
    Tilemap();


private:

    sf::Vector2i m_dimensions;
    sf::Vector2f m_position;

    std::vector<Tile> m_tileSet;

    std::vector<std::vector<int>> m_map;

};


#endif //MIXGAMEJAM2020_TILEMAP_H
