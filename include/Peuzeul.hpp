#include <SFML/Graphics.hpp>
#include "Omega/Graphics/Line.h"
#include "Omega/Graphics/Rectangle.h"
#include "Omega/Math/GeometricFunctions.h"
#include "Omega/Graphics/Sprite.h"
#include "ItemManager.hpp"
#include "JsonData.hpp"

class Peuzeul
{

public:
    Peuzeul(sf::RenderWindow* fen, ItemManager* itemManger);

    void init(std::string path);


    void event(sf::Event e);
    void update();
    void render();

    void setPositon(sf::Vector2i pos);
    
    void polygon(std::vector<sf::Vector2i> poly);

    void setSelectedItemIndex(int index);

    bool isWin();

private:

    void updateOnResize();

    bool isInPolygone();
    void place();
    void remove();

    void computeWin();

    sf::RenderWindow* m_fen;

    sf::Vector2i m_pos;

    float WIDTH_OUTLINE = 5;

    int indexSelectedInventoryPiece = -1;
    Item m_selectedItem;
    sf::Vector2f mousePos;
    sf::Vector2i indexMousePos;
    std::vector<O::graphics::Sprite> m_shape;
    std::vector<sf::Vector2i> m_shapeDelta;
    bool m_isInPolygone = false;

    std::vector<std::vector<bool>> m_polygoneEmplacements;

    std::vector<O::data::triplet<std::vector<O::graphics::Sprite>,std::vector<sf::Vector2i>, Item>> m_placedPiece;



    std::vector<O::graphics::Line> m_contour;
    std::vector<O::graphics::Rectangle> m_content;
    // poly diementions
    int minX = 10000;
    int minY = 10000;
    int maxX = -10000;
    int maxY = -10000;

    ItemManager* m_itemManger;

    bool m_isWin = false;

    
};



