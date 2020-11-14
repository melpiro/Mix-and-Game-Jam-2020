//
// Created by etien on 14/11/2020.
//

#ifndef MIXGAMEJAM2020_ENEMYMANAGER_H
#define MIXGAMEJAM2020_ENEMYMANAGER_H


#include "EnemyCharacter.h"

class EnemyManager {

    static std::map<int, EnemyCharacter*> enemies;


public:
    static void addEnemy(EnemyCharacter* enemy);
    static void killEnemy(int id);

    static void update(float dt);
    static void draw();
    static void event(sf::Event& e);

};


#endif //MIXGAMEJAM2020_ENEMYMANAGER_H
