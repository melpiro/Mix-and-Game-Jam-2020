#include <SFML/Graphics.hpp>
#include "Omega/Operators/PrintFunctions.h"
#include "Omega/Graphics/RessourceManager.h"
#include "../src/Character.h"

class MainGame
{

public:
    MainGame(sf::RenderWindow* fen);

    void init();


    void event(sf::Event e);
    void update();
    void render();

private:

    void updateOnResize(sf::Event& e);

    sf::RenderWindow* m_fen;

    sf::View m_view;
    double m_viewZoom = 1.f;

    sf::RectangleShape m_object;

    const float cam_speed= 5.f;
    const float cam_zoom_factor= 1.5f;

    Character m_character;
};



