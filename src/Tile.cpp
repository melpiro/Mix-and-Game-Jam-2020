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

Tile::Tile(sf::Texture &tile, sf::Vector2i nbrOfSprite, int spacing, long animSpeed,int SizeFactor):
m_nbrOfSprite(nbrOfSprite),
m_spacing(spacing),
m_animSpeed(animSpeed),
m_currentFrame(0)
{
    m_img = sf::Sprite(tile);
    m_img.setScale(SizeFactor,SizeFactor);
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
        m_img.setPosition(x,y);
        fen->draw(m_img);
    }else{
        m_img.setPosition(x,y);
        int size = m_img.getTexture()->getSize().x/m_nbrOfSprite.x;
        if(m_nbrOfSprite.y == 1){
            m_img.setTextureRect(sf::IntRect((m_currentFrame)*size,0,size,size));
        }else if(m_nbrOfSprite.x == 1){
            m_img.setTextureRect(sf::IntRect(0,(m_currentFrame)*size,size,size));
        }else{
            m_img.setTextureRect(sf::IntRect((m_currentFrame % m_nbrOfSprite.x)*size,(m_currentFrame / m_nbrOfSprite.y)*size,size,size));
        }
        fen->draw(m_img);
    }
}

void Tile::update() {
    if(m_frameCount == 1) return;
    if(m_animClock.getElapsedTime().asMilliseconds() > m_animSpeed){
        m_currentFrame++;
        m_currentFrame %= m_frameCount;
        std::cout << m_currentFrame << std::endl;

        m_animClock.restart();
    }


}

int Tile::getTextureSize() {
    return m_img.getTexture()->getSize().x*m_img.getScale().x;
}

void Tile::setSolid(bool state) {
    m_isSolid = state;
}

bool Tile::isSolid() {
    return m_isSolid;
}
