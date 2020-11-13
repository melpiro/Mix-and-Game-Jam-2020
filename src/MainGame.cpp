#include "MainGame.hpp"

MainGame::MainGame(sf::RenderWindow* fen)
{
    m_fen=fen;
}

void MainGame::init()
{

}

void MainGame::event(sf::Event e)
{
    if (e.type == sf::Event::Resized)
    {
        updateOnResize();
    }
}
void MainGame::update()
{

}
void MainGame::render()
{

}

void MainGame::updateOnResize()
{
    
}
