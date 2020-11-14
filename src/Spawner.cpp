//
// Created by Alarm on 14/11/2020.
//

#include <EnemyCharacter.h>
#include <Enemies/BlobEnemy.h>
#include <EnemyManager.h>
#include <Enemies/SpitterEnemy.h>
#include "Spawner.h"

void Spawner::init() {
    Object::init();
}

void Spawner::draw() {
    Object::draw();
    sf::RectangleShape rec = sf::RectangleShape({m_pos.x,m_pos.y});
    rec.setSize({10,10});
    rec.setFillColor(sf::Color::Black);
    m_fen->draw(rec);
}

void Spawner::update(float deltatime) {
    Object::update(deltatime);

    if(m_timer.getElapsedTime().asSeconds() > m_delay){
        //TODO spawn d'un monstre
        EnemyCharacter* e;

        float xp , yp;
        do{
            xp = O::math::rdm::randFloat(-10,10);
            yp = O::math::rdm::randFloat(-10,10);
        }while (m_tilemap->intersectSolidArea({xp,yp}));


        if(m_typeMob == "blob"){
            e = new BlobEnemy(m_fen,m_hero);
        }else if(m_typeMob == "spitter"){
            e = new SpitterEnemy(m_fen,m_hero);
        }

        e->setPos({xp,yp});
        e->setTileMap(m_tilemap);
        EnemyManager::addEnemy(e);
        m_timer.restart();
    }
}

void Spawner::event(sf::Event &e) {
    Object::event(e);
}

Spawner::Spawner(std::string typeMob, int spawDelay, sf::Vector2f pos,Tilemap* tm,PlayerCharacter* hero, sf::RenderWindow* fen) {
    m_typeMob = typeMob;
    m_delay = spawDelay;
    m_pos = pos;
    m_fen = fen;
    m_tilemap = tm;
    m_hero = hero;

    m_collider = {m_pos.x,m_pos.y,10,10};

}
