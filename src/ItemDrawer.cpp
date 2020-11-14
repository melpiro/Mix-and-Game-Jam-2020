#include "ItemDrawer.hpp"

ItemDrawer::ItemDrawer(sf::RenderWindow* fen, ItemManager* manager) :
    m_manager(manager)
{
    m_fen=fen;
}

void ItemDrawer::init()
{
    updateRender();
}

void ItemDrawer::event(sf::Event e)
{
    if (e.type == sf::Event::Resized)
    {
        updateOnResize();
    }
}
void ItemDrawer::update()
{
    if (m_manager->haveChanged())
    {
        updateRender();
    }
}
void ItemDrawer::render()
{
    for (size_t i = 0; i < m_items.size(); i++)
    {
        for (size_t j = 0; j < m_items[i].size(); j++)
        {
            m_items[i][j].draw();
        }
    }
}

void ItemDrawer::updateOnResize()
{
    
}

void ItemDrawer::updateRender()
{
    m_items.clear();
    for (size_t i = 0; i < m_manager->getItems().size(); i++)
    {

        float nbCellX = allPiece[(int)m_manager->getItems()[i].type][m_manager->getItems()[i].rotation].back().size();
        float nbCellY = allPiece[(int)m_manager->getItems()[i].type][m_manager->getItems()[i].rotation].size();
        float cell_size;
        float deltaXForCenter = 0;
        float deltaYForCenter = 0;

        cell_size = std::min(ItemManager::ITEM_SIZE / nbCellX, ItemManager::ITEM_SIZE / nbCellY);

        std::vector<O::graphics::Sprite> item;
        for (size_t y = 0; y < allPiece[(int)m_manager->getItems()[i].type][m_manager->getItems()[i].rotation].size(); y++)
        {
            for (size_t x = 0; x < allPiece[(int)m_manager->getItems()[i].type][m_manager->getItems()[i].rotation].back().size(); x++)
            {
                if (allPiece[(int)m_manager->getItems()[i].type][m_manager->getItems()[i].rotation][y][x] )
                {
                    item.push_back(O::graphics::Sprite(m_fen, "tetrisCell", 0,0));
                    item.back().loadTexture();
                    item.back().setPosition(m_manager->getItems()[i].x + x *cell_size, m_manager->getItems()[i].y + y * cell_size);
                    item.back().setScale(cell_size / (float)O::graphics::ressourceManager.getTexture("tetrisCell").getSize().x, cell_size / (float)O::graphics::ressourceManager.getTexture("tetrisCell").getSize().y);
                    item.back().setColor(m_manager->getItems()[i].coul);
                }
                
            }
        }
        m_items.push_back(item);
    }
    
}