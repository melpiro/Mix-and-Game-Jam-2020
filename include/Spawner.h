//
// Created by Alarm on 14/11/2020.
//

#ifndef MIXGAMEJAM2020_SPAWNER_H
#define MIXGAMEJAM2020_SPAWNER_H


#include "Object.h"
#include "Tilemap.h"
#include "PlayerCharacter.h"

class Spawner : public Object{

public:


    Spawner(std::string typeMob,int spawDelay,sf::Vector2f pos,Tilemap* tm,PlayerCharacter* hero,sf::RenderWindow* fen);

    void init() override;
    void draw() override;
    void update(float deltatime) override;
    void event(sf::Event &e) override;

private:
    std::string m_typeMob;
    PlayerCharacter* m_hero;
    int m_delay;
    Tilemap* m_tilemap;
    sf::Clock m_timer;
};


#endif //MIXGAMEJAM2020_SPAWNER_H
