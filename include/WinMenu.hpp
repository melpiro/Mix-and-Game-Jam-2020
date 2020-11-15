#include <Omega/Graphics/Sprite.h>
#include <Omega/Graphics/Button.h>
#include "Omega/Graphics/Text.h"

class WinMenu
{

public:
    WinMenu(sf::RenderWindow* fen);

    void init();


    Step event(sf::Event e);
    void update();
    void render();
    

    void updateOnResize();

    int currentLvl = 0;
    int nbrLvl = 3;
private:

    sf::RenderWindow* m_fen;
    
    O::graphics::Text m_title;
    O::graphics::Sprite m_background;

    O::graphics::Button m_bouttonMainMenu;
    O::graphics::Button m_bouttonNextLevel;
};



