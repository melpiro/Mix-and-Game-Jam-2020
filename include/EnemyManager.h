//
// Created by etien on 14/11/2020.
//

#ifndef MIXGAMEJAM2020_ENEMYMANAGER_H
#define MIXGAMEJAM2020_ENEMYMANAGER_H


#include <list>
#include "EnemyCharacter.h"

struct Projectile {
    Projectile(sf::RenderWindow *win, const sf::Vector2f &pos, const sf::Vector2f &vel) : win(win), pos(pos), vel(vel) {}
    sf::RenderWindow* win;
    sf::Vector2f pos;
    sf::Vector2f vel;
    float lifeTime = 2, currentLifeTime = 0;
    bool dead = false;
    void update(float dt);
    void draw() const;
};

class EnemyManager {

    static std::map<int, EnemyCharacter*> enemies;
    static std::list<Projectile> projectiles;


public:
    static void addEnemy(EnemyCharacter* enemy);
    static void killEnemy(int id);

    static void addProjectile(Projectile projectile);

    static void update(float dt);
    static void draw();
    static void event(sf::Event& e);

    static void loadEnemiesFromFiles(const std::string& path, sf::RenderWindow* win, PlayerCharacter* character);

    static void setTileMap(Tilemap *tilemap);
};


#endif //MIXGAMEJAM2020_ENEMYMANAGER_H
