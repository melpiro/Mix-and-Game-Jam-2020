//
// Created by Alarm on 15/11/2020.
//

#ifndef MIXGAMEJAM2020_TUTOMENU_H
#define MIXGAMEJAM2020_TUTOMENU_H


#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include "Step.hpp"
#include "Omega/Graphics/Button.h"
#include "Omega/Graphics/Sprite.h"

class TutoMenu {
public:
    TutoMenu(sf::RenderWindow* fen);

    void init();


    Step event(sf::Event e);
    void update(float dt);
    void render();


    void updateOnResize();

    void reset();

private:

    sf::RenderWindow* m_fen;



    O::graphics::Sprite m_tuto;
    O::graphics::Sprite m_background;
    O::graphics::Button m_backButton;

    float m_posYmin = 1000;
    float m_posYmax;

    bool m_mustmove = false;
    float m_wheelScroll;
};


#endif //MIXGAMEJAM2020_TUTOMENU_H
