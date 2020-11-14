#include "MainGame.hpp"

MainGame::MainGame(sf::RenderWindow* fen) :
    m_tetrisTest(fen),
    m_character(fen),
    m_enemy(fen, &m_character),
    m_enemy2(fen, &m_character)
{
    m_fen=fen;

    m_object.setSize(sf::Vector2f(100,100));
    m_object.setFillColor(sf::Color::Red);
    m_object.setOrigin(50,50); // center
    m_object.setPosition(500,500);


    m_tetrisTest.setPosition(50,50);
    m_tetrisTest.setWindowSize(150,300);
    m_tetrisTest.setTileSize(10,20);

    m_enemy.setPos({500, 500});
    m_enemy2.setPos({800, 500});
}

void MainGame::init()
{
    m_character.init();
    m_enemy.init();
    m_enemy2.init();

    m_tetrisTest.start();
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

    m_tetrisTest.event(e);

    m_character.event(e);
    m_enemy.event(e);
    m_enemy2.event(e);
}
void MainGame::update(float dt)
{

    m_view.setCenter(m_character.getPos());
    m_fen->setView(m_view);

    m_tetrisTest.update();
    m_character.update(dt);
    m_enemy.update(dt);
    m_enemy2.update(dt);

    m_timeForTetrisAnimeTest += 0.01;
    m_tetrisTest.setPosition(std::cos(m_timeForTetrisAnimeTest) * 20 + 50, std::sin(m_timeForTetrisAnimeTest) * 20 + 50);
    m_tetrisTest.setWindowSize((std::cos(m_timeForTetrisAnimeTest) + 1) * 15.0*5.0 + 150, (std::cos(m_timeForTetrisAnimeTest) + 1) * 30.0*5.0 + 300 );
    
}
void MainGame::render()
{
    m_fen->draw(m_object);

    m_tetrisTest.render();
    m_enemy.draw();
    m_enemy2.draw();
    m_character.draw();
}

void MainGame::updateOnResize()
{
    m_view.setSize((sf::Vector2f) m_fen->getSize() * m_viewZoom);
}
