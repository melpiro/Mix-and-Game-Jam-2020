#include "WinMenu.hpp"

WinMenu::WinMenu(sf::RenderWindow* fen) : 
    m_title(fen, "mainFont", STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HEIGHT, STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HEIGHT, true)
{
    m_fen=fen;

    m_title.setString(O::graphics::ressourceManager.text(5));
    m_title.setCharacterSize(50);
}

void WinMenu::init()
{
    m_title.loadFont();
}

void WinMenu::event(sf::Event e)
{
    if (e.type == sf::Event::Resized)
    {
        updateOnResize();
    }

    m_title.event(e);
}
void WinMenu::update()
{

}
void WinMenu::render()
{
    m_title.draw();
}

void WinMenu::updateOnResize()
{
    
}
