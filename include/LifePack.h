//
// Created by Alarm on 15/11/2020.
//

#ifndef MIXGAMEJAM2020_LIFEPACK_H
#define MIXGAMEJAM2020_LIFEPACK_H


#include "Object.h"
#include "PlayerCharacter.h"

class LifePack  : public Object{

public:

    LifePack(float healAmount,sf::Vector2f pos,sf::RenderWindow* fen, PlayerCharacter* hero);

     void init() override;
     void draw() override;
     void update(float deltatime) override;
     void event(sf::Event &e) override;



private:

    float m_healAmount;
    PlayerCharacter* m_hero;
    sf::Sprite m_spr;


};


#endif //MIXGAMEJAM2020_LIFEPACK_H
