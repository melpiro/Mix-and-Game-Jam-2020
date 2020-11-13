//
// Created by Alarm on 13/11/2020.
//

#include <iostream>
#include "Tile.h"

Tile::Tile(sf::Texture &tilePic):
m_nbrOfSprite(1,1),
m_spacing(0),
m_animSpeed(0),
m_currentFrame(0),
m_frameCount(1)
{
     // pour savoir combien de frame max on a
    m_img = sf::Sprite(tilePic);
}

Tile::Tile(sf::Texture &tile, sf::Vector2i nbrOfSprite, int spacing, long animSpeed):
m_nbrOfSprite(nbrOfSprite),
m_spacing(spacing),
m_animSpeed(animSpeed),
m_currentFrame(0)
{
    m_img = sf::Sprite(tile);
    m_frameCount = m_nbrOfSprite.x * nbrOfSprite.y;
}

Tile::Tile(sf::Texture &tilePic, int ScaleFactor):
m_nbrOfSprite(1,1),
m_spacing(0),
m_animSpeed(0),
m_currentFrame(0),
m_frameCount(1){
    m_img = sf::Sprite(tilePic);
    m_img.setScale(ScaleFactor,ScaleFactor);
}

void Tile::draw(float x,float y,sf::RenderWindow* fen) {
    if(m_frameCount == 1){
        //TODO : faire l'affichage simple d'un sprite
        m_img.setPosition(x,y);
        fen->draw(m_img);
    }else{
        //TODO: gérer les sprite animés
    }
}

void Tile::update() {
    //TODO: gerer l'avancement des anim
}

int Tile::getTextureSize() {
    return m_img.getTexture()->getSize().x*m_img.getScale().x;
}

void Tile::setSolid(bool state) {
    m_isSolid = state;
}
