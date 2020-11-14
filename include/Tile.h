//
// Created by Alarm on 13/11/2020.
//

#ifndef MIXGAMEJAM2020_TILE_H
#define MIXGAMEJAM2020_TILE_H


#include <SFML/Graphics.hpp>

class Tile {

public:
    //constructeur pour une image simple
    Tile(sf::Texture &tilePic);

    Tile(sf::Texture &tilePic,int SizeFactor);

    //constructeur pour init une tile avec plusieurs frame d'animation
    Tile(sf::Texture &tile, sf::Vector2i nbrOfSprite, int spacing,long animSpeed, int SizeFactor);

    void draw(float x, float y,sf::RenderWindow* fen);

    void update();


    int getTextureSize();

    void setSolid(bool state);
    bool isSolid();

private:

    sf::Sprite m_img;

    long m_animSpeed;
    int m_spacing;
    int m_currentFrame;
    int m_frameCount;
    bool m_isSolid = false;
    sf::Vector2i m_nbrOfSprite;

    sf::Clock m_animClock;


};


#endif //MIXGAMEJAM2020_TILE_H
