#include <EnemyManager.h>
#include <Enemies/SpitterEnemy.h>
#include "MainGame.hpp"

MainGame::MainGame(sf::RenderWindow* fen) :
    m_character(fen),
    m_inventory(fen, &m_viewZoom, &m_itemManager),
    m_itemManager(sf::FloatRect(0, 0, 50 * 16 * 4,50 * 16 * 4), 30),
    m_itemDrawer(fen, &m_itemManager),
    m_peuzeul(fen)
{
    m_fen=fen;

}

void MainGame::init()
{
    m_character.init();
    m_inventory.init();
    m_itemDrawer.init();


    EnemyManager::loadEnemiesFromFiles("resources/data/enemies1.json", m_fen, &m_character);
    

    //Initialisation de la tilemap
    std::vector<Tile> tileSet;
    tileSet.emplace_back(O::graphics::ressourceManager.getTexture("water"),sf::Vector2i(1,2),0,1500,4);
    tileSet.emplace_back(O::graphics::ressourceManager.getTexture("grass"),4);
    tileSet.emplace_back(O::graphics::ressourceManager.getTexture("bordGrass"),4);
    tileSet.emplace_back(O::graphics::ressourceManager.getTexture("murGrass"),4);
    tileSet.emplace_back(O::graphics::ressourceManager.getTexture("pontHorHaut"),4);// 4
    tileSet.emplace_back(O::graphics::ressourceManager.getTexture("pontHorBas"),4);// 5
    tileSet.emplace_back(O::graphics::ressourceManager.getTexture("pontBord"),sf::Vector2i(1,2),0,1500,4); // 6
    tileSet.emplace_back(O::graphics::ressourceManager.getTexture("pontGauche"),4);// 7
    tileSet.emplace_back(O::graphics::ressourceManager.getTexture("pontDroite"),4);// 8
    tileSet.emplace_back(O::graphics::ressourceManager.getTexture("ladder"),4);// 9


    //les tiles solides
    tileSet[0].setSolid(true);
    tileSet[2].setSolid(true);
    tileSet[3].setSolid(true);
    tileSet[6].setSolid(true);

    m_map = Tilemap(tileSet,*m_fen,"resources/data/map1.json");


    m_character.setPos({16*16*4,12*16*4});

    m_character.setTileMap(&m_map);
    EnemyManager::setTileMap(&m_map);


    m_itemManager.setTileMap(&m_map);


    m_itemManager.init();

    m_peuzeul.init();
    m_peuzeul.setPositon(sf::Vector2i(22,12));
    m_peuzeul.polygon(std::vector<sf::Vector2i> {
        sf::Vector2i(0,0),
        sf::Vector2i(2,0),
        sf::Vector2i(2,3),
        sf::Vector2i(6,3),
        sf::Vector2i(6,5),
        sf::Vector2i(3,5),
        sf::Vector2i(3,6),
        sf::Vector2i(10,6),
        sf::Vector2i(10,7),
        sf::Vector2i(5,7),
        sf::Vector2i(5,10),
        sf::Vector2i(5,15),
        sf::Vector2i(3,15),
        sf::Vector2i(-5,15),
        sf::Vector2i(-5,14),
        sf::Vector2i(-5,0),
        sf::Vector2i(-4,0),
        sf::Vector2i(-4,14),
        sf::Vector2i(3,14),
        sf::Vector2i(3,10),
        sf::Vector2i(0,10),

    });

    m_vie = O::graphics::ChargingBar(m_fen,5,5,150,30);
    m_vie.setMaxChargingValue(5);
    m_vie.setMinChargingValue(0);
    m_vie.setOutlineColor(sf::Color::Black);
    m_vie.setBackgroundColor(sf::Color::Red);
    m_vie.setOutlineThickness(5);
    m_vie.setChargingValue(m_character.getLife());

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
    else if (e.type == sf::Event::KeyPressed) {

        switch (e.key.code) {
            case sf::Keyboard::Tab:
                m_inventory.openClose();
                break;
        }

    }


    m_character.event(e);

    m_inventory.event(e);
    m_itemDrawer.event(e);

    EnemyManager::event(e);
    m_peuzeul.event(e);
}
void MainGame::update(float dt)
{

    auto cameraDir = m_character.getCameraPos() - m_view.getCenter();
    auto cameraNextStep = m_view.getCenter() + cameraDir * cameraSpeed;
    m_view.setCenter(cameraNextStep);
    m_fen->setView(m_view);

    m_character.update(dt);

    m_inventory.update();

    m_vie.setPosition(m_view.getCenter().x- (m_view.getSize().x/2) + 100,m_view.getCenter().y-(m_view.getSize().y/2)+50);

    m_itemDrawer.update();

    m_itemManager.pickItem(m_character.getRect());

    EnemyManager::update(dt);

    m_map.update();

    m_peuzeul.update();

    m_vie.update();

}
void MainGame::render()
{
    m_map.draw();
    //m_peuzeul.render();
    m_itemDrawer.render();

    m_character.draw();
    m_inventory.render();

    EnemyManager::draw();

    m_vie.draw();
}

void MainGame::updateOnResize()
{
    m_view.setSize((sf::Vector2f) m_fen->getSize() * m_viewZoom);
}

