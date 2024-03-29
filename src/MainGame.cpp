#include <EnemyManager.h>
#include <Enemies/SpitterEnemy.h>
#include <Step.hpp>
#include <MusicManager.h>
#include "MainGame.hpp"
#include "ObjectManager.h"

MainGame::MainGame(sf::RenderWindow* fen) :
    m_character(fen),
    m_inventory(fen, &m_viewZoom, &m_itemManager),
    m_itemManager(sf::FloatRect(0, 0, 50 * 16 * 4,50 * 16 * 4), 30),
    m_itemDrawer(fen, &m_itemManager),
    m_peuzeul(fen, &m_itemManager),
    m_textExplain(fen,"mainFont", 1410,600, true)
{
    m_fen=fen;

    m_textExplain.setString(O::graphics::ressourceManager.text(9));
    m_textExplain.gT().setFillColor(sf::Color::White);
    m_textExplain.setCharacterSize(65); 
}

void MainGame::init()
{

    ObjectManager::init();

    MusicManager::init();
    MusicManager::getMusic("explore")->play();
    MusicManager::getMusic("fight")->play();
    MusicManager::getMusic("fight")->setVolume(0);
    MusicManager::getMusic("explore")->setVolume(75);

    MusicManager::getMusic("explore")->setLoop(true);
    MusicManager::getMusic("fight")->setLoop(true);

    m_textExplain.loadFont();


    //std::cout << "MainGame::init : " << &m_character <<std::endl;
}

void MainGame::event(sf::Event e)
{
    ObjectManager::event(e);
    if (e.type == sf::Event::Resized)
    {
        updateOnResize();
    }else if (e.type == sf::Event::KeyPressed) {

        switch (e.key.code) {
            case sf::Keyboard::Tab:
                m_inventory.openClose();
                break;
        }
    }

    // else if (e.type == sf::Event::MouseWheelMoved)
    // {
    //     if (e.mouseWheel.delta > 0)
    //     {
    //         m_viewZoom *= cam_zoom_factor;
    //         m_view.zoom(cam_zoom_factor);
    //         m_fen->setView(m_view);
    //     }
    //     else if (e.mouseWheel.delta < 0)
    //     {
    //         m_viewZoom /= cam_zoom_factor;
    //         m_view.zoom(1.0/cam_zoom_factor);
    //         m_fen->setView(m_view);
    //     }
    // }

    m_character.event(e);

    ///////////////////////////////////////////////////////////////
    // ALERTE DANGER DE MORT :
    // m_peuzeul.event(e);  doit etre fait avant  
    // m_inventory.event(e);
    m_peuzeul.event(e); 
    m_inventory.event(e);
    m_itemDrawer.event(e);

    EnemyManager::event(e);
}
Step MainGame::update(float dt)
{
    if(!m_endReset)return GAME;

    auto cameraDir = m_character.getCameraPos() - m_view.getCenter();
    auto cameraNextStep = m_view.getCenter() + cameraDir * cameraSpeed;
    m_view.setCenter(cameraNextStep);
    m_fen->setView(m_view);

    m_character.update(dt);

    if(m_character.isDead()) {
        MusicManager::fadeTo("explore", 75);
        MusicManager::fadeTo("fight", 0);
        return MAIN_MENU;
    }

    if(m_character.isAttacked()) {
        MusicManager::fadeTo("explore", 0);
        MusicManager::fadeTo("fight", 100);
    }
    else {
        MusicManager::fadeTo("explore", 75);
        MusicManager::fadeTo("fight", 0);
    }

    m_inventory.update();

    m_itemDrawer.update();

    m_itemManager.pickItem(m_character.getRect());

    EnemyManager::update(dt);

    m_map.update();

    m_peuzeul.update();


    ObjectManager::update(dt);

    m_peuzeul.setSelectedItemIndex(m_inventory.getSelectedItemIndex());


    if (m_peuzeul.isWin())
    {
        return WIN_MENU;
    }

    return GAME;
}

void MainGame::render()
{
    m_map.draw();

    if (m_mapZero)
        m_textExplain.draw();

    m_peuzeul.render();
    m_itemDrawer.render();

    

    EnemyManager::draw();

    ObjectManager::draw();

    m_character.draw();
    m_inventory.render();


}

void MainGame::updateOnResize()
{
    m_view.setSize((sf::Vector2f) m_fen->getSize() * m_viewZoom);
}

void MainGame::reset(const std::string& path) {

    if(path.empty()){
        m_mapZero = true;
        reset("resources/data/map0.json");
        return;
    }
    if (path == "resources/data/map0.json")
        m_mapZero = true;
    else m_mapZero = false;

    m_endReset = false;

    EnemyManager::reset();
    ObjectManager::reset();


    m_character = PlayerCharacter(m_fen);
    m_inventory = Inventory(m_fen, &m_viewZoom, &m_itemManager);
    m_itemManager = ItemManager(sf::FloatRect(0, 0, 50 * 16 * 4,50 * 16 * 4), 30);
    m_itemDrawer = ItemDrawer(m_fen, &m_itemManager);
    m_peuzeul = Peuzeul(m_fen, &m_itemManager);



    m_character.init();
    m_inventory.init();
    m_itemDrawer.init();



    JsonData j;
    j.readFile(path);
    float x = *((double *)j["heroStart"]["x"].getValue());
    float y = *((double *)j["heroStart"]["y"].getValue());
    m_character.setPos({ x*16*4,y*16*4});
    m_character.setTileMap(&m_map);
    EnemyManager::setTileMap(&m_map);




    EnemyManager::loadEnemiesFromFiles(path, m_fen, &m_character);


    //Initialisation de la tilemap
    std::vector<Tile> tileSet;
    tileSet.emplace_back(O::graphics::ressourceManager.getTexture("water"),sf::Vector2i(1,2),0,1500,4);//0
    tileSet.emplace_back(O::graphics::ressourceManager.getTexture("grass"),4);//1
    tileSet.emplace_back(O::graphics::ressourceManager.getTexture("bordGrass"),4);//2
    tileSet.emplace_back(O::graphics::ressourceManager.getTexture("murGrass"),4);//3
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

    m_map = Tilemap(tileSet,*m_fen,path);

    ObjectManager::setHero(&m_character);
    ObjectManager::setFen(m_fen);
    ObjectManager::setTileMap(&m_map);
    ObjectManager::loadObjectsFromFile(path);

    m_peuzeul.init(path);
    m_itemManager.setTileMap(&m_map);
    m_itemManager.init(m_character.getHitbox());


    //std::cout << "MainGame::reset : " << &m_character <<std::endl;
    m_endReset = true;

}

// ---------------------------------- GRAPH



