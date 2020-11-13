#include "MainGame.hpp"

MainGame::MainGame(sf::RenderWindow* fen) :
    m_character(fen),
    m_enemy(fen, &m_character)
{
    m_fen=fen;

    m_object.setSize(sf::Vector2f(100,100));
    m_object.setFillColor(sf::Color::Red);
    m_object.setOrigin(50,50); // center
    m_object.setPosition(500,500);

    m_enemy.setPos({500, 500});
}

void MainGame::init()
{
    m_character.init();
    m_enemy.init();
}

void MainGame::event(sf::Event e)
{
    if (e.type == sf::Event::Resized)
    {
        updateOnResize(e);
    }

    m_character.event(e);
}
void MainGame::update(float dt)
{

    m_view.setCenter(m_character.getPos());
    m_fen->setView(m_view);

    m_character.update(dt);
    m_enemy.update(dt);
}
void MainGame::render()
{
    m_fen->draw(m_object);

    m_character.draw();
    m_enemy.draw();
}

void MainGame::updateOnResize(sf::Event& e)
{
    m_view.setSize(e.size.width * m_viewZoom, e.size.height * m_viewZoom);
}
