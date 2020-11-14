#pragma once
#ifndef MAINHAME_HPP
#define MAINHAME_HPP

#include <SFML/Graphics.hpp>
#include "Omega/Operators/PrintFunctions.h"
#include "Omega/Graphics/RessourceManager.h"
#include "PlayerCharacter.h"
#include "EnemyCharacter.h"
#include "Inventory.hpp"

class MainGame
{

public:
    MainGame(sf::RenderWindow* fen);

    void init();


    void event(sf::Event e);
    void update(float dt);
    void render();


    void updateOnResize();


private:

    sf::RenderWindow* m_fen;

    sf::View m_view;
    float m_viewZoom = 1.f;

    sf::RectangleShape m_object;

    float m_timeForTetrisAnimeTest;


    const float cam_speed= 5.f;
    const float cam_zoom_factor= 1.5f;

    PlayerCharacter m_character;
    EnemyCharacter m_enemy;
    EnemyCharacter m_enemy2;

    Inventory m_inventory;
};



#endif