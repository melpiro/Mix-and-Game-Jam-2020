#include <SFML/Graphics.hpp>
#include "Omega/Operators/PrintFunctions.h"
#include "MinitTetris.hpp"


class MainGame
{

public:
    MainGame(sf::RenderWindow* fen);

    void init();


    void event(sf::Event e);
    void update();
    void render();


    void updateOnResize();


private:

    sf::RenderWindow* m_fen;

    sf::View m_view;
    float m_viewZoom = 1.f;

    bool m_left = false;
    bool m_right = false;
    bool m_up = false;
    bool m_down = false;

    sf::RectangleShape m_persoTest;
    sf::RectangleShape m_object;

    const float speed= 5.f;
    const float zoom_factor= 1.5f;

    MinitTetris m_tetrisTest;
};



