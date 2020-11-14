#include "MainGame.hpp"
#include "Omega/Graphics/RessourceManager.h"

MainGame::MainGame(sf::RenderWindow* fen)
{
    m_fen=fen;




}

void MainGame::init()
{
    std::vector<Tile> v;


    v.emplace_back(O::graphics::ressourceManager.getTexture("water"),sf::Vector2i(1,2),0,1500,5);
    v.emplace_back(O::graphics::ressourceManager.getTexture("grass"),5);
    v.emplace_back(O::graphics::ressourceManager.getTexture("bordGrass"),5);
    v.emplace_back(O::graphics::ressourceManager.getTexture("murGrass"),5);

    v[1].setSolid(true);
    std::vector<std::vector<int>> tmpMap = {
            {3,3,3,3,3},
            {3,0,0,0,3},
            {3,1,1,1,3},
            {3,2,2,2,3},
            {3,3,3,3,3},
    };
    m_tmap = Tilemap(v,*m_fen,"resources/data/map1.json");
    //m_tmap.setTMap(tmpMap);
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
