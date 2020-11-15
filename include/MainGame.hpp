#pragma once
#ifndef MAINHAME_HPP
#define MAINHAME_HPP

#include <SFML/Graphics.hpp>
#include "Omega/Operators/PrintFunctions.h"
#include "Omega/Graphics/RessourceManager.h"
#include "Omega/Graphics/ChargingBar.h"
#include "PlayerCharacter.h"
#include "EnemyCharacter.h"
#include "Inventory.hpp"
#include "ItemDrawer.hpp"
#include "Enemies/BlobEnemy.h"
#include "Tilemap.h"
#include "Peuzeul.hpp"
#include "Omega/Math/Graph.h"
#include "Step.hpp"

class MainGame
{

public:
    MainGame(sf::RenderWindow* fen);

    void init();


    void event(sf::Event e);
    Step update(float dt);
    void render();


    void updateOnResize();


    void reset(const std::string& path = "");

    void initGraph(std::string path);

private:

    sf::RenderWindow* m_fen;

    sf::View m_view;
    float m_viewZoom = 1.f;
    float cameraSpeed = 0.1f;

    float m_timeForTetrisAnimeTest;


    float cam_speed= 5.f;
    float cam_zoom_factor= 1.5f;

    PlayerCharacter m_character;

    Tilemap m_map;


    Inventory m_inventory;
    ItemManager m_itemManager;
    ItemDrawer m_itemDrawer;
    Peuzeul m_peuzeul;

    bool m_endReset = true;

  


};


#endif