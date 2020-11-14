#pragma once
#include <SFML/Graphics.hpp>
#include "Graphics/Sprite.h"
#include "ItemManager.hpp"
#include "Graphics/Text.h"

class Inventory
{

public:
    Inventory(sf::RenderWindow* fen,  float* viewZoom, ItemManager* manager);

    void init();


    void event(sf::Event e);
    void update();
    void render();

    int getSelectedItemIndex();
    bool haveSelectedItem();
    void openClose();

private:

    void updateOnResize();
    void updateRender();
    void openAnime();
    void closeAnime();

    bool m_isOpen = false;
    bool m_openAnimate = false;
    bool m_closeAnimate = false;
    float MOVE_SPEED = 40.f;
    float backgroundDelta = 0;
    float backgroundDeltaMax = 350;

    sf::RenderWindow* m_fen;
    float* m_viewZoom;

    O::graphics::Sprite m_invBackground;
    O::graphics::Sprite m_invIcon;
    O::graphics::Text m_title;
    float ITEM_SIZE = 45;
    float ITEM_MARGIN = 25;

    int nbItemPerLine = 3;

    ItemManager* m_itemManager;
    
    int indexItemSelected = -1;
    //Item selectedItem;
    //sf::Vector2f mousePos;
    //sf::Vector2i indexPos;

    std::vector<std::vector<O::graphics::Sprite>> m_items;
    std::vector<std::vector<sf::Vector2f>> relativItemPos;
    std::vector<float> m_itemscale;
};



