#include "ItemManager.hpp"

ItemManager::ItemManager(sf::FloatRect rect, int nbMaxItem)
{
    m_rect = rect;
    this->nbMaxItem = nbMaxItem;

    for (size_t i = 0; i < nbMaxItem; i++)
    {
        addItemRdm();
    }
    
}

void ItemManager::pickItem(sf::FloatRect playerRect)
{
    std::vector<Item> pickedItems;
    sf::Vector2f playerRectPos(playerRect.left, playerRect.top);
    sf::Vector2f playerRectSize(playerRect.width, playerRect.height);
    for (size_t i = 0; i < m_allItems.size(); i++)
    {
        sf::Vector2f itemPos(m_allItems[i].x, m_allItems[i].y);
        if (O::math::geo2d::intersect_AABB_cercle(playerRectPos, playerRectSize, itemPos, ITEM_SIZE))
        {
            pickedItems.push_back(m_allItems[i]);
            m_allItems.erase(m_allItems.begin() + i);
            i--;
        }
    }
    for (size_t i = 0; i < pickedItems.size(); i++)
    {
        addItemRdm();
        m_inventory.push_back(pickedItems[i]);
    }
    
}

std::vector<Item>& ItemManager::getItems()
{
    return m_allItems;
}

void ItemManager::addItemRdm()
{
    sf::Vector2f pos;
    Item it;
    it.x = O::math::rdm::randFloat(m_rect.left, m_rect.left + m_rect.width);
    it.y = O::math::rdm::randFloat(m_rect.top, m_rect.top + m_rect.height);
    it.type = (PIECE) O::math::rdm::randInt(0, NB_PIECE);

    m_allItems.push_back(it);


    m_haveChanged = true;
}

bool ItemManager::haveChanged()
{
    if (m_haveChanged)
    {

        m_haveChanged = false;
        return true;
    }
    return false;
}

const float ItemManager::ITEM_SIZE = 10;