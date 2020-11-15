#include <Step.hpp>
#include "WinMenu.hpp"

WinMenu::WinMenu(sf::RenderWindow* fen) : 
    m_title(fen, "titleFont", STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HEIGHT*0.5f, STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HEIGHT, true),
    m_background(fen, "loadingMenuBackground", STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HEIGHT, STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HEIGHT, true),
    m_bouttonMainMenu(fen,"mainFont",STATIC::SYS::HALF_WIDTH,500,300,100,STATIC::SYS::HALF_WIDTH,STATIC::SYS::HALF_HEIGHT,true),
    m_bouttonNextLevel(fen,"mainFont",STATIC::SYS::HALF_WIDTH,680,300,100,STATIC::SYS::HALF_WIDTH,STATIC::SYS::HALF_HEIGHT,true)

{
    m_fen=fen;

    m_title.setString(O::graphics::ressourceManager.text(5));
    m_title.setCharacterSize(100);

    m_bouttonMainMenu.setString(O::graphics::ressourceManager.text(2));
    m_bouttonMainMenu.setCharacterSize(50);
    m_bouttonMainMenu.setTextColor(sf::Color::Black);
    m_bouttonMainMenu.setFillColor(sf::Color(133, 130, 130));

    m_bouttonNextLevel.setString(O::graphics::ressourceManager.text(8));
    m_bouttonNextLevel.setCharacterSize(50);
    m_bouttonNextLevel.setTextColor(sf::Color::Black);
    m_bouttonNextLevel.setFillColor(sf::Color(133, 130, 130));
}

void WinMenu::init()
{
    m_title.loadFont();
    m_bouttonMainMenu.loadFont();
    m_bouttonNextLevel.loadFont();
    m_background.loadTexture();

}

Step WinMenu::event(sf::Event e)
{
    if (e.type == sf::Event::Resized)
    {
        updateOnResize();
    }

    if(m_bouttonNextLevel.clicked(e)){
        return GAME;
    }

    if(m_bouttonMainMenu.clicked(e)){
        return MAIN_MENU;
    }

    m_title.event(e);
    m_background.event(e);
    m_bouttonMainMenu.event(e);
    if(currentLvl < nbrLvl)
        m_bouttonNextLevel.event(e);

    return WIN_MENU;
}

void WinMenu::update()
{

}
void WinMenu::render()
{
    m_background.draw();
    m_title.draw();
    m_bouttonMainMenu.draw();
    if(currentLvl < nbrLvl)
        m_bouttonNextLevel.draw();

}

void WinMenu::updateOnResize()
{
    m_title.update();
    m_background.update();
    m_bouttonMainMenu.update();
    m_bouttonNextLevel.update();
}
