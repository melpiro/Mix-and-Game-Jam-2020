#include "Peuzeul.hpp"

Peuzeul::Peuzeul(sf::RenderWindow* fen, ItemManager* itemManger)
{
    m_fen=fen;
    m_itemManger = itemManger;
}

void Peuzeul::init(std::string path)
{

    JsonData j;

    j.readFile(path);

    setPositon(sf::Vector2i((int)*(double*)j["peuzeul"]["pos"]["x"].getValue(),(int)*(double*)j["peuzeul"]["pos"]["y"].getValue()));
    std::vector<sf::Vector2i> poly;
    std::vector<sf::Vector2f> polyReal;
    std::vector<JsonData> polyDAta = *(std::vector<JsonData>*) j["peuzeul"]["poly"].getValue();
    for (size_t i = 0; i < polyDAta.size(); i++)
    {
        poly.push_back(
            sf::Vector2i(
                (int)*(double*)polyDAta[i]["x"].getValue(),
                (int)*(double*)polyDAta[i]["y"].getValue()
            )
        );

        polyReal.push_back(
            (sf::Vector2f) (poly.back() + m_pos) * 64.f 
        );
    }

    m_itemManger->setPeuzeulPoly(polyReal);
    

    polygon(poly);
}

void Peuzeul::event(sf::Event e)
{
    if (e.type == sf::Event::Resized)
    {
        updateOnResize();
    }

    if (e.type==sf::Event::MouseMoved)
    {
        mousePos = m_fen->mapPixelToCoords(sf::Vector2i(e.mouseMove.x, e.mouseMove.y));
        indexMousePos = sf::Vector2i(mousePos.x / 64, mousePos.y / 64);
    }

    if (e.type == sf::Event::MouseButtonPressed)
    {
        if (e.mouseButton.button == sf::Mouse::Left)
        {
            if (indexSelectedInventoryPiece != -1 && m_isInPolygone)
                place();
            else if (indexSelectedInventoryPiece == -1)
                remove();
        }
    }

   
}
void Peuzeul::update()
{
    for (size_t i = 0; i < m_shape.size(); i++)
    {
        m_shape[i].setPosition(
            (indexMousePos.x + m_shapeDelta[i].x) * 64.f,
            (indexMousePos.y + m_shapeDelta[i].y) * 64.f
        );

    }

    if (indexSelectedInventoryPiece != -1)
    {
        if (isInPolygone())
        {
            m_isInPolygone = true;
            for (size_t i = 0; i < m_shape.size(); i++)
            {
                sf::Color c = m_shape[i].gS().getColor();
                c.a = 255;
                m_shape[i].setColor(c);
            }
            
        }
        else
        {
            m_isInPolygone = false;
            for (size_t i = 0; i < m_shape.size(); i++)
            {
                sf::Color c = m_shape[i].gS().getColor();
                c.a = 150;
                m_shape[i].setColor(c);
            }
        }
        
    }

    
    
}
void Peuzeul::render()
{
    for (size_t i = 0; i < m_contour.size(); i++)
    {
        m_contour[i].draw();
    }
    for (size_t i = 0; i < m_content.size(); i++)
    {
        m_content[i].draw();
    }

    for (size_t i = 0; i < m_shape.size(); i++)
    {
        m_shape[i].draw();
    }
    for (size_t i = 0; i < m_placedPiece.size(); i++)
    {
        for (size_t j = 0; j < m_placedPiece[i].first.size(); j++)
        {
            m_placedPiece[i].first[j].draw();
        }
    }
}

void Peuzeul::updateOnResize()
{
    
}

void Peuzeul::setPositon(sf::Vector2i pos)
{
    m_pos = pos;
}


void Peuzeul::polygon(std::vector<sf::Vector2i> poly)
{

    for (size_t i = 0; i < poly.size(); i++)
    {
        int i_1 = i + 1;
        if (i_1 == poly.size()) i_1 = 0;


        m_contour.push_back(
            O::graphics::Line(
                m_fen, ((sf::Vector2f)(m_pos+ poly[i])) * (16.f * 4.f), ((sf::Vector2f)(m_pos+ poly[i_1]))  * (16.f * 4.f),  WIDTH_OUTLINE
            )
        );

    }

    minX = 10000;
    minY = 10000;
    maxX = -10000;
    maxY = -10000;

   
    for (size_t i = 0; i < poly.size(); i++)
    {
        if (poly[i].x < minX) minX = poly[i].x;
        if (poly[i].y < minY) minY = poly[i].y;
        if (poly[i].x > maxX) maxX = poly[i].x;
        if (poly[i].y > maxY) maxY = poly[i].y;
    }

    m_polygoneEmplacements = O::vector::create2DVector(maxX - minX, maxY - minY, false);


    std::vector<sf::Vector2f> polyF;
    for (size_t i = 0; i < poly.size(); i++)
    {
        polyF.push_back((sf::Vector2f)poly[i]);
    }
    
    for (int x = minX; x < maxX; x++)
    {
        for (int y = minY; y < maxY; y++)
        {
            if (O::math::geo2d::intersect_point_polygon(sf::Vector2f(((float)x) + 0.6, ((float)y) + 0.7),polyF))
            {
                m_content.push_back(
                    O::graphics::Rectangle( 
                        m_fen, 
                        ((float)(m_pos.x+ x)) * (16.f * 4.f),
                         ((float)(m_pos.y+ y))  * (16.f * 4.f),

                         (16.f * 4.f),
                         (16.f * 4.f)

                ));
                m_content.back().setFillColor(sf::Color(0,0,0, 150));
            }
            else
            {
                m_polygoneEmplacements[x - minX][y - minY] = true;
            }
        }
    }
}


