#include <SFML/Graphics.hpp>
#include "Graphics/Sprite.h"
#include "Graphics/Text.h"

#include "Graphics/Rectangle.h"
#include "Graphics/Circle.h"
#include "Graphics/Button.h"
#include "Graphics/TexturedButton.h"
#include "Graphics/ChargingBar.h"
#include "String/StringFunctions.h"
#include "Graphics/Line.h"
#include "Graphics/GraphiqueCurve.h"

#include "Graphics/Input.h"
#include "Graphics/TextInput.h"

class MainMenu
{

public:
    MainMenu(sf::RenderWindow* fen);

    void init();


    void event(sf::Event e);
    void update();
    void render();

private:

    void updateOnResize();

    sf::RenderWindow* m_fen;

    O::graphics::Sprite m_background;
    O::graphics::Text m_titre;
};



