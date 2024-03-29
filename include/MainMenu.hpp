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
#include "Omega/Graphics/RessourceManager.h"
#include "Step.hpp"

class MainMenu
{

public:
    MainMenu(sf::RenderWindow* fen);

    void init();


    Step event(sf::Event e);
    void update(float dt);
    void render();

    void updateOnResize();

private:

    sf::RenderWindow* m_fen;

    O::graphics::Sprite m_titre;

    float m_pxAnimMin = 250;
    float m_pxAnimMax = 300;
    float m_pxDir = 20;

    O::graphics::Sprite m_background;
    O::graphics::Button m_bouttonJouer;
    O::graphics::Button m_bouttonTuto;

    O::graphics::Sprite m_credits;
    O::graphics::Sprite m_logoJam;

    O::graphics::Button m_buttonGame0;
    O::graphics::Button m_buttonGame1;
    O::graphics::Button m_buttonGame2;
};



