//
// Created by etien on 13/11/2020.
//

#include <Omega/Graphics/RessourceManager.h>
#include "EnemyManager.h"
#include "Character.h"

int Character::nextID = 0;
Character* Character::player = nullptr;

Character::Character(sf::RenderWindow* fen) : fen(fen),  m_healthBar(fen, 0, 0, 0, 0){
    id = nextID++;
}

void Character::initHealthBar() {
    m_healthBar.setSize(getRect().width*0.7f, getRect().height*0.1f);
    m_healthBar.setMaxChargingValue(life);
    m_healthBar.setMinChargingValue(0);
    m_healthBar.setOutlineColor(sf::Color::Black);
    m_healthBar.setBackgroundColor(sf::Color::Red);
    m_healthBar.setForgroundColor(sf::Color::Green);
    m_healthBar.setOutlineThickness(5);
    m_healthBar.setChargingValue(life);
    m_healthBar.setOrigineAsCenter();
}

void Character::draw() {

    setAnim();
    fen->draw(sprite);

    m_healthBar.draw();
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


    if(m_map != nullptr)
    {
        auto nextpos = pos + vel * deltatime;
        auto bound = getHitbox();

        auto nextBoundX = bound;
        nextBoundX.left = nextpos.x - bound.width/2.0;

        if (m_map->intersectSolidArea(nextBoundX) || EnemyManager::collide(this, nextBoundX, player)) {
            vel.x = 0;
        }
        
        auto nextBoundY = bound;
        nextBoundY.top = nextpos.y;
        if (m_map->intersectSolidArea(nextBoundY) || EnemyManager::collide(this, nextBoundY, player)) {
            vel.y = 0;
        }

        
    }
    pos += vel * deltatime;

    sprite.setPosition(pos);


    vel *= dash +1;
    dash *= friction;

    vel *= friction;

    currentDashTime += deltatime;

    m_healthBar.setPosition(pos.x, pos.y - getRect().height*0.5f);
    m_healthBar.update();
}

void Character::event(sf::Event &e) {

}

void Character::setTileMap(Tilemap* map)
{
    m_map = map;

    m_graphNodePos = m_map->getGraphNodePos();
    m_mapGraph = m_map->getGraph();
}

float Character::getLife() const {
    return life;
}

void Character::kill() {
    dead = true;
}

bool Character::isDead() const {
    return dead;
}

void Character::applyDamage(float dmg) {
    life -= dmg;
    m_healthBar.setChargingValue(life);
    if(life <= 0)
        kill();
}

sf::FloatRect Character::getHitbox() const {
    auto bound = sprite.getGlobalBounds();
    bound.height /= 2.0;
    bound.width /= 2.0;
    bound.top +=bound.height;
    bound.left += bound.width*0.5f;
    return bound;
}

int Character::getId() const {
    return id;
}


void Character::init() {

}

void Character::onCollide(Character *other) {

}
