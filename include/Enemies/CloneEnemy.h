//
// Created by etien on 15/11/2020.
//

#ifndef MIXGAMEJAM2020_CLONEENEMY_H
#define MIXGAMEJAM2020_CLONEENEMY_H

#include "EnemyCharacter.h"

class CloneEnemy : public EnemyCharacter {

    enum Phase {
        Attack,
        Flee
    };

    Phase phase = Attack;

public:
    CloneEnemy(sf::RenderWindow *fen, PlayerCharacter *pc);

    void init() override;

    void onCollide(Character *other) override;

    Type getType() override;

    void update(float deltatime) override;

    void applyDamage(float dmg) override;
};


#endif //MIXGAMEJAM2020_CLONEENEMY_H
