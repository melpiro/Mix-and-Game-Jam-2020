#include "Inventory.hpp"

Inventory::Inventory(sf::RenderWindow* fen, float* viewZoom, ItemManager* manager) :
    m_invBackground(fen, "inventoryBackground", 0, 0, false),
    m_invIcon(fen, "boxIcon", 0, 0, true),
    m_viewZoom(viewZoom),
    m_itemManager(manager),
    m_title(fen, "mainFont", 0, 0, true)
{
    m_fen=fen;
    m_invBackground.setColor(sf::Color(255,255,230));

    m_title.gT().setFillColor(sf::Color::Black);
    m_title.setString(O::graphics::ressourceManager.text(3));
}

void Inventory::init()
{
    m_invBackground.loadTexture();
    m_invIcon.loadTexture();
    m_title.loadFont();
}

void Inventory::event(sf::Event e)
{
    if (e.type == sf::Event::Resized)
    {
        updateOnResize();
    }

    else if (m_invIcon.clicked(e))
    {
        m_isOpen = !m_isOpen;
        if (m_isOpen) m_openAnimate = true, m_closeAnimate = false;
        else m_openAnimate = false, m_closeAnimate = true;
    }
}

void Inventory::update()
{
    if (m_itemManager->haveChanged())
    {
        updateRender();
    }

    sf::View v = m_fen->getView();
    sf::Vector2f pos = v.getCenter() + sf::Vector2f(v.getSize().x, 0) * 0.5f - (sf::Vector2f(150.f, 800.f/2.f) + sf::Vector2f(backgroundDelta, 0)) * (*m_viewZoom);
    m_invBackground.setPosition(pos.x, pos.y);
    m_invBackground.setScale(*m_viewZoom, *m_viewZoom);
    m_invIcon.setPosition(pos.x + (200.0 / 2.0) * (*m_viewZoom), pos.y + (800.0 / 2.0) * (*m_viewZoom));
    m_invIcon.setScale(*m_viewZoom / 10.0, *m_viewZoom / 10.0);

    for (size_t i = 0; i < m_items.size(); i++)
    {
        for (size_t j = 0; j < m_items[i].size(); j++)
        {
            sf::Vector2f itemPos = relativItemPos[i][j] * (*m_viewZoom) + pos + sf::Vector2f(225, 80) * (*m_viewZoom);
            m_items[i][j].setPosition(itemPos.x, itemPos.y);
            m_items[i][j].setScale(m_itemscale[i] * (*m_viewZoom), m_itemscale[i] * (*m_viewZoom) );
        }
        
    }
    


    m_title.setCharacterSize(40* (*m_viewZoom));
    m_title.setPosition(pos.x + 325 * (*m_viewZoom), pos.y + 30 * (*m_viewZoom));

    

    openAnime();
    closeAnime();
}
void Inventory::render()
{
    m_invBackground.draw();
    m_invIcon.draw();
    m_title.draw();

    for (size_t i = 0; i < m_items.size(); i++)
    {
        for (size_t j = 0; j < m_items[i].size(); j++)
        {
            m_items[i][j].draw();
        }
        
    }
}

void Inventory::updateOnResize()
{
    
}

void Inventory::updateRender()
{
    m_items.clear();
    relativItemPos.clear();
    m_itemscale.clear();
    for (size_t i = 0; i < m_itemManager->getMyItems().size(); i++)
    {
        std::vector<O::graphics::Sprite> item;
        std::vector<sf::Vector2f> itempos;
        float nbCellX = allPiece[(int)m_itemManager->getMyItems()[i].type][m_itemManager->getMyItems()[i].rotation].back().size();
        float nbCellY = allPiece[(int)m_itemManager->getMyItems()[i].type][m_itemManager->getMyItems()[i].rotation].size();
        float cell_size;
        float deltaXForCenter = 0;
        float deltaYForCenter = 0;
        if (ITEM_SIZE / nbCellY  <  ITEM_SIZE / nbCellX)
        {
            cell_size = ITEM_SIZE / nbCellY;
            deltaXForCenter =  (ITEM_SIZE - nbCellX * cell_size) / 2.0;
        }
        else
        {

            cell_size = ITEM_SIZE / nbCellX;
            deltaYForCenter =  (ITEM_SIZE - nbCellY * cell_size) / 2.0;
        }
        
        

        for (size_t y = 0; y < allPiece[(int)m_itemManager->getMyItems()[i].type][m_itemManager->getMyItems()[i].rotation].size(); y++)
        {
            for (size_t x = 0; x < allPiece[(int)m_itemManager->getMyItems()[i].type][m_itemManager->getMyItems()[i].rotation].back().size(); x++)
            {
                if (allPiece[(int)m_itemManager->getMyItems()[i].type][m_itemManager->getMyItems()[i].rotation][y][x] )
                {
                    item.push_back(O::graphics::Sprite(m_fen, "tetrisCell", 0,0));
                    item.back().loadTexture();
                    itempos.push_back(
                        sf::Vector2f(
                            deltaXForCenter + x * cell_size  + (i % nbItemPerLine) * (ITEM_SIZE + ITEM_MARGIN),
                            deltaYForCenter + y *  cell_size + (i / nbItemPerLine) * (ITEM_SIZE + ITEM_MARGIN) ));

                    item.back().setScale(cell_size / (float)O::graphics::ressourceManager.getTexture("tetrisCell").getSize().x, cell_size / (float)O::graphics::ressourceManager.getTexture("tetrisCell").getSize().y);
                    
                    item.back().setColor(m_itemManager->getMyItems()[i].coul);

                }
                
            }
        }
        m_itemscale.push_back(cell_size / (float)O::graphics::ressourceManager.getTexture("tetrisCell").getSize().x);
        m_items.push_back(item);
        relativItemPos.push_back(itempos);
    }
}


void Inventory::openAnime()
{
    if (m_openAnimate)
    {
        backgroundDelta += MOVE_SPEED;
        if (backgroundDelta >= backgroundDeltaMax)
        {
            backgroundDelta = backgroundDeltaMax;
            m_openAnimate = false;
        }
    }
}
void Inventory::closeAnime()
{
    if (m_closeAnimate)
    {
        backgroundDelta -= MOVE_SPEED;
        if (backgroundDelta <= 0)
        {
            backgroundDelta = 0;
            m_closeAnimate = false;
        }
    }
}