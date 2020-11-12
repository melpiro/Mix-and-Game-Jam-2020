#include "LoadingMenu.hpp"

LoadingMenu::LoadingMenu(sf::RenderWindow* fen) :
    m_background(fen, "loadingMenuBackground", STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HIGHT, STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HIGHT, true),
    m_loadingIcon(fen, "loadIcon", STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HIGHT, STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HIGHT, true),
    m_loadingTitle(fen, "mainFont", STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HIGHT - 170, STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HIGHT, true)
{
    m_fen=fen;

    m_loadingIcon.setScale(0.2f, 0.2f);
    m_loadingIcon.setColor(sf::Color::White);

    m_loadingTitle.setString(O::graphics::ressourceManager.text(1));
    //m_loadingTitle.gT().setFillColor(sf::Color::Black);

    // l'icon de chargement et le text de chargement
    // son chargé en priorité avant tous les autres
    // pour qu'il soit présent pendant que les autres ressources
    // sont chargés
    m_loadingIcon.loadTexture();
    m_loadingTitle.loadFont();
}

void LoadingMenu::init()
{
    m_background.loadTexture();
}



void LoadingMenu::event(sf::Event e)
{
    if (e.type == sf::Event::Resized)
    {
        updateOnResize();
    }
    m_background.event(e);
    m_loadingIcon.event(e);
    m_loadingTitle.event(e);
}
void LoadingMenu::update()
{
    m_loadingIcon.gS().rotate(-2);
    
}
void LoadingMenu::render()
{
    m_background.draw();
    m_loadingIcon.draw();
    m_loadingTitle.draw();
}

void LoadingMenu::updateOnResize()
{
    
}