//
// Created by etien on 14/11/2020.
//

#ifndef MIXGAMEJAM2020_SPITTERENEMY_H
#define MIXGAMEJAM2020_SPITTERENEMY_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <PlayerCharacter.h>

class SpitterEnemy : public EnemyCharacter {

public:
    SpitterEnemy(sf::RenderWindow *fen, PlayerCharacter *pc);

    void init() override;
};


#endif //MIXGAMEJAM2020_SPITTERENEMY_H
