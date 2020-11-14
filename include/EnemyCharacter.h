//
// Created by etien on 13/11/2020.
//

#ifndef MIXGAMEJAM2020_ENEMYCHARACTER_H
#define MIXGAMEJAM2020_ENEMYCHARACTER_H


#include "Character.h"
#include "MiniTetris.hpp"

class PlayerCharacter;



class EnemyCharacter : public Character {

    static int nextID;

protected:
    int id;

    PlayerCharacter* player;
    bool isAttacking = false;

    MiniTetris miniTetris;

    float agroDist = 500;
    float loseAgroDist = 800;

public:

    EnemyCharacter(sf::RenderWindow *fen, PlayerCharacter* pc);

    void init() override;
    void update(float deltatime) override;

    void draw() override;

    void event(sf::Event &e) override;

    MiniTetris* getMiniTetris();

    int getId() const;

    int operator==(const EnemyCharacter& other) const;


};


#endif //MIXGAMEJAM2020_ENEMYCHARACTER_H
