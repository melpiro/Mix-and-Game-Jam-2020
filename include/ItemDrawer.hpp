#pragma once
#include "ItemManager.hpp"

#include <SFML/Graphics.hpp>
#include <Omega/Graphics/Rectangle.h>
#include <Omega/Graphics/Sprite.h>

class ItemDrawer
{

public:
    ItemDrawer(sf::RenderWindow* fen, ItemManager* m_manager);

    void init();


    void event(sf::Event e);
    void update();
    void render();

private:

    void updateRender();

    void updateOnResize();

    sf::RenderWindow* m_fen;

    ItemManager* m_manager;

    std::vector<std::vector<O::graphics::Sprite>> m_items;

    const float CELL_SIZE = 10;
    
};
