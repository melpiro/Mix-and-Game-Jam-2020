//
// Created by Alarm on 13/11/2020.
//

#ifndef MIXGAMEJAM2020_TILEMAP_H
#define MIXGAMEJAM2020_TILEMAP_H

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Tile.h"
#include "Omega/Math/GeometricFunctions.h"
#include "Omega/Math/Graph.h"
#include "JsonData.hpp"
#include "Omega/Graphics/Line.h"

struct line{
    int y;
    int x;
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

    bool intersectSolidArea(sf::Vector2f point);
    bool intersectSolidArea(sf::FloatRect rect);
    std::vector<std::pair<sf::Vector2f,std::pair<sf::Vector2f,sf::Vector2f>>> crossSolidArea(sf::FloatRect rect);

    std::map<int, sf::Vector2i>* getGraphNodePos();
    O::math::Graph<int>* getGraph();


    std::vector<O::graphics::Line> m_edgeDebug;
    std::vector<sf::CircleShape> m_nodesDebug;

    sf::Vector2f getSize();


    std::pair<bool, sf::FloatRect> intersectSolidAreaGetRect(sf::FloatRect rect);

private:


    void initGraph(JsonData& j);


    line* getLineUnder(line* ligne, std::vector<line*>* lignes,std::vector<line*>* excluded);
    std::vector<line*>* getLinesUnder(line* ligne, std::vector<line*>* lignes,std::vector<line*>* excluded);
    sf::FloatRect* getRect(line* ligne, std::vector<line*>* lignes,std::vector<line*>* excluded);
    std::vector<line*> cutLines(std::vector<std::vector<int>> map);

    //pour le test
    std::vector<sf::FloatRect> m_rects;
    //fin

    sf::Vector2i m_dimensions;

    std::vector<Tile> m_tileSet;

    std::vector<std::vector<int>> m_map;

    sf::RenderWindow* m_fen;

    int m_tileSize{};

    int idCollid;

    std::map<int, sf::Vector2i> m_graphNodePos;
    O::math::Graph<int> m_mapGraph;

};


#endif //MIXGAMEJAM2020_TILEMAP_H
