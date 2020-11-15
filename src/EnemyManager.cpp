//
// Created by etien on 14/11/2020.
//

#include <JsonData.hpp>
#include <Enemies/BlobEnemy.h>
#include <Enemies/SpitterEnemy.h>
#include <Enemies/CloneEnemy.h>
#include "EnemyManager.h"

std::map<int, EnemyCharacter*> EnemyManager::enemies;
std::list<Projectile> EnemyManager::projectiles;
Tilemap* EnemyManager::tilemap = nullptr;

void EnemyManager::addEnemy(EnemyCharacter* enemy) {
    if(tilemap != nullptr)
        enemy->setTileMap(tilemap);
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
    while (it != projectiles.end()){
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

void EnemyManager::loadEnemiesFromFiles(const std::string &path, sf::RenderWindow* win, PlayerCharacter* character) {
    JsonData json;
    json.readFile(path);

    auto data = (std::vector<JsonData>*)json["enemies"].getValue();
    for(auto enemy : *data) {
        sf::String type = *((sf::String*)enemy["type"].getValue());
        double x = *((double *)enemy["x"].getValue());
        double y = *((double *)enemy["y"].getValue());

        EnemyCharacter* e;
        if(type == "blob")
            e = new BlobEnemy(win, character);
        else if(type == "spitter")
            e = new SpitterEnemy(win, character);
        else if(type == "clone")
            e = new CloneEnemy(win, character);
        else
            e = new EnemyCharacter(win, character);

        e->init();
        e->setPos({static_cast<float>(x), static_cast<float>(y)});
        addEnemy(e);
    }
}

void EnemyManager::setTileMap(Tilemap *tilemap) {
    EnemyManager::tilemap = tilemap;
    for(auto pair : enemies)
        pair.second->setTileMap(tilemap);
}

std::list<Projectile> &EnemyManager::getProjectiles() {
    return projectiles;
}

void EnemyManager::killProjectile(int id) {
    auto it = projectiles.begin();
    while (it != projectiles.end()) {
        if(it->id == id)
            it = projectiles.erase(it);
        else
            it++;
    }
}

void EnemyManager::reset() {
    enemies.clear();
    projectiles.clear();
}

bool EnemyManager::collide(Character* character, sf::FloatRect hitbox, Character* pc) {

    //std::cout << "EnemyManager::collide : " << &pc <<std::endl;
    for (auto& e : enemies)
        if(e.second != character && hitbox.intersects(e.second->getHitbox())) {
            character->onCollide(e.second);
            e.second->onCollide(character);
            return true;
        }

    if(pc != nullptr && pc != character && hitbox.intersects(pc->getHitbox())) {
        character->onCollide(pc);
        pc->onCollide(character);
        return true;
    }

    return false;
}

const std::map<int, EnemyCharacter *> &EnemyManager::getEnemies() {
    return enemies;
}

// Projectile =================================
int Projectile::nextID = 0;

Projectile::Projectile(sf::RenderWindow *win, const sf::Vector2f &pos, const sf::Vector2f &vel) : win(win), pos(pos), vel(vel) {
    id = nextID++;
}

void Projectile::update(float dt) {
    pos += vel;
    currentLifeTime += dt;
    dead = currentLifeTime >= lifeTime;
}

void Projectile::draw() const {
    sf::RectangleShape rect({8, 8});
    rect.setFillColor(sf::Color::Red);
    rect.setPosition(pos);
    win->draw(rect);
}
