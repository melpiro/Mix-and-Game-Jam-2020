#include "Inventory.hpp"

Inventory::Inventory(sf::RenderWindow* fen, float* viewZoom, ItemManager* manager) :
    m_invBackground(fen, "inventoryBackground", 0, 0, false),
    m_invIcon(fen, "boxIcon", 0, 0, true),
    m_viewZoom(viewZoom),
    m_itemManager(manager)
{
    m_fen=fen;
    m_invBackground.setColor(sf::Color(255,255,230));
}

void Inventory::init()
{
    m_invBackground.loadTexture();
    m_invIcon.loadTexture();
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
    sf::View v = m_fen->getView();
    sf::Vector2f pos = v.getCenter() + sf::Vector2f(v.getSize().x, 0) * 0.5f - (sf::Vector2f(150.f, 800.f/2.f) + sf::Vector2f(backgroundDelta, 0)) * (*m_viewZoom);
    m_invBackground.setPosition(pos.x, pos.y);
    m_invBackground.setScale(*m_viewZoom, *m_viewZoom);
    m_invIcon.setPosition(pos.x + (200.0 / 2.0) * (*m_viewZoom), pos.y + (800.0 / 2.0) * (*m_viewZoom));
    m_invIcon.setScale(*m_viewZoom / 10.0, *m_viewZoom / 10.0);

    if (m_itemManager->haveChanged())
    {
        updateRender();
    }

    openAnime();
    closeAnime();
}
void Inventory::render()
{
    m_invBackground.draw();
    m_invIcon.draw();
}

void Inventory::updateOnResize()
{
    
}

void Inventory::updateRender()
{

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