//
// Created by Alarm on 15/11/2020.
//

#include "TutoMenu.h"

TutoMenu::TutoMenu(sf::RenderWindow *fen):
m_tuto(fen,"tuto",STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HEIGHT,STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HEIGHT,true),
m_backButton(fen,"mainFont",STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HEIGHT,STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HEIGHT,true),
m_background(fen,"loadingMenuBackground",STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HEIGHT, STATIC::SYS::HALF_WIDTH, STATIC::SYS::HALF_HEIGHT, true)
{
    m_posYmin = m_tuto.getPosition().y ;
    m_posYmax = m_tuto.getPosition().y + 500;
}

void TutoMenu::init() {
    m_tuto.loadTexture();
    m_backButton.loadFont();
    m_background.loadTexture();
    m_backButton.setSize(300,80);
    m_backButton.setString(O::graphics::ressourceManager.text(6));
    m_backButton.setTextColor(sf::Color::Black);
    m_backButton.setFillColor(sf::Color(133, 130, 130));
    reset();
}

Step TutoMenu::event(sf::Event e) {

    if(e.type == sf::Event::MouseWheelMoved){
        float scroll = e.mouseWheel.delta;
        std::cout << scroll << std::endl;
        m_tuto.setPosition(m_tuto.getPosition().x , m_tuto.getPosition().y + 20*scroll);
    }

    if(m_backButton.clicked(e)){
        return Step::MAIN_MENU;
    }

    return TUTO_MENU;
}

void TutoMenu::update(float dt) {
    m_tuto.update();
    m_backButton.update();
    m_background.update();

    m_backButton.setPosition(m_tuto.getPosition().x-400,m_tuto.getPosition().y + 1000);

    std::cout << m_tuto.getPosition().y << std::endl;
}

void TutoMenu::render() {
    m_background.draw();
    m_tuto.draw();
    m_backButton.draw();
}

void TutoMenu::updateOnResize() {

}

void TutoMenu::reset() {
    m_tuto.setPosition(m_tuto.getPosition().x,1100);
}
