#include <SFML/Graphics.hpp>

#include <Tilemap.h>

class MainGame
{

public:
    MainGame(sf::RenderWindow* fen);

    void init();


    void event(sf::Event e);
    void update();
    void render();

private:

    void updateOnResize();

    sf::RenderWindow* m_fen;

    Tilemap m_tmap ;
    
};



