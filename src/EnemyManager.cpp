//
// Created by etien on 14/11/2020.
//

#include "EnemyManager.h"

std::map<int, EnemyCharacter*> EnemyManager::enemies;

void EnemyManager::addEnemy(EnemyCharacter* enemy) {
    enemies.insert(std::make_pair(enemy->getId(), enemy));
}

void EnemyManager::killEnemy(int id) {
    delete enemies[id];
    enemies.erase(id);
}

void EnemyManager::update(float dt) {
    for(auto pair : enemies)
        pair.second->update(dt);
}

void EnemyManager::draw() {
    for(auto pair : enemies)
        pair.second->draw();
}

void EnemyManager::event(sf::Event &e) {
    for(auto pair : enemies)
        pair.second->event(e);
}
