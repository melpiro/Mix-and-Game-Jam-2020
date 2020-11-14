#include <EnemyManager.h>
#include <Enemies/SpitterEnemy.h>
#include <Step.hpp>
#include "MainGame.hpp"

MainGame::MainGame(sf::RenderWindow* fen) :
    m_character(fen),
    m_inventory(fen, &m_viewZoom, &m_itemManager),
    m_itemManager(sf::FloatRect(0, 0, 50 * 16 * 4,50 * 16 * 4), 30),
    m_itemDrawer(fen, &m_itemManager),
    m_peuzeul(fen, &m_itemManager)
{
    m_fen=fen;

}

void MainGame::init()
{
    m_character.init();
    m_inventory.init();
    m_itemDrawer.init();


    EnemyManager::loadEnemiesFromFiles("resources/data/map1.json", m_fen, &m_character);
    

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

    m_peuzeul.setPositon(sf::Vector2i(22,12));
    m_peuzeul.polygon(std::vector<sf::Vector2i> {
        sf::Vector2i(0,0),
        sf::Vector2i(6,0),
        sf::Vector2i(6,1),
        sf::Vector2i(7,1),
        sf::Vector2i(7,2),
        sf::Vector2i(8,2),
        sf::Vector2i(8,3),
        sf::Vector2i(7,3),
        sf::Vector2i(7,4),
        sf::Vector2i(1,4),
        sf::Vector2i(1,3),
        sf::Vector2i(0,3)
    });


    m_healthBar = O::graphics::ChargingBar(m_fen, 0, 0, m_character.getRect().width*0.7f, m_character.getRect().height*0.1f);
    m_healthBar.setMaxChargingValue(m_character.getLife());
    m_healthBar.setMinChargingValue(0);
    m_healthBar.setOutlineColor(sf::Color::Black);
    m_healthBar.setBackgroundColor(sf::Color::Red);
    m_healthBar.setForgroundColor(sf::Color::Green);
    m_healthBar.setOutlineThickness(5);
    m_healthBar.setChargingValue(m_character.getLife());
    m_healthBar.setOrigineAsCenter();

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
Step MainGame::update(float dt)
{

    auto cameraDir = m_character.getCameraPos() - m_view.getCenter();
    auto cameraNextStep = m_view.getCenter() + cameraDir * cameraSpeed;
    m_view.setCenter(cameraNextStep);
    m_fen->setView(m_view);

    m_character.update(dt);

    if(m_character.isDead())
        return MAIN_MENU;

    m_inventory.update();


    m_itemDrawer.update();

    m_itemManager.pickItem(m_character.getRect());

    EnemyManager::update(dt);

    m_map.update();

    m_peuzeul.update();

    m_healthBar.setPosition(m_character.getPos().x, m_character.getPos().y - m_character.getRect().height*0.5f);
    m_healthBar.setChargingValue(m_character.getLife());
    m_healthBar.update();


    m_peuzeul.setSelectedItemIndex(m_inventory.getSelectedItemIndex());



    return GAME;
}

void MainGame::render()
{
    m_map.draw();
    m_peuzeul.render();
    m_itemDrawer.render();

    EnemyManager::draw();

    m_character.draw();
    m_inventory.render();


    m_healthBar.draw();
}

void MainGame::updateOnResize()
{
    m_view.setSize((sf::Vector2f) m_fen->getSize() * m_viewZoom);
}

void MainGame::reset() {
    EnemyManager::reset();

    m_character = PlayerCharacter(m_fen);
    m_inventory = Inventory(m_fen, &m_viewZoom, &m_itemManager);
    m_itemManager = ItemManager(sf::FloatRect(0, 0, 50 * 16 * 4,50 * 16 * 4), 30);
    m_itemDrawer = ItemDrawer(m_fen, &m_itemManager);
    m_peuzeul = Peuzeul(m_fen, &m_itemManager);

    m_character.init();
    m_inventory.init();
    m_itemDrawer.init();

    EnemyManager::loadEnemiesFromFiles("resources/data/map1.json", m_fen, &m_character);

    m_character.setPos({16*16*4,12*16*4});
    m_character.setTileMap(&m_map);
    EnemyManager::setTileMap(&m_map);

    m_itemManager.setTileMap(&m_map);


    m_itemManager.init();

    m_peuzeul.setPositon(sf::Vector2i(22,12));
    m_peuzeul.polygon(std::vector<sf::Vector2i> {
            sf::Vector2i(0,0),
            sf::Vector2i(6,0),
            sf::Vector2i(6,1),
            sf::Vector2i(7,1),
            sf::Vector2i(7,2),
            sf::Vector2i(8,2),
            sf::Vector2i(8,3),
            sf::Vector2i(7,3),
            sf::Vector2i(7,4),
            sf::Vector2i(1,4),
            sf::Vector2i(1,3),
            sf::Vector2i(0,3)
    });


    m_healthBar = O::graphics::ChargingBar(m_fen, 0, 0, m_character.getRect().width*0.7f, m_character.getRect().height*0.1f);
    m_healthBar.setMaxChargingValue(m_character.getLife());
    m_healthBar.setMinChargingValue(0);
    m_healthBar.setOutlineColor(sf::Color::Black);
    m_healthBar.setBackgroundColor(sf::Color::Red);
    m_healthBar.setForgroundColor(sf::Color::Green);
    m_healthBar.setOutlineThickness(5);
    m_healthBar.setChargingValue(m_character.getLife());
    m_healthBar.setOrigineAsCenter();

}

