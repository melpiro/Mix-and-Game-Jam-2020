#include "MinitTetris.hpp"

MinitTetris::MinitTetris(sf::RenderWindow* fen) :
    m_background(fen, 0,0,100,100, true)
{
    m_fen=fen;

    m_background.setFillColor(sf::Color(255,255,255,180));

    m_debug.setFillColor(sf::Color::Magenta);
    m_debug.setRadius(5);
    m_debug.setOrigin(5,5);
}

void MinitTetris::start()
{
    float minX = m_background.getPosition().x - m_background.getSize().x /2.0 + padding;
    float minY = m_background.getPosition().y - m_background.getSize().y /2.0 + padding;
    float maxX = m_background.getPosition().x + m_background.getSize().x /2.0 - padding;
    float maxY = m_background.getPosition().y + m_background.getSize().y /2.0 - padding;
    float sizeX = (m_background.getSize().x - 2.f * padding) / (float) m_nbCol;
    float sizeY = (m_background.getSize().y - 2.f * padding) / (float) (m_nbLine - 3);


    m_caseArray = O::vector::create2DVector(m_nbCol, m_nbLine, false);
    m_allcase = O::vector::create2DVector(m_nbCol, m_nbLine, O::graphics::Rectangle(m_fen, 0,0, 0,0, false));
    m_caseColor = O::vector::create2DVector(m_nbCol, m_nbLine, NULL_COLOR);

   for (size_t i = 0; i < m_allcase.size(); i++)
   {
       for (int j = 0; j < m_allcase[i].size(); j++)
       {
           m_allcase[i][j].setPosition(minX + i * sizeX, minY + (j - 3) * sizeY);
           m_allcase[i][j].setFillColor(sf::Color::Cyan);
           m_allcase[i][j].setSize(sizeX,sizeY);
       }
   }

   generateRdm();

   m_running = true;
   m_defeat = false;
   m_timeDown = sf::seconds(0.2);
}



void MinitTetris::event(sf::Event e)
{
    if (m_running && !m_defeat)
    {
        if (e.type == sf::Event::KeyPressed)
        {
            if (e.key.code == sf::Keyboard::Up)
            {
                rotateLeft();
            }
            else if (false && e.key.code == sf::Keyboard::Right)
            {
                rotateRight();
            }
            else if (e.key.code == sf::Keyboard::Left)
            {
                sf::Vector2i futurePos = m_actualPiecePos;
                futurePos.x--;

                if (futurePos.x < 0)
                {
                    futurePos.x = 0;
                }

                if (!checkCollision(futurePos))
                {
                    m_actualPiecePos = futurePos;
                }

            }
            else if (e.key.code == sf::Keyboard::Right)
            {
                sf::Vector2i futurePos = m_actualPiecePos;
                futurePos.x ++;

                if (futurePos.x + m_piece.size() > m_nbCol)
                {
                    futurePos.x = m_nbCol - (int) m_piece.size();
                }

                if (!checkCollision(futurePos))
                {
                    m_actualPiecePos = futurePos;
                }

            }
            else if (e.key.code == sf::Keyboard::Down)
            {
                m_timeDown = sf::seconds(0.05);
            }
        }
        else if (e.type == sf::Event::KeyReleased)
        {
            if (e.key.code == sf::Keyboard::Down)
            {
                m_timeDown = sf::seconds(0.2);
            }
        }
    }
    else
    {
        if (e.type== sf::Event::KeyPressed)
        {
            if (e.key.code == sf::Keyboard::Space)
            {
                start();
            }
        }
    }
    
}
void MinitTetris::update()
{
    if (m_running && !m_defeat)
    {
        if (m_timerDown.getElapsedTime() > m_timeDown)
        {
            m_timerDown.restart();
            sf::Vector2i futurePos = m_actualPiecePos;
                
            futurePos.y ++;
            if (!checkCollision(futurePos))
            {
                m_actualPiecePos = futurePos;
                
                if (m_actualPiecePos.y + m_piece.back().size() >= m_nbLine)
                {
                    m_actualPiecePos.y = m_nbLine - (int) m_piece.back().size();
                    
                    for (size_t i = m_actualPiecePos.x; i < m_actualPiecePos.x+m_piece.size(); i++)
                    {
                        for (size_t j = m_actualPiecePos.y; j < m_actualPiecePos.y+m_piece.back().size(); j++)
                        {
                            if (m_piece[i - m_actualPiecePos.x][j - m_actualPiecePos.y])
                            {
                                m_caseArray[i][j] = true;
                                m_caseColor[i][j] = m_pieceColor;
                            }
                        }
                    }
                }
            }
            else
            {  
                for (size_t i = m_actualPiecePos.x; i < m_actualPiecePos.x+m_piece.size(); i++)
                {
                    for (size_t j = m_actualPiecePos.y; j < m_actualPiecePos.y+m_piece.back().size(); j++)
                    {
                        if (m_piece[i - m_actualPiecePos.x][j - m_actualPiecePos.y])
                        {
                            m_caseArray[i][j] = true;
                            m_caseColor[i][j] = m_pieceColor;
                        }
                    }
                }

                if (!checkDefeat())
                    generateRdm();

            }
            
        }

        
        

        for (int i = 0; i < m_allcase.size(); i++)
        {
            for (int j = 0; j < m_allcase[i].size(); j++)
            {
                if (m_caseArray[i][j])
                    m_allcase[i][j].setFillColor(m_caseColor[i][j]);
                else
                    m_allcase[i][j].setFillColor(NULL_COLOR);
            }
            
        }
        for (size_t i = 0; i < m_piece.size(); i++)
        {
            for (size_t j = 0; j < m_piece.back().size(); j++)
            {
                if (m_piece[i][j])
                    m_allcase[i + m_actualPiecePos.x][j  + m_actualPiecePos.y].setFillColor(m_pieceColor);
            }
        }
    }
}
void MinitTetris::render()
{
    if (m_running)
    {
        m_background.draw();

        for (size_t i = 0; i < m_allcase.size(); i++)
        {
            for (size_t j = 3; j < m_allcase[i].size(); j++)
            {
                m_allcase[i][j].draw();
            }
        }

        m_fen->draw(m_debug);
    }
}


