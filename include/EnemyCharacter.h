//
// Created by etien on 13/11/2020.
//

#ifndef MIXGAMEJAM2020_ENEMYCHARACTER_H
#define MIXGAMEJAM2020_ENEMYCHARACTER_H


#include "Character.h"
#include "MiniTetris.hpp"
#include "Omega/Graphics/Line.h"
class PlayerCharacter;



class EnemyCharacter : public Character {

protected:

    PlayerCharacter* player;
    bool isAttacking = false;

    MiniTetris miniTetris;

    float agroDist = 800;
    float loseAgroDist = 1000;

    // -- graph

    std::vector<int> m_path;
    int nodePlusProchePlayer = -1;
    bool m_havePath = false;

    std::vector<O::graphics::Line> m_debugPath;
    int comeFromPoint = -1;
    sf::Clock m_pathUpdater;
    sf::Time m_pathUpdateDelay = sf::seconds(1);
    sf::Vector2f pathTarget;

    

public:

    EnemyCharacter(sf::RenderWindow *fen, PlayerCharacter* pc);

    void init() override;
    void update(float deltatime) override;

    void draw() override;

    void event(sf::Event &e) override;

    MiniTetris* getMiniTetris();


    int operator==(const EnemyCharacter& other) const;
    int operator!=(const EnemyCharacter& other) const;

    void computPath(sf::Vector2f dest);


};


#endif //MIXGAMEJAM2020_ENEMYCHARACTER_H
