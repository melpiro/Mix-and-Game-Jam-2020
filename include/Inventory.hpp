#pragma once
#include <SFML/Graphics.hpp>
#include "Graphics/Sprite.h"

class Inventory
{

public:
    Inventory(sf::RenderWindow* fen,  float* viewZoom);

    void init();


    void event(sf::Event e);
    void update();
    void render();

private:

    void updateOnResize();

    sf::RenderWindow* m_fen;
    float* m_viewZoom;

    O::graphics::Sprite m_invBackground;
    O::graphics::Sprite m_invIcon;
    
};



