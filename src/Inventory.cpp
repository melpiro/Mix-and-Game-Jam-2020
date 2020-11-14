#include "Inventory.hpp"

Inventory::Inventory(sf::RenderWindow* fen, float* viewZoom) :
    m_invBackground(fen, "inventoryBackground", 0, 0, false),
    m_invIcon(fen, "boxIcon", 0, 0, true),
    m_viewZoom(viewZoom)
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
}
void Inventory::update()
{
    sf::View v = m_fen->getView();
    sf::Vector2f pos = v.getCenter() + sf::Vector2f(v.getSize().x, 0) * 0.5f - sf::Vector2f(150.f, 800.f/2.f) * (*m_viewZoom);
    m_invBackground.setPosition(pos.x, pos.y);
    m_invBackground.setScale(*m_viewZoom, *m_viewZoom);
    m_invIcon.setPosition(pos.x + (200.0 / 2.0) * (*m_viewZoom), pos.y + (800.0 / 2.0) * (*m_viewZoom));
    m_invIcon.setScale(*m_viewZoom / 10.0, *m_viewZoom / 10.0);
}
void Inventory::render()
{
    m_invBackground.draw();
    m_invIcon.draw();
}

void Inventory::updateOnResize()
{
    
}
