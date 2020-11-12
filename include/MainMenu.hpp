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

    O::graphics::Rectangle m_rectTest;
    O::graphics::Circle m_circleTest;

    O::graphics::Button m_buttonTest;
    O::graphics::TexturedButton m_boutonTextureTest;

    O::graphics::ChargingBar m_chargingBarTest; 
    O::graphics::Text m_poucentage;
    double m_charge = 0;
    bool augment = true;

    O::graphics::GraphiqueCurve m_graph;
    double time = 0;
    O::graphics::Line m_line;

    O::graphics::Input m_input;
    O::graphics::TextInput m_textInput;
};



