#pragma once
#include "SFML/Graphics.hpp"
#include "Omega/Math/GeometricFunctions.h"
#include "Operators/PrintFunctions.h"
#include "Tilemap.h"
#include "Piece.hpp"

struct Item
{
    Item() {this->x = 0, this->y = 0, type = PIECE::J; }
    Item(float x, float y, PIECE type) {this->x = x, this->y = y, this->type = type;}
    float x;
    float y;
    PIECE type;
    sf::Color coul;
    int rotation;
}; 


class ItemManager
{
public:
    ItemManager(sf::FloatRect rect, int nbMaxItem);

    void setTileMap(Tilemap* map);
    void init();
    

    void pickItem(sf::FloatRect playerRect);
    std::vector<Item>& getItems();
    std::vector<Item>& getMyItems();
    static const float ITEM_SPACING;
    static const float ITEM_SIZE;

    bool haveChanged();

    void removeInventoryItem(int index);
    void addItemInInventory(Item item);

    void setPeuzeulPoly(std::vector<sf::Vector2f>& poly);
private:

    void addItemRdm();
    bool canAdd(Item it);

    std::vector<Item> m_allItems;
    sf::FloatRect playerRectCpy;
    Tilemap* m_map;

    sf::FloatRect m_rect;
    int nbItem;
    int nbMaxItem;

    bool m_haveChanged = false;

    std::vector<Item> m_inventory;
    int MAX_INV_ITEM = 30;

    std::vector<sf::Vector2f> m_peuzeulpoly;


};
