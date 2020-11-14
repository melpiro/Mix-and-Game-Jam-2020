//
// Created by Alarm on 13/11/2020.
//

#ifndef MIXGAMEJAM2020_TILEMAP_H
#define MIXGAMEJAM2020_TILEMAP_H

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Tile.h"

struct line{
    int x;
    int y;
    int size;
};

class Tilemap {

public:

    //TODO : faire un constructeur qui prend un fichier pour load une map
    //en attendant la map sera hardcodée

    Tilemap();
    Tilemap(sf::Vector2i dimensions,std::vector<Tile> m_Tileset,sf::RenderWindow &fen);
    Tilemap(std::vector<Tile> m_Tileset,sf::RenderWindow &fen,std::string path);


    void draw();

    void update();

    void setTMap(std::vector<std::vector<int>> tmap);

    void loadlevelFromFile(std::string path);

    std::vector<sf::FloatRect> getColliders(); // retourne toutes les zones de collision de la map

private:


    line* getLineUnder(line* ligne, std::vector<line*>* lignes,std::vector<line*>* excluded);
    std::vector<line*>* getLinesUnder(line* ligne, std::vector<line*>* lignes,std::vector<line*>* excluded);
    sf::FloatRect* getRect(line* ligne, std::vector<line*>* lignes,std::vector<line*>* excluded);

    sf::Vector2i m_dimensions;

    std::vector<Tile> m_tileSet;

    std::vector<std::vector<int>> m_map;

    sf::RenderWindow* m_fen;

    int m_tileSize{};

};


#endif //MIXGAMEJAM2020_TILEMAP_H
