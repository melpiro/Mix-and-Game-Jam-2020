#include <SFML/Graphics.hpp>
#include "Omega/Graphics/Line.h"
#include "Omega/Graphics/Rectangle.h"

class Peuzeul
{

public:
    Peuzeul(sf::RenderWindow* fen);

    void init();


    void event(sf::Event e);
    void update();
    void render();

    void setPositon(sf::Vector2i pos);
    
    void polygon(std::vector<sf::Vector2i> poly);

private:

    void updateOnResize();

    sf::RenderWindow* m_fen;

    std::vector<O::graphics::Line> m_contour;
    std::vector<O::graphics::Rectangle> m_content;

    
};



