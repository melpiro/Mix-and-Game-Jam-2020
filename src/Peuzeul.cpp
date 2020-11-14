#include "Peuzeul.hpp"

Peuzeul::Peuzeul(sf::RenderWindow* fen)
{
    m_fen=fen;
}

void Peuzeul::init()
{

}

void Peuzeul::event(sf::Event e)
{
    if (e.type == sf::Event::Resized)
    {
        updateOnResize();
    }
}
void Peuzeul::update()
{

}
void Peuzeul::render()
{

}

void Peuzeul::updateOnResize()
{
    
}


void polygon(std::vector<sf::Vector2i> poly)
{
    
}