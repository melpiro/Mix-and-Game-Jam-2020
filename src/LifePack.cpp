//
// Created by Alarm on 15/11/2020.
//

#include <ObjectManager.h>
#include "LifePack.h"

void LifePack::init() {
    Object::init();
}

void LifePack::draw() {
    Object::draw();

    m_spr.setPosition(m_pos);
    m_fen->draw(m_spr);
}

void LifePack::update(float deltatime) {
    Object::update(deltatime);

    if(m_hero->getHitbox().intersects(m_collider)){
        m_hero->heal(m_healAmount);
        ObjectManager::delObject(m_myId);
    }
}

void LifePack::event(sf::Event &e) {
    Object::event(e);
}

LifePack::LifePack(float healAmount,sf::Vector2f  pos, sf::RenderWindow *fen, PlayerCharacter *hero) {
    m_pos = pos;
    m_fen = fen;
    m_healAmount = healAmount;
    m_collider = {m_pos.x, m_pos.y, 48,48};
    m_spr = sf::Sprite(O::graphics::ressourceManager.getTexture("lifePack"));
    m_spr.setScale({3,3});
    m_hero = hero;


}
