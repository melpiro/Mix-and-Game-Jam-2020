//
// Created by etien on 14/11/2020.
//

#include "EnemyManager.h"

std::map<int, EnemyCharacter*> EnemyManager::enemies;
std::list<Projectile> EnemyManager::projectiles;

void EnemyManager::addEnemy(EnemyCharacter* enemy) {
    enemies[enemy->getId()] = enemy;
}

void EnemyManager::killEnemy(int id) {
    delete enemies[id];
    enemies.erase(id);
}

void EnemyManager::update(float dt) {
    auto en2 = enemies;
    for(auto pair : en2)
        enemies[pair.first]->update(dt);

    auto it = projectiles.begin();
    for (;it != projectiles.end();){
        it->update(dt);
        if(it->dead)
            it = projectiles.erase(it);
        else
            it++;
    }
}

void EnemyManager::draw() {
    for(auto pair : enemies)
        pair.second->draw();

    for(auto proj : projectiles)
        proj.draw();
}

void EnemyManager::event(sf::Event &e) {
    for(auto pair : enemies)
        pair.second->event(e);
}

void EnemyManager::addProjectile(Projectile projectile) {
    projectiles.push_back(projectile);
}

// Projectile =================================

void Projectile::update(float dt) {
    pos += vel;
    lifeTime += dt;
    dead = currentLifeTime >= lifeTime;
}

void Projectile::draw() const {
    sf::RectangleShape rect({8, 8});
    rect.setFillColor(sf::Color::Red);
    rect.setPosition(pos);
    win->draw(rect);
}
