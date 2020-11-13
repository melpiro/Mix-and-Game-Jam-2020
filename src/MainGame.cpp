#include "MainGame.hpp"
#include "Omega/Graphics/RessourceManager.h"

MainGame::MainGame(sf::RenderWindow* fen)
{
    m_fen=fen;




}

void MainGame::init()
{
    std::vector<Tile> v;

    for(int i = 0; i < 5; i++){
        v.emplace_back(O::graphics::ressourceManager.getTexture("t"+std::to_string(i)),10);
    }

    v.emplace_back(O::graphics::ressourceManager.getTexture("test"),sf::Vector2i(2,2),0,1000,10);
    v.emplace_back(O::graphics::ressourceManager.getTexture("test2"),sf::Vector2i(3,1),0,100,10);

    std::vector<std::vector<int>> tmpMap = {
            {0,1,2,3,0},
            {0,1,3,1,0},
            {0,0,2,3,0},
            {0,1,0,3,0},
            {0,1,2,6,5},
    };
    m_tmap = Tilemap(sf::Vector2i(5,5),v,*m_fen);
    m_tmap.setTMap(tmpMap);
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
    m_tmap.update();
}
void MainGame::render()
{
    m_tmap.draw();
}

void MainGame::updateOnResize()
{
    
}
