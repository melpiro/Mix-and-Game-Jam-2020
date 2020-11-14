//
// Created by etien on 14/11/2020.
//

#ifndef MIXGAMEJAM2020_BLOBENEMY_H
#define MIXGAMEJAM2020_BLOBENEMY_H


#include "EnemyCharacter.h"

class BlobEnemy : public EnemyCharacter {

public:
    BlobEnemy(sf::RenderWindow *fen, PlayerCharacter *pc);

    void init() override;
};


#endif //MIXGAMEJAM2020_BLOBENEMY_H
