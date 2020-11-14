#include "MainGame.hpp"

MainGame::MainGame(sf::RenderWindow* fen) :
    m_character(fen),
    m_enemy(fen, &m_character),
    m_enemy2(fen, &m_character),
    m_inventory(fen, &m_viewZoom),
    m_itemManager(sf::FloatRect(-1000,-1000,2000,2000), 30),
    m_itemDrawer(fen, &m_itemManager)
{
    m_fen=fen;

    m_enemy.setPos({500, 500});
    m_enemy2.setPos({800, 500});
}

void MainGame::init()
{
    m_character.init();
    m_enemy.init();
    m_enemy2.init();
    m_inventory.init();
    m_itemDrawer.init();

}

void MainGame::event(sf::Event e)
{
    if (e.type == sf::Event::Resized)
    {
        updateOnResize();
    }
    else if (e.type == sf::Event::MouseWheelMoved)
    {
        if (e.mouseWheel.delta > 0)
        {
             m_viewZoom /= cam_zoom_factor;
             m_view.zoom(1.f/cam_zoom_factor);
        }
        else if (e.mouseWheel.delta < 0)
        {
            m_viewZoom *= cam_zoom_factor;
            m_view.zoom(cam_zoom_factor);
        }
        
    }


    m_character.event(e);
    m_enemy.event(e);
    m_enemy2.event(e);
    m_inventory.event(e);
    m_itemDrawer.event(e);
}
void MainGame::update(float dt)
{

    m_view.setCenter(m_character.getPos());
    m_fen->setView(m_view);

    m_character.update(dt);
    m_enemy.update(dt);
    m_enemy2.update(dt);

    m_inventory.update();
    m_itemDrawer.update();

    m_itemManager.pickItem(m_character.getRect());

}
void MainGame::render()
{
    m_enemy.draw();
    m_enemy2.draw();
    m_character.draw();
    m_inventory.render();
}

void MainGame::updateOnResize()
{
    m_view.setSize((sf::Vector2f) m_fen->getSize() * m_viewZoom);
}