void MinitTetris::setPosition(float x, float y)
{
    m_background.setPosition(x, y);

    float minX = m_background.getPosition().x - m_background.getSize().x /2.0 + padding;
    float minY = m_background.getPosition().y - m_background.getSize().y /2.0 + padding;
    float sizeX = (m_background.getSize().x - 2.f * padding) / (float) m_nbCol;
    float sizeY = (m_background.getSize().y - 2.f * padding) / (float) (m_nbLine - 3);

   for (size_t i = 0; i < m_allcase.size(); i++)
   {
       for (int j = 0; j < m_allcase[i].size(); j++)
       {
           m_allcase[i][j].setPosition(minX + i * sizeX, minY + (j - 3) * sizeY);
       }
   }
}


void MinitTetris::setWindowSize(float x, float y)
{
    m_background.setSize(x, y);

    float minX = m_background.getPosition().x - m_background.getSize().x /2.0 + padding;
    float minY = m_background.getPosition().y - m_background.getSize().y /2.0 + padding;
    float sizeX = (m_background.getSize().x - 2.f * padding) / (float) m_nbCol;
    float sizeY = (m_background.getSize().y - 2.f * padding) / (float) (m_nbLine - 3);

   for (size_t i = 0; i < m_allcase.size(); i++)
   {
       for (int j = 0; j < m_allcase[i].size(); j++)
       {
           m_allcase[i][j].setPosition(minX + i * sizeX, minY + (j - 3) * sizeY);
           m_allcase[i][j].setSize(sizeX, sizeY);
       }
   }
}

void MinitTetris::setTileSize(int nbCol, int nbLine)
{
    m_nbLine = nbLine + 3;
    m_nbCol = nbCol;

}

void MinitTetris::addPiece(int x, int y, PIECE p, sf::Color coul, int rotation)
{
    m_actualPiecePos = sf::Vector2i(x, y);
    pieceId = p;

    pieceRotation = rotation;
    m_piece = allPiece[(int)pieceId][pieceRotation];

    m_pieceColor = coul;
}

void MinitTetris::rotateRight()
{
    pieceRotation++;
    if (pieceRotation > 3) pieceRotation = 0;

    m_piece = allPiece[(int)pieceId][pieceRotation];
    

}
void MinitTetris::rotateLeft()
{
    pieceRotation--;
    if (pieceRotation < 0) pieceRotation = 3;


    m_piece = allPiece[(int)pieceId][pieceRotation];
}

std::pair<int, int> MinitTetris::getPieceSize(PIECE p)
{
    switch (p)
    {
    case T:
        return std::make_pair(3,2);
    
    default:
        return std::make_pair(0,0);
    }
}




bool MinitTetris::checkCollision(sf::Vector2i futurePos)
{
    for (size_t i = 0; i < m_piece.size(); i++)
    {
        for (size_t j = 0; j < m_piece.back().size(); j++)
        {
            if (m_caseArray[i + futurePos.x][j + futurePos.y] && m_piece[i][j])
                return true;
        }
    }
    return false;
}

void MinitTetris::generateRdm()
{
    PIECE p = (PIECE)O::math::rdm::randInt(0, NB_PIECE);
    auto size = getPieceSize(p);
    addPiece(O::math::rdm::randInt(0, m_nbCol - size.first - 1), 0, p, 
        COLORS[O::math::rdm::randInt(0, COLORS.size())],
        O::math::rdm::randInt(0,3));
}

bool MinitTetris::checkDefeat()
{
    // check defeat
    for (size_t i = 0; i < m_caseArray.size(); i++)
    {
        if (m_caseArray[i][3] == true)
        {
            m_defeat = true;
            return true;
        }
    }
    return false;
}