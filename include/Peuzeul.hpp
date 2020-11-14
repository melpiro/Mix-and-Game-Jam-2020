#include <SFML/Graphics.hpp>
#include "Omega/Graphics/Line.h"
#include "Omega/Graphics/Rectangle.h"
#include "Omega/Math/GeometricFunctions.h"
#include "Omega/Graphics/Sprite.h"
#include "ItemManager.hpp"

class Peuzeul
{

public:
    Peuzeul(sf::RenderWindow* fen, ItemManager* itemManger);

    void init();


    void event(sf::Event e);
    void update();
    void render();

    void setPositon(sf::Vector2i pos);
    
    void polygon(std::vector<sf::Vector2i> poly);

    void setSelectedItemIndex(int index);

private:

    void updateOnResize();

    sf::RenderWindow* m_fen;

    sf::Vector2i m_pos;

    const float WIDTH_OUTLINE = 5;

    int indexSelectedInventoryPiece = -1;
    Item m_selectedItem;
    sf::Vector2f mousePos;
    sf::Vector2i indexMousePos;
    std::vector<O::graphics::Sprite> m_shape;
    std::vector<sf::Vector2i> m_shapeDelta;



    std::vector<O::graphics::Line> m_contour;
    std::vector<O::graphics::Rectangle> m_content;

    ItemManager* m_itemManger;

    
};



