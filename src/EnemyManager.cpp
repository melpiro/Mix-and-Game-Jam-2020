//
// Created by etien on 14/11/2020.
//

#include "EnemyManager.h"

std::map<int, EnemyCharacter*> EnemyManager::enemies;

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
}

void EnemyManager::draw() {
    for(auto pair : enemies)
        pair.second->draw();
}

void EnemyManager::event(sf::Event &e) {
    for(auto pair : enemies)
        pair.second->event(e);
}
