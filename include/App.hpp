#pragma once

#include <SFML/Graphics.hpp>
#include "Graphics/RessourceManager.h"
#include "Step.hpp"
#include "LoadingMenu.hpp"
#include <future>
#include "MainMenu.hpp"
#include "MainGame.hpp"
#include "WinMenu.hpp"


class App {

public:
    App();

    void loadRessources();

    void run();

    void event();
    void update(float dt);
    void render();


private:

    sf::RenderWindow m_fen;
    Step m_step = LOADING_MENU;
    Step m_lastStep = LOADING_MENU;

    LoadingMenu m_loadingMenu;
    MainMenu m_mainMenu;
    MainGame m_mainGame;

    WinMenu m_winMenu;


    std::future<void> m_th_load_ressources;
};