//
// Created by etien on 13/11/2020.
//

#ifndef MIXGAMEJAM2020_PLAYERCHARACTER_H
#define MIXGAMEJAM2020_PLAYERCHARACTER_H


#include "Character.h"
#include "EnemyCharacter.h"

class PlayerCharacter : public Character {

    EnemyCharacter* enemyAgro;

public:

    explicit PlayerCharacter(sf::RenderWindow *fen);

    void init() override;
    void update(float deltatime) override;
    void event(sf::Event &e) override;

    EnemyCharacter *getEnemyAgro() const;
    void setEnemyAgro(EnemyCharacter *enemyAgro);

    bool isAttacked();
};


#endif //MIXGAMEJAM2020_PLAYERCHARACTER_H
