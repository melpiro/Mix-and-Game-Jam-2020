#include "MainMenu.hpp"

MainMenu::MainMenu(sf::RenderWindow* fen) :
    m_background(fen, "loadingMenuBackground", STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HIGHT, STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HIGHT, true),
    m_titre(fen, "mainFont", STATIC::SYS::HALF_WIDTH, 100, STATIC::SYS::HALF_WIDTH, 100, true),
    
    m_rectTest(fen, STATIC::SYS::HALF_WIDTH - 450,50, 100, 50, STATIC::SYS::HALF_WIDTH - 450, 50, false),
    m_circleTest(fen, STATIC::SYS::HALF_WIDTH - 600, 50, 25, STATIC::SYS::HALF_WIDTH - 450, 50, true),
    
    m_buttonTest(fen, "mainFont", STATIC::SYS::HALF_WIDTH,  STATIC::SYS::HIGHT - 300, 300, 100, STATIC::SYS::HALF_WIDTH,  STATIC::SYS::HIGHT - 300, true),
    m_boutonTextureTest(fen, "boutonTexture", "mainFont", STATIC::SYS::HALF_WIDTH + 400,  STATIC::SYS::HIGHT - 300, STATIC::SYS::HALF_WIDTH,  STATIC::SYS::HIGHT - 300, true),

    m_chargingBarTest(fen,  STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HIGHT, 300,30, STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HIGHT, true),
    m_poucentage(fen, "mainFont",  STATIC::SYS::HALF_WIDTH + 300.0 / 2.0 + 40, STATIC::SYS::HALF_HIGHT, STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HIGHT, true),

    m_graph(fen, STATIC::SYS::HALF_WIDTH - 300, STATIC::SYS::HALF_HIGHT, 200,200, STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HIGHT, true),
    m_line(fen, sf::Vector2f(STATIC::SYS::WIDTH, 0), sf::Vector2f(STATIC::SYS::WIDTH - 100, 200), 3, STATIC::SYS::WIDTH, 0),

    m_input(fen, "mainFont", STATIC::SYS::HALF_WIDTH - 500,  STATIC::SYS::HIGHT - 800, 300, 40, STATIC::SYS::HALF_WIDTH,  STATIC::SYS::HIGHT - 300, false),
    m_textInput(fen, "mainFont", STATIC::SYS::HALF_WIDTH + 250,  STATIC::SYS::HIGHT - 1000, 300, 500, STATIC::SYS::HALF_WIDTH,  STATIC::SYS::HIGHT - 300, false)
{
    m_fen=fen;

    m_titre.setString(O::graphics::ressourceManager.text(2));
    m_titre.setCharacterSize(50);

    m_buttonTest.setString(O::graphics::ressourceManager.text(3));
    m_buttonTest.gT().setCharacterSize(15);
    m_buttonTest.setColorOnHover(sf::Color::Transparent, sf::Color(255,255,255, 150));
    m_buttonTest.setOutlineColorOnHover(sf::Color::White, sf::Color::White);
    m_buttonTest.setOutlineThickness(3);

    m_boutonTextureTest.setString(O::graphics::ressourceManager.text(4));
    m_boutonTextureTest.gT().setFillColor(sf::Color::Black);
    m_boutonTextureTest.setCharacterSize(30);

    m_chargingBarTest.setBackgroundColor(sf::Color::Black);
    m_chargingBarTest.setForgroundColor(sf::Color::Red);
    m_chargingBarTest.setMinChargingValue(0);
    m_chargingBarTest.setMaxChargingValue(1);
    m_chargingBarTest.setOutlineColor(sf::Color::White);
    m_chargingBarTest.setOutlineThickness(3);

    m_graph.addCourbe("test", sf::Color::Green, 200);
}

void MainMenu::init()
{
    m_background.loadTexture();
    m_titre.loadFont();

    m_buttonTest.loadFont();

    m_poucentage.loadFont();

    m_boutonTextureTest.loadRessources();

    m_input.loadFont();
    m_textInput.loadFont();
}

void MainMenu::event(sf::Event e)
{
    if (e.type == sf::Event::Resized)
    {
        updateOnResize();
    }

    if (m_buttonTest.clicked(e))
    {
        std::cout << "je suis le bouton qui parle" <<std::endl;
    }

    if (m_boutonTextureTest.clicked(e))
    {
        std::cout << "m_boutonTextureTest cliqued !" <<std::endl;
    }


    m_background.event(e);
    m_titre.event(e);

    m_rectTest.event(e);
    m_circleTest.event(e);

    m_buttonTest.event(e);

    m_boutonTextureTest.event(e);

    m_chargingBarTest.event(e);
    m_poucentage.event(e);

    m_line.event(e);
    m_graph.event(e);

    m_input.event(e);
    m_textInput.event(e);
}
void MainMenu::update()
{
    if (augment)
    {
        m_charge += 0.01;
        if (m_charge > 1) m_charge = 1, augment = false;
        m_chargingBarTest.setChargingValue(m_charge);
        m_poucentage.setString((int)(m_charge * 100.0) + std::string(" %"));
    }
    else
    {
        m_charge -= 0.01;
        if (m_charge <= 0) m_charge = 0, augment = true;
        m_chargingBarTest.setChargingValue(m_charge);
        m_poucentage.setString((int)(m_charge * 100.0) + std::string(" %"));
    }

    time += 0.01 * 3;
    m_graph.addPoint("test", sf::Vector2f(time * 3, std::cos(time)));
    

}
void MainMenu::render()
{
    m_background.draw();
    m_titre.draw();

    m_rectTest.draw();
    m_circleTest.draw();

    m_buttonTest.draw();

    m_boutonTextureTest.draw();

    m_chargingBarTest.draw();
    m_poucentage.draw();

    m_line.draw();

    m_graph.draw();

    m_input.draw();
    m_textInput.draw();
}

void MainMenu::updateOnResize()
{
    
}
