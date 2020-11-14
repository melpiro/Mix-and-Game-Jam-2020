#include "App.hpp"

App::App() :
    m_fen(sf::VideoMode(1200,1000),"App"),
    m_loadingMenu(&m_fen),
    m_mainMenu(&m_fen),
    m_mainGame(&m_fen)
{
    m_fen.setFramerateLimit(60);
    m_th_load_ressources = std::async(std::launch::async, &App::loadRessources, this);

    //sf::View v(sf::FloatRect(100,100,2000,1000));
    //m_fen.setView(v);
}


void App::loadRessources()
{
    O::graphics::ressourceManager.loadAllRessources();

    // on charge les menu après les textures !! très important
    m_loadingMenu.init();
    m_mainMenu.init();
    m_mainGame.init();

    m_step = GAME;
    m_mainGame.updateOnResize();
}

void App::run()
{
    sf::Clock dtclock;

    while (m_fen.isOpen())
    {
        float dt = dtclock.restart().asSeconds();

        event();
        update(dt);
        render();
    }
    
}

void App::event()
{
    sf::Event e;
    while (m_fen.pollEvent(e))
    {
        if (e.type==sf::Event::Closed)
        {
            m_fen.close();
        }
        else if (e.type == sf::Event::Resized)
        {
            if (m_step != GAME) // si c'est linterface
            {
                // redimention classique
                sf::FloatRect visibleArea(0, 0, e.size.width, e.size.height);
			    m_fen.setView(sf::View(visibleArea));
            }
            // sinon, c'est la class main game qui s'en occupe
            
        }
        if (m_step == LOADING_MENU)
        {
            m_loadingMenu.event(e);
        }
        else if (m_step == MAIN_MENU)
        {
            m_step = m_mainMenu.event(e);
            if(m_step == GAME) {
                m_mainGame.reset();
                m_mainGame.updateOnResize();
            }
        }
        else if (m_step == GAME)
        {
            m_mainGame.event(e);
        }
    }
}

void App::update(float dt)
{
    if (m_step == LOADING_MENU)
    {
        m_loadingMenu.update();
    }
    else if (m_step == MAIN_MENU)
    {
        m_mainMenu.update(dt);
    }
    else if (m_step == GAME)
    {
        m_step = m_mainGame.update(dt);
    }
}

void App::render()
{
    m_fen.clear();

    if (m_step == LOADING_MENU)
    {
        m_loadingMenu.render();
    }
    else if (m_step == MAIN_MENU)
    {
        m_mainMenu.render();
    }
    else if (m_step == GAME)
    {
        m_mainGame.render();
    }

    m_fen.display();
}