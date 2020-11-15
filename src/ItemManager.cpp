#include "ItemManager.hpp"

ItemManager::ItemManager(sf::FloatRect rect, int nbMaxItem)
{
    m_rect = rect;
    this->nbMaxItem = nbMaxItem;

    
}

void ItemManager::init()
{
    for (size_t i = 0; i < nbMaxItem; i++)
    {
        addItemRdm();
    }
}

void ItemManager::pickItem(sf::FloatRect playerRect)
{
    playerRectCpy = playerRect;
    if (m_inventory.size() < MAX_INV_ITEM)
    {
        m_haveChanged = false;
        std::vector<Item> pickedItems;
        sf::Vector2f playerRectPos(playerRect.left, playerRect.top);
        sf::Vector2f playerRectSize(playerRect.width, playerRect.height);
        for (size_t i = 0; i < m_allItems.size(); i++)
        {
            sf::Vector2f itemPos(m_allItems[i].x, m_allItems[i].y);
            if (O::math::geo2d::intersect_AABB_AABB(playerRectPos, playerRectSize, sf::Vector2f(itemPos.x, itemPos.y), sf::Vector2f(ITEM_SIZE, ITEM_SIZE)))
            {
                pickedItems.push_back(m_allItems[i]);
                m_allItems.erase(m_allItems.begin() + i);
                i--;
                if (m_inventory.size() >= MAX_INV_ITEM) break;
            }
        }
        for (size_t i = 0; i < pickedItems.size(); i++)
        {
            addItemRdm();
            m_inventory.push_back(pickedItems[i]);
        }
    }
}

std::vector<Item>& ItemManager::getItems()
{
    return m_allItems;
}
std::vector<Item>& ItemManager::getMyItems()
{
    return m_inventory;
}

void ItemManager::addItemRdm()
{

    Item it;
    do
    {
        sf::Vector2f pos;
        it.x = O::math::rdm::randFloat(m_rect.left, m_rect.left + m_rect.width);
        it.y = O::math::rdm::randFloat(m_rect.top, m_rect.top + m_rect.height);
        it.type = (PIECE) O::math::rdm::randInt(0, NB_PIECE);
        it.coul= COLORS[O::math::rdm::randInt(0, COLORS.size())];
        it.rotation = O::math::rdm::randInt(0, 4);
    } while (!canAdd(it));
    
    
    m_allItems.push_back(it);


    m_haveChanged = true;
}

void ItemManager::setTileMap(Tilemap* map)
{
    m_map = map;
}


bool ItemManager::canAdd(Item it)
{
    if (m_map->intersectSolidArea(sf::FloatRect(it.x, it.y, ITEM_SIZE, ITEM_SIZE)))
    {
        return false;
    }
  

    if (O::math::geo2d::intersect_AABB_cercle(
        sf::Vector2f(playerRectCpy.left, playerRectCpy.top),
        sf::Vector2f(playerRectCpy.width, playerRectCpy.height), sf::Vector2f(it.x, it.y), PLAYER_SPACING)) return false;


    for (size_t i = 0; i < m_allItems.size(); i++)
    {
        if (O::math::geo2d::intersect_cercle_cercle(
            sf::Vector2f(m_allItems[i].x, m_allItems[i].y), ITEM_SPACING,
            sf::Vector2f(it.x, it.y), ITEM_SPACING)) 
                return false;
    }

    if (O::math::geo2d::intersect_AABB_polygon(sf::Vector2f(it.x, it.y), sf::Vector2f(ITEM_SIZE, ITEM_SIZE), m_peuzeulpoly))
    {
        return false;
    }

    return true;
}

bool ItemManager::haveChanged()
{
    return m_haveChanged;
}

void ItemManager::removeInventoryItem(int index)
{
    m_inventory.erase(m_inventory.begin() + index);
    m_haveChanged = true;
}


void ItemManager::addItemInInventory(Item item)
{
    m_inventory.push_back(item);
    m_haveChanged = true;
}

void ItemManager::setPeuzeulPoly(std::vector<sf::Vector2f>& poly)
{
    m_peuzeulpoly = poly;
}
const float ItemManager::ITEM_SPACING = 50;
const float ItemManager::ITEM_SIZE = 50;
const float ItemManager::PLAYER_SPACING = 500;
