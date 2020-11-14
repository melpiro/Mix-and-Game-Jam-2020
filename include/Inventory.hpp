#pragma once
#include <SFML/Graphics.hpp>
#include "Graphics/Sprite.h"
#include "ItemManager.hpp"

class Inventory
{

public:
    Inventory(sf::RenderWindow* fen,  float* viewZoom, ItemManager* manager);

    void init();


    void event(sf::Event e);
    void update();
    void render();

private:

    void updateOnResize();
    void updateRender();
    void openAnime();
    void closeAnime();

    bool m_isOpen = false;
    bool m_openAnimate = false;
    bool m_closeAnimate = false;
    const float MOVE_SPEED = 40.f;
    float backgroundDelta = 0;
    const float backgroundDeltaMax = 350;

    sf::RenderWindow* m_fen;
    float* m_viewZoom;

    O::graphics::Sprite m_invBackground;
    O::graphics::Sprite m_invIcon;

    ItemManager* m_itemManager;
    
};