void Peuzeul::setSelectedItemIndex(int index)
{

    if (index != indexSelectedInventoryPiece)
    {
        indexSelectedInventoryPiece = index;

        if (index != -1)
        {
            m_selectedItem = m_itemManger->getMyItems()[index];
            

            sf::Color coul = m_selectedItem.coul;
            coul.a = 150;
            


            for (size_t i = 0; i < allPiece[(int)m_selectedItem.type][m_selectedItem.rotation].size(); i++)
            {
                for (size_t j = 0; j < allPiece[(int)m_selectedItem.type][m_selectedItem.rotation][i].size(); j++)
                {  
                    if (allPiece[(int)m_selectedItem.type][m_selectedItem.rotation][i][j])
                    {
                        m_shape.push_back(
                            O::graphics::Sprite(m_fen, "tetrisCell",
                            indexMousePos.x * 64.f,
                            indexMousePos.y * 64.f
                            )
                        );

                        m_shape.back().setScale(
                            64.f / (float)O::graphics::ressourceManager.getTexture("tetrisCell").getSize().x,
                            64.f / (float)O::graphics::ressourceManager.getTexture("tetrisCell").getSize().y);

                        m_shape.back().setColor(coul);
                        m_shape.back().loadTexture();

                        m_shapeDelta.push_back(sf::Vector2i(j,i));

                    }   
                }
                
            }
            
        }
        else
        {
            // reset
            m_shape.clear();
            m_shapeDelta.clear();
        }
    }
}


bool Peuzeul::isInPolygone()
{
    int x = indexMousePos.x - m_pos.x - minX;
    int y = indexMousePos.y - m_pos.y - minY;

    if (x >= 0 && x + allPiece[(int)m_selectedItem.type][m_selectedItem.rotation].back().size() <= maxX - minX && y >= 0 && y + allPiece[(int)m_selectedItem.type][m_selectedItem.rotation].size() <= maxY - minY )
    {
        for (size_t i = 0; i < m_shapeDelta.size(); i++)
        {
            if (m_polygoneEmplacements[x + m_shapeDelta[i].x][y + m_shapeDelta[i].y])
            {
                return false;
            }
        }
        

        return true;
    }

    return false;
}


void Peuzeul::place()
{
    int x = indexMousePos.x - m_pos.x - minX;
    int y = indexMousePos.y - m_pos.y - minY;
    if (x >= 0 && x + allPiece[(int)m_selectedItem.type][m_selectedItem.rotation].back().size() <= maxX - minX && y >= 0 && y + allPiece[(int)m_selectedItem.type][m_selectedItem.rotation].size() <= maxY - minY )
    {
        for (size_t i = 0; i < m_shapeDelta.size(); i++)
        {
            m_polygoneEmplacements[x + m_shapeDelta[i].x][y + m_shapeDelta[i].y] = true;
        }

        O::data::triplet<std::vector<O::graphics::Sprite>,std::vector<sf::Vector2i>, Item> piece;
        for (size_t i = 0; i < m_shape.size(); i++)
        {
            piece.first.push_back(m_shape[i]);

        }
        for (size_t i = 0; i < m_shapeDelta.size(); i++)
        {
            piece.second.push_back(sf::Vector2i(x,y) + m_shapeDelta[i]);
        }
        piece.third = m_selectedItem;

        m_placedPiece.push_back(piece);

        m_itemManger->removeInventoryItem(indexSelectedInventoryPiece);

        computeWin();
    }
}


void Peuzeul::remove()
{
    if (m_itemManger->getMyItems().size() < 30)
    {
        int x = indexMousePos.x - m_pos.x - minX;
        int y = indexMousePos.y - m_pos.y - minY;

        for (size_t i = 0; i < m_placedPiece.size(); i++)
        {
            for (size_t j = 0; j < m_placedPiece[i].second.size(); j++)
            {
                if (x == m_placedPiece[i].second[j].x && y == m_placedPiece[i].second[j].y)
                {
                    
                    m_itemManger->addItemInInventory(m_placedPiece[i].third);

                    for (size_t k = 0; k < m_placedPiece[i].second.size(); k++)
                    {
                        sf::Vector2i pos = m_placedPiece[i].second[k];
                        m_polygoneEmplacements[pos.x][pos.y] = false;
                    }
                    


                    m_placedPiece.erase(m_placedPiece.begin() + i);


                    return;
                }
            }
            
        }
    }
}

void Peuzeul::computeWin()
{
    for (size_t i = 0; i < m_polygoneEmplacements.size(); i++)
    {
        for (size_t j = 0; j < m_polygoneEmplacements[i].size(); j++)
        {
            if (!m_polygoneEmplacements[i][j])
            {
                m_isWin = false;
                return;
            }
        }
        
    }
    m_isWin = true;
}

bool Peuzeul::isWin()
{
    return m_isWin;
    
}