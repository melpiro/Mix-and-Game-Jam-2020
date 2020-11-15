#include <MusicManager.h>
#include "App.hpp"

App::App() :
    m_fen(sf::VideoMode(1200,800),"Tetradventure"),
    m_loadingMenu(&m_fen),
    m_mainMenu(&m_fen),
    m_mainGame(&m_fen),
    m_winMenu(&m_fen),
    m_tutoMenu(&m_fen)
{
    m_fen.setFramerateLimit(60);

    if(icon.loadFromFile("resources/Graphics/icon.png")) {
        m_fen.setIcon(64, 64, icon.getPixelsPtr());
    }

    m_th_load_ressources = std::async(std::launch::async, &App::loadRessources, this);

}


void App::loadRessources()
{
    O::graphics::ressourceManager.loadAllRessources();

    // on charge les menu après les textures !! très important
    m_loadingMenu.init();
    m_mainMenu.init();
    m_mainGame.init();
    m_winMenu.init();
    m_tutoMenu.init();

    m_step = MAIN_MENU;
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
            else if(m_step == GOTOLVL1) {
                m_mainGame.reset("resources/data/map0.json");
                m_mainGame.updateOnResize();
                m_step = GAME;
            }
            else if(m_step == GOTOLVL2) {
                m_mainGame.reset("resources/data/map1.json");
                m_mainGame.updateOnResize();
                m_step = GAME;
            }
            else if(m_step == GOTOLVL3) {
                m_mainGame.reset("resources/data/map2.json");
                m_mainGame.updateOnResize();
                m_step = GAME;
            }
        }
        else if (m_step == GAME)
        {
            m_mainGame.event(e);
        }
        else if (m_step == WIN_MENU)
        {
            m_step = m_winMenu.event(e);
            if(m_step == GAME) {
                m_winMenu.currentLvl++;
                if(m_winMenu.currentLvl < m_winMenu.nbrLvl)
                    m_mainGame.reset("resources/data/map" + std::to_string(m_winMenu.currentLvl) + ".json");
            }
        }
        else if(m_step == TUTO_MENU){
            m_step = m_tutoMenu.event(e);
            if(m_step == MAIN_MENU) {
                m_tutoMenu.reset();
                m_tutoMenu.updateOnResize();
            }
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
        if (m_step != GAME) {
            sf::FloatRect visibleArea(0, 0, m_fen.getSize().x, m_fen.getSize().y);
            m_fen.setView(sf::View(visibleArea));
            m_winMenu.updateOnResize();
            m_mainMenu.updateOnResize();
        }
    }
    else if (m_step == WIN_MENU)
    {
        m_winMenu.update();
    }else if(m_step == TUTO_MENU){
        m_tutoMenu.update(dt);
    }


    if (m_lastStep != m_step)
    {
        m_lastStep = m_step;
        m_fen.setSize(m_fen.getSize()-sf::Vector2u(1,1));
        m_fen.setSize(m_fen.getSize()+sf::Vector2u(1,1));
    }

    MusicManager::update(dt);
}

void App::render()
{
    m_fen.clear(sf::Color(10,83,165));

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
    else if (m_step == WIN_MENU)
    {
        m_winMenu.render();
    }else if(m_step == TUTO_MENU){
        m_tutoMenu.render();
    }

    m_fen.display();
}