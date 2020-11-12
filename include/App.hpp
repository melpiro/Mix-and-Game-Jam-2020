#pragma once

#include <SFML/Graphics.hpp>
#include "Graphics/RessourceManager.h"
#include "Steps.hpp"
#include "LoadingMenu.hpp"
#include <future>
#include "MainMenu.hpp"

class App {

public:
    App();

    void loadRessources();

    void run();

    void event();
    void update();
    void render();


private:

    sf::RenderWindow m_fen;
    Steps m_step = LOADING_MENU;

    LoadingMenu m_loadingMenu;
    MainMenu m_mainMenu;


    std::future<void> m_th_load_ressources;
};