#include <SFML/Graphics.hpp>
#include "Graphics/Sprite.h"
#include "Graphics/Text.h"

class LoadingMenu
{

public:
    LoadingMenu(sf::RenderWindow* fen);

    void init();


    void event(sf::Event e);
    void update();
    void render();

private:

    void updateOnResize();

    sf::RenderWindow* m_fen;

    O::graphics::Sprite m_background;
    O::graphics::Sprite m_loadingIcon;
    O::graphics::Text m_loadingTitle;
    
};



