//
// Created by etien on 14/11/2020.
//

#ifndef MIXGAMEJAM2020_SPITTERENEMY_H
#define MIXGAMEJAM2020_SPITTERENEMY_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <PlayerCharacter.h>

class SpitterEnemy : public EnemyCharacter {

    float shootDistance = 300;

    float fireRate = 0.9f;
    float fireRateTime = 0;

public:
    SpitterEnemy(sf::RenderWindow *fen, PlayerCharacter *pc);

    void init() override;

    void update(float deltatime) override;

    Type getType() override;
};


#endif //MIXGAMEJAM2020_SPITTERENEMY_H
