#include "MiniTetris.hpp"

MiniTetris::MiniTetris(sf::RenderWindow* fen) :
    m_background(fen, 0,0,100,100, true)
{
    m_fen=fen;

    m_background.setFillColor(sf::Color(255,255,255,30));

}

void MiniTetris::start()
{
    float minX = m_background.getPosition().x - m_background.getSize().x /2.0 + padding;
    float minY = m_background.getPosition().y - m_background.getSize().y /2.0 + padding;
    float maxX = m_background.getPosition().x + m_background.getSize().x /2.0 - padding;
    float maxY = m_background.getPosition().y + m_background.getSize().y /2.0 - padding;
    float sizeX = (m_background.getSize().x - 2.f * padding) / (float) m_nbCol;
    float sizeY = (m_background.getSize().y - 2.f * padding) / (float) (m_nbLine - 3);


    m_caseArray = O::vector::create2DVector(m_nbCol, m_nbLine, false);
    m_allcase = O::vector::create2DVector(m_nbCol, m_nbLine, O::graphics::Sprite(m_fen, "tetrisCell", 0,0));
    m_caseColor = O::vector::create2DVector(m_nbCol, m_nbLine, NULL_COLOR);

   for (size_t i = 0; i < m_allcase.size(); i++)
   {
       for (int j = 0; j < m_allcase[i].size(); j++)
       {
            m_allcase[i][j].setPosition(minX + i * sizeX, minY + (j - 3) * sizeY);
            m_allcase[i][j].setColor(NULL_COLOR);
            m_allcase[i][j].setScale(sizeX/(float)O::graphics::ressourceManager.getTexture("tetrisCell").getSize().x,sizeY/(float)O::graphics::ressourceManager.getTexture("tetrisCell").getSize().y);
            m_allcase[i][j].loadTexture();
       }
   }

   generateRdm();

   m_running = true;
   m_defeat = false;
   m_timeDown = sf::seconds(0.2);
   m_leftPressed = false;
   m_rightPressed = false;
}



void MiniTetris::event(sf::Event e)
{
    if (m_running && !m_defeat)
    {
        if (e.type == sf::Event::KeyPressed)
        {
            if (e.key.code == sf::Keyboard::Up)
            {
                rotateRight();
            }
            else if (false && e.key.code == sf::Keyboard::Right)
            {
                rotateRight();
            }
            else if (e.key.code == sf::Keyboard::Left)
            {
                m_leftPressed = true;
            }
            else if (e.key.code == sf::Keyboard::Right)
            {
                m_rightPressed = true;
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
        
            else if (e.key.code == sf::Keyboard::Left)
            {
                m_leftPressed = false;
            }
            else if (e.key.code == sf::Keyboard::Right)
            {
                m_rightPressed = false;
            }
        }
    }
    
}

void MiniTetris::updateMoves()
{
    if (m_leftPressed)
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
    else if (m_rightPressed)
    {
        sf::Vector2i futurePos = m_actualPiecePos;
        futurePos.x++;

        if (futurePos.x + m_piece.size() > m_nbCol)
        {
            futurePos.x = m_nbCol - (int) m_piece.size();
        }

        if (!checkCollision(futurePos))
        {
            m_actualPiecePos = futurePos;
        }
    }
}
void MiniTetris::updateGameDisplay()
{
    for (int i = 0; i < m_allcase.size(); i++)
    {
        for (int j = 0; j < m_allcase[i].size(); j++)
        {
            if (m_caseArray[i][j])
                m_allcase[i][j].setColor(m_caseColor[i][j]);
            else
                m_allcase[i][j].setColor(NULL_COLOR);
        }
        
    }
    for (size_t i = 0; i < m_piece.size(); i++)
    {
        for (size_t j = 0; j < m_piece.back().size(); j++)
        {
            if (m_piece[i][j])
                m_allcase[i + m_actualPiecePos.x][j  + m_actualPiecePos.y].setColor(m_pieceColor);
        }
    }
}
void MiniTetris::updateGameCollide()
{
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

            generateRdm();
            checkLines();
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
        {
            generateRdm();
            checkLines();
        }
        
    }
}
void MiniTetris::update()
{

    if (m_running && !m_defeat)
    {
        if (m_timerMove.getElapsedTime() > m_timeMove)
        {
            m_timerMove.restart();

            updateMoves();
            updateGameDisplay();
        }
        if (m_timerDown.getElapsedTime() > m_timeDown)
        {
            m_timerDown.restart();
            
            updateGameCollide();
            updateGameDisplay();
            
        }

    }
}
void MiniTetris::render()
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
    }
}


void MiniTetris::setPosition(float x, float y)
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


