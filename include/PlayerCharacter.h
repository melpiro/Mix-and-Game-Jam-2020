//
// Created by etien on 13/11/2020.
//

#ifndef MIXGAMEJAM2020_PLAYERCHARACTER_H
#define MIXGAMEJAM2020_PLAYERCHARACTER_H


#include "Character.h"
#include "EnemyCharacter.h"

class PlayerCharacter : public Character {

    std::vector<EnemyCharacter*> enemiesAgro;
    size_t targetedEnemy = 0;

    float invincibilityTime = 1;
    float currentInvincibilityTime = 0;


public:

    explicit PlayerCharacter(sf::RenderWindow *fen);

    void init() override;
    void update(float deltatime) override;
    void event(sf::Event &e) override;


    void addEnemyAgro(EnemyCharacter *enemy);
    void removeEnemyAgro(EnemyCharacter *enemy);

    bool isAttacked() const;

    void draw() override;

    void applyDamage(float dmg) override;
    void heal(float amount);
    bool invincible() const;

    sf::Vector2f getCameraPos();

    Type getType() override;

private:
    float m_maxLife;

};


#endif //MIXGAMEJAM2020_PLAYERCHARACTER_H
