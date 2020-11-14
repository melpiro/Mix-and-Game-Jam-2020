#include "MainMenu.hpp"

MainMenu::MainMenu(sf::RenderWindow* fen) :
    m_background(fen, "loadingMenuBackground", STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HEIGHT, STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HEIGHT, true),
    m_bouttonJouer(fen,"mainFont",STATIC::SYS::HALF_WIDTH,500,300,100,STATIC::SYS::HALF_WIDTH,STATIC::SYS::HALF_HEIGHT,true),
    m_titre(fen,"titreJeu",STATIC::SYS::HALF_WIDTH,200,true)
{
    m_fen=fen;
 
}

void MainMenu::init()
{
    m_background.loadTexture();
    m_titre.loadTexture();
    m_titre.setScale(3,3);
    m_titre.setPointRedi((m_fen->getSize().x/2) + 350,200);

    //m_bouttonJouer = O::graphics::Button(m_fen,"mainFont",(m_fen->getSize().x/2) + 350,500,100,50);
    m_bouttonJouer.loadFont();
    m_bouttonJouer.setString(O::graphics::ressourceManager.text(4));
    m_bouttonJouer.setTextColor(sf::Color::Black);
    m_bouttonJouer.setFillColor(sf::Color(133, 130, 130));
}

Step MainMenu::event(sf::Event e)
{
    if (e.type == sf::Event::Resized)
    {
        updateOnResize();
    }

    m_background.event(e);
    m_bouttonJouer.event(e);

    if(m_bouttonJouer.clicked(e)){
        return GAME;
    }

    return MAIN_MENU;
}
void MainMenu::update(float dt)
{
    m_titre.update();
    m_bouttonJouer.update();

    auto pos = m_titre.getPosition();
    m_titre.setPosition(pos.x,pos.y + m_pxDir*dt);

    if(m_pxDir > 0 && pos.y >= m_pxAnimMax){
        m_pxDir = -m_pxDir;
    } else if(m_pxDir < 0 && pos.y <= m_pxAnimMin){
        m_pxDir = -m_pxDir;
    }

}
void MainMenu::render()
{
    m_background.draw();
    m_titre.draw();
    m_bouttonJouer.draw();

}

void MainMenu::updateOnResize()
{
    
}
