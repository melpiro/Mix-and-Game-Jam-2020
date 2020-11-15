#include "MainMenu.hpp"

MainMenu::MainMenu(sf::RenderWindow* fen) :
    m_background(fen, "loadingMenuBackground", STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HEIGHT, STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HEIGHT, true),
    m_bouttonJouer(fen,"mainFont",STATIC::SYS::HALF_WIDTH,500,300,100,STATIC::SYS::HALF_WIDTH,STATIC::SYS::HALF_HEIGHT,true),
    m_bouttonTuto(fen,"mainFont",STATIC::SYS::HALF_WIDTH,680 + 100,300,100,STATIC::SYS::HALF_WIDTH,STATIC::SYS::HALF_HEIGHT,true),
    m_logoJam(fen, "logoJam", STATIC::SYS::WIDTH-80, STATIC::SYS::HIGHT-80, STATIC::SYS::WIDTH, STATIC::SYS::HIGHT, true),
    m_credits(fen, "credits", 170, STATIC::SYS::HIGHT-80, 0, STATIC::SYS::HIGHT, true),
    m_titre(fen,"titreJeu",STATIC::SYS::HALF_WIDTH,200,true),

    m_buttonGame0(fen, "mainFont", STATIC::SYS::HALF_WIDTH - 150, STATIC::SYS::HALF_HEIGHT + 100, 100,100, STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HEIGHT, true),
    m_buttonGame1(fen, "mainFont", STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HEIGHT + 100, 100,100, STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HEIGHT, true),
    m_buttonGame2(fen, "mainFont", STATIC::SYS::HALF_WIDTH + 150, STATIC::SYS::HALF_HEIGHT + 100, 100,100, STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HEIGHT, true)
{
    m_fen=fen;
 
}

void MainMenu::init()
{
    m_background.loadTexture();
    m_logoJam.loadTexture();
    m_credits.loadTexture();
    m_titre.loadTexture();
    m_titre.setScale(3,3);
    m_titre.setPointRedi((m_fen->getSize().x/2) + 350,200);

    //m_bouttonJouer = O::graphics::Button(m_fen,"mainFont",(m_fen->getSize().x/2) + 350,500,100,50);
    m_bouttonJouer.loadFont();
    m_bouttonJouer.setString(O::graphics::ressourceManager.text(4));
    m_bouttonJouer.setTextColor(sf::Color::Black);
    m_bouttonJouer.setFillColor(sf::Color(133, 130, 130));

    m_bouttonTuto.loadFont();
    m_bouttonTuto.setString(O::graphics::ressourceManager.text(7));
    m_bouttonTuto.setTextColor(sf::Color::Black);
    m_bouttonTuto.setFillColor(sf::Color(133, 130, 130));

    m_logoJam.setScale(0.1,0.1);


    m_buttonGame0.setString("LVL 0");
    m_buttonGame0.loadFont();
    m_buttonGame0.setFillColor(sf::Color(133, 130, 130));

    m_buttonGame1.setString("LVL 1");
    m_buttonGame1.loadFont();
    m_buttonGame1.setFillColor(sf::Color(133, 130, 130));

    m_buttonGame2.setString("LVL 2");
    m_buttonGame2.loadFont();
    m_buttonGame2.setFillColor(sf::Color(133, 130, 130));

}

Step MainMenu::event(sf::Event e)
{
    if (e.type == sf::Event::Resized)
    {
        updateOnResize();
    }

    m_background.event(e);
    m_bouttonJouer.event(e);
    m_logoJam.event(e);
    m_credits.event(e);


    if(m_bouttonJouer.clicked(e)){

        return GAME;
    }

    if(m_bouttonTuto.clicked(e)){
        return TUTO_MENU;
    }

    m_buttonGame0.event(e);
    if (m_buttonGame0.clicked(e))
    {
        //
    }
    m_buttonGame1.event(e);
    if (m_buttonGame1.clicked(e))
    {
        //
    }
    m_buttonGame2.event(e);
    if (m_buttonGame2.clicked(e))
    {
        //
    }

    return MAIN_MENU;
}
void MainMenu::update(float dt)
{
    m_titre.update();
    m_bouttonJouer.update();
    m_bouttonTuto.update();
    m_logoJam.update();
    m_credits.update();

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
    m_bouttonTuto.draw();
    m_credits.draw();
    m_logoJam.draw();

    m_buttonGame0.draw();
    m_buttonGame1.draw();
    m_buttonGame2.draw();

}

void MainMenu::updateOnResize()
{
    
}
