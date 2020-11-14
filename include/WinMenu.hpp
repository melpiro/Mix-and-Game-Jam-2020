#include <SFML/Graphics.hpp>
#include "Omega/Graphics/Text.h"

class WinMenu
{

public:
    WinMenu(sf::RenderWindow* fen);

    void init();


    void event(sf::Event e);
    void update();
    void render();
    

    void updateOnResize();

private:


    sf::RenderWindow* m_fen;
    
    O::graphics::Text m_title;
    
};



