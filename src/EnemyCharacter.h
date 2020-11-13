//
// Created by etien on 13/11/2020.
//

#ifndef MIXGAMEJAM2020_ENEMYCHARACTER_H
#define MIXGAMEJAM2020_ENEMYCHARACTER_H


#include "Character.h"

class PlayerCharacter;

class EnemyCharacter : public Character {

    PlayerCharacter* player;
    bool isAttacking = false;

    float agroDist = 100;

public:

    EnemyCharacter(sf::RenderWindow *fen, PlayerCharacter* pc);

    void init() override;
    void update(float deltatime) override;
};


#endif //MIXGAMEJAM2020_ENEMYCHARACTER_H
