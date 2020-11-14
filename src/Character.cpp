//
// Created by etien on 13/11/2020.
//

#include <Omega/Graphics/RessourceManager.h>
#include "Character.h"

Character::Character(sf::RenderWindow* fen) : fen(fen) {}

void Character::init() {

}

void Character::draw() {

    setAnim();
    fen->draw(sprite);

}

void Character::setAnim() {
    if(playAnim) {
        sprite.setTextureRect(sf::Rect<int>(sprite.getTexture()->getSize().x - direction * frameSize,
                                             animY + frameSize * animStage,
                                            frameSize,
                                            frameSize));
    }
}



void Character::setPos(const sf::Vector2f &pos) {
    Character::pos = pos;
}

void Character::setVel(const sf::Vector2f &vel) {
    Character::vel = vel;
}

void Character::setSpeed(float speed) {
    Character::speed = speed;
}

void Character::setCurrentAnim(Character::Direction currentAnim) {
    Character::direction = currentAnim;
}

void Character::setPlayAnim(bool playAnim) {
    Character::playAnim = playAnim;
}

const sf::Vector2f &Character::getPos() const {
    return pos;
}

sf::FloatRect Character::getRect() const
{
    return sprite.getGlobalBounds();
}

void Character::update(float deltatime) {

    // Ici pour jouer la bonne anim en fonction de la direction de la velocité
    if(O::math::getDistance(vel) < speed)
        playAnim = false;
    else playAnim = true;

    if (std::abs(vel.y) >= std::abs(vel.x)) {
        if(vel.y >= 0)
            direction = Down;
        else
            direction = Up;
    }
    else {
        if(vel.x >= 0)
            direction = Right;
        else
            direction = Left;
    }

    if(playAnim) {
        currentAnimTime += deltatime;
        if(currentAnimTime > animSpeed) {
            animStage = (animStage + 1)%nbrFrames;
            currentAnimTime -= animSpeed;
        }
    }

    if (m_map == NULL)
        pos += vel * deltatime;
    else
    {
        auto nextpos = pos + vel * deltatime;

        auto bound = sprite.getGlobalBounds();
        bound.height /= 2.0;
        bound.top +=bound.height;

        auto nextBoundX = bound;
        nextBoundX.left = nextpos.x;
        if (m_map->intersectSolidArea(nextBoundX)) {
            vel.x = 0;
        }
        
        auto nextBoundY = bound;
        nextBoundY.top = nextpos.y;
        if (m_map->intersectSolidArea(nextBoundY)) {
            vel.y = 0;
        }
        
        pos += vel * deltatime;
    }
    
    sprite.setPosition(pos);


    vel *= dash +1;
    dash *= friction;

    vel *= friction;

    currentDashTime += deltatime;
}

void Character::event(sf::Event &e) {

}

void Character::setTileMap(Tilemap* map)
{
    m_map = map;
}