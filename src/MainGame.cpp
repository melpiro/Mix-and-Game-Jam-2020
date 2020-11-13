#include "MainGame.hpp"

MainGame::MainGame(sf::RenderWindow* fen)
{
    m_fen=fen;


    m_persoTest.setSize(sf::Vector2f(100,100));
    m_persoTest.setFillColor(sf::Color::Blue);
    m_persoTest.setOrigin(50,50); // center

    m_object.setSize(sf::Vector2f(100,100));
    m_object.setFillColor(sf::Color::Red);
    m_object.setOrigin(50,50); // center
    m_object.setPosition(500,500);
}

void MainGame::init()
{

}

void MainGame::event(sf::Event e)
{
    if (e.type == sf::Event::Resized)
    {
        updateOnResize(e);
    }
    else if (e.type == sf::Event::KeyPressed)
    {
        if (e.key.code == sf::Keyboard::Left)
        {
            m_left = true;
        }
        else if (e.key.code == sf::Keyboard::Right)
        {
            m_right = true;
        }
        else if (e.key.code == sf::Keyboard::Up)
        {
            m_up = true;
        }
        else if (e.key.code == sf::Keyboard::Down)
        {
            m_down = true;
        }
    }
    else if (e.type == sf::Event::KeyReleased)
    {
        if (e.key.code == sf::Keyboard::Left)
        {
            m_left = false;
        }
        else if (e.key.code == sf::Keyboard::Right)
        {   
            m_right = false;
        }
        else if (e.key.code == sf::Keyboard::Up)
        {
            m_up = false;
        }
        else if (e.key.code == sf::Keyboard::Down)
        {
            m_down = false;
        }
    }
    else if (e.type == sf::Event::MouseWheelMoved)
    {
        std::cout << e.mouseWheel.delta <<std::endl;
        if (e.mouseWheel.delta > 0)
        {
             m_viewZoom /= zoom_factor;
             m_view.zoom(1.f/zoom_factor);
        }
        else if (e.mouseWheel.delta < 0)
        {
            m_viewZoom *= zoom_factor;
            m_view.zoom(zoom_factor);
        }
        
    }
    

}
void MainGame::update()
{
    if (m_left)
    {
        m_persoTest.move(-speed,0);
    }
    else if (m_right)
    {
        m_persoTest.move(speed,0);
    }
    else if (m_up)
    {
        m_persoTest.move(0,-speed);
    }
    else if (m_down)
    {
        m_persoTest.move(0,speed);
    }
    m_view.setCenter(m_persoTest.getPosition());
    m_fen->setView(m_view);
}
void MainGame::render()
{
    m_fen->draw(m_persoTest);
    m_fen->draw(m_object);
}

void MainGame::updateOnResize(sf::Event& e)
{
    m_view.setSize(e.size.width * m_viewZoom, e.size.height * m_viewZoom);
}
