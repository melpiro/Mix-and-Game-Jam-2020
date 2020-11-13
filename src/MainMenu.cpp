#include "MainMenu.hpp"

MainMenu::MainMenu(sf::RenderWindow* fen) :
    m_background(fen, "loadingMenuBackground", STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HIGHT, STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HIGHT, true),
    m_titre(fen, "mainFont", STATIC::SYS::HALF_WIDTH, 100, STATIC::SYS::HALF_WIDTH, 100, true)
{
    m_fen=fen;

    m_titre.setString(O::graphics::ressourceManager.text(2));
    m_titre.setCharacterSize(50);

 
}

void MainMenu::init()
{
    m_background.loadTexture();
    m_titre.loadFont();

}

void MainMenu::event(sf::Event e)
{
    if (e.type == sf::Event::Resized)
    {
        updateOnResize();
    }

    m_background.event(e);
    m_titre.event(e);
}
void MainMenu::update()
{


}
void MainMenu::render()
{
    m_background.draw();
    m_titre.draw();

}

void MainMenu::updateOnResize()
{
    
}