void MiniTetris::setWindowSize(float x, float y)
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
           m_allcase[i][j].setScale(sizeX /(float)O::graphics::ressourceManager.getTexture("tetrisCell").getSize().x, sizeY/(float)O::graphics::ressourceManager.getTexture("tetrisCell").getSize().y);
       }
   }
}

void MiniTetris::setTileSize(int nbCol, int nbLine)
{
    m_nbLine = nbLine + 3;
    m_nbCol = nbCol;

}

void MiniTetris::addPiece(int x, int y, PIECE p, sf::Color coul, int rotation)
{
    m_actualPiecePos = sf::Vector2i(x, y);
    pieceId = p;

    pieceRotation = rotation;
    m_piece = allPiece[(int)pieceId][pieceRotation];

    m_pieceColor = coul;
}

void MiniTetris::rotateRight()
{
    sf::Vector2i lastPiecePos = m_actualPiecePos;
    int lastPieceRotation = pieceRotation;

    pieceRotation++;
    if (pieceRotation > 3) pieceRotation = 0;

    m_piece = allPiece[(int)pieceId][pieceRotation];
    

    if (pieceId == PIECE::I)
    {
        if (pieceRotation == 1) m_actualPiecePos.x ++;
        if (pieceRotation == 2) m_actualPiecePos.x --;
        if (pieceRotation == 3) m_actualPiecePos.x ++;
        if (pieceRotation == 0) m_actualPiecePos.x --;
    }
    

    if (m_actualPiecePos.x + m_piece.size() >= m_nbCol)
    {
        m_actualPiecePos.x = m_nbCol - m_piece.size();
    }
    if (m_actualPiecePos.x < 0)
    {
        m_actualPiecePos.x = 0;
    }

    if (checkCollision(m_actualPiecePos))
    {
        m_actualPiecePos = lastPiecePos;
        pieceRotation = lastPieceRotation;
        m_piece = allPiece[(int)pieceId][pieceRotation];
    }

}
void MiniTetris::rotateLeft()
{
    pieceRotation--;
    if (pieceRotation < 0) pieceRotation = 3;


    m_piece = allPiece[(int)pieceId][pieceRotation];

    if (pieceId == PIECE::I)
    {
        if (pieceRotation == 1) m_actualPiecePos.x ++;
        if (pieceRotation == 2) m_actualPiecePos.x --;
        if (pieceRotation == 3) m_actualPiecePos.x ++;
        if (pieceRotation == 0) m_actualPiecePos.x --;
    }

    if (m_actualPiecePos.x + m_piece.size() >= m_nbCol)
    {
        m_actualPiecePos.x = m_nbCol - m_piece.size();
    }
    if (m_actualPiecePos.x < 0)
    {
        m_actualPiecePos.x = 0;
    }
    if (m_actualPiecePos.y + m_piece.size() >= m_nbLine)
    {
        m_actualPiecePos.y = m_nbLine - m_piece.size();
    }
    if (m_actualPiecePos.y < 0)
    {
        m_actualPiecePos.y = 0;
    }
}

std::pair<int, int> MiniTetris::getPieceSize(PIECE p, int rotation)
{
    return std::make_pair(
        allPiece[(int)p][rotation].size(),
        allPiece[(int)p][rotation].back().size()
    );
}




bool MiniTetris::checkCollision(sf::Vector2i futurePos)
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

void MiniTetris::generateRdm()
{
    PIECE p = (PIECE)O::math::rdm::randInt(0, allPiece.size());
    int rotation = O::math::rdm::randInt(0, 4);

    auto size = getPieceSize(p, rotation);

    auto v = O::math::rdm::randInt(0, m_nbCol - 1 - size.first );
    addPiece(v, 0, p,
        COLORS[O::math::rdm::randInt(0, COLORS.size())],
        rotation);
}

bool MiniTetris::checkDefeat()
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

bool MiniTetris::defeat() const {
    return m_defeat;
}

sf::Vector2f MiniTetris::getWindowSize() {
    return m_background.getSize();
}

void MiniTetris::checkLines()
{
    for (size_t y = 0; y < m_caseArray.back().size(); y++)
    {
        bool line = true;
        for (size_t x = 0; x < m_caseArray.size(); x++)
        {
            if (!m_caseArray[x][y])
            {
                line = false;
                break;
            }
        }

        if (line)
        {
            m_score++;

            for (int _y = y; _y > 0; _y--)
            {
                for (int _x = 0; _x < m_caseArray.size(); _x++)
                {
                    m_caseArray[_x][_y] = m_caseArray[_x][_y - 1];
                }
            }
            checkLines();
        }
    }
}