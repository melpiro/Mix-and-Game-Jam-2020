#include <EnemyManager.h>
#include <Enemies/SpitterEnemy.h>
#include "MainGame.hpp"

MainGame::MainGame(sf::RenderWindow* fen) :
    m_character(fen),
    m_inventory(fen, &m_viewZoom, &m_itemManager),
    m_itemManager(sf::FloatRect(0, 0, 50 * 16 * 4,50 * 16 * 4), 30),
    m_itemDrawer(fen, &m_itemManager)
{
    m_fen=fen;

}

void MainGame::init()
{
    m_character.init();
    m_inventory.init();
    m_itemDrawer.init();

    auto* enemy = new EnemyCharacter(m_fen, &m_character);
    auto* enemy2 = new BlobEnemy(m_fen, &m_character);
    auto* enemy3 = new SpitterEnemy(m_fen, &m_character);
    enemy->init();
    enemy2->init();
    enemy3->init();
    enemy->setPos({500, 500});
    enemy2->setPos({800, 500});
    enemy3->setPos({800, 800});

    EnemyManager::addEnemy(enemy);
    EnemyManager::addEnemy(enemy2);
    EnemyManager::addEnemy(enemy3);

    //Initialisation de la tilemap
    std::vector<Tile> tileSet;
    tileSet.emplace_back(O::graphics::ressourceManager.getTexture("water"),sf::Vector2i(1,2),0,1500,4);
    tileSet.emplace_back(O::graphics::ressourceManager.getTexture("grass"),4);
    tileSet.emplace_back(O::graphics::ressourceManager.getTexture("bordGrass"),4);
    tileSet.emplace_back(O::graphics::ressourceManager.getTexture("murGrass"),4);
    tileSet.emplace_back(O::graphics::ressourceManager.getTexture("pontHorHaut"),4);// 4
    tileSet.emplace_back(O::graphics::ressourceManager.getTexture("pontHorBas"),4);// 5
    tileSet.emplace_back(O::graphics::ressourceManager.getTexture("pontBord"),sf::Vector2i(1,2),0,1500,4); // 6

    //les tiles solides
    tileSet[0].setSolid(true);
    tileSet[2].setSolid(true);
    tileSet[3].setSolid(true);
    tileSet[6].setSolid(true);

    m_map = Tilemap(tileSet,*m_fen,"resources/data/map1.json");


    m_character.setPos({16*16*4,12*16*4});

    m_character.setTileMap(&m_map);


    m_itemManager.setTileMap(&m_map);


    m_itemManager.init();



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

    m_inventory.event(e);
    m_itemDrawer.event(e);

    EnemyManager::event(e);
}
void MainGame::update(float dt)
{

    auto cameraDir = m_character.getCameraPos() - m_view.getCenter();
    auto cameraNextStep = m_view.getCenter() + cameraDir * cameraSpeed;
    m_view.setCenter(cameraNextStep);
    m_fen->setView(m_view);

    m_character.update(dt);

    m_inventory.update();
    m_itemDrawer.update();

    m_itemManager.pickItem(m_character.getRect());

    EnemyManager::update(dt);

    m_map.update();



}
void MainGame::render()
{
    m_map.draw();
    m_itemDrawer.render();

    m_character.draw();
    m_inventory.render();

    EnemyManager::draw();
}

void MainGame::updateOnResize()
{
    m_view.setSize((sf::Vector2f) m_fen->getSize() * m_viewZoom);
}
