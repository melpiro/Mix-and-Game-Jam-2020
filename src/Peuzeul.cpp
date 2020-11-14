#include "Peuzeul.hpp"

Peuzeul::Peuzeul(sf::RenderWindow* fen)
{
    m_fen=fen;
}

void Peuzeul::init()
{

}

void Peuzeul::event(sf::Event e)
{
    if (e.type == sf::Event::Resized)
    {
        updateOnResize();
    }
}
void Peuzeul::update()
{

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

        //std::cout << m_contour.size() <<std::endl;
    }

    int minX = 10000;
    int minY = 10000;
    int maxX = -10000;
    int maxY = -10000;

    for (size_t i = 0; i < poly.size(); i++)
    {
        if (poly[i].x < minX) minX = poly[i].x;
        if (poly[i].y < minY) minY = poly[i].y;
        if (poly[i].x > maxX) maxX = poly[i].x;
        if (poly[i].y > maxY) maxY = poly[i].y;
    }

    std::vector<sf::Vector2f> polyF;
    for (size_t i = 0; i < poly.size(); i++)
    {
        polyF.push_back((sf::Vector2f)poly[i]);
    }
    
    for (int x = minX; x < maxX; x++)
    {
        for (int y = minY; y < maxY; y++)
        {
            if (O::math::geo2d::intersect_point_polygon(sf::Vector2f(((float)x) + 0.5, ((float)y) + 0.5),polyF))
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
        }
        
    }
    
}