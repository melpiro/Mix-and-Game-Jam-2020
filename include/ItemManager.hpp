#pragma once
#include "SFML/Graphics.hpp"
#include "Omega/Math/GeometricFunctions.h"
#include "Operators/PrintFunctions.h"
#include "Piece.hpp"

struct Item
{
    Item() {this->x = 0, this->y = 0, type = PIECE::J; }
    Item(float x, float y, PIECE type) {this->x = x, this->y = y, this->type = type;}
    float x;
    float y;
    PIECE type;
}; 


class ItemManager
{
public:
    ItemManager(sf::FloatRect rect, int nbMaxItem);

    void pickItem(sf::FloatRect playerRect);
    std::vector<Item>& getItems();
    static const float ITEM_SIZE;

    bool haveChanged();
private:

    void addItemRdm();

    std::vector<Item> m_allItems;

    sf::FloatRect m_rect;
    int nbItem;
    int nbMaxItem;

    bool m_haveChanged = false;

    std::vector<Item> m_inventory;


};
