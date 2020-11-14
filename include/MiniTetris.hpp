#pragma once
#ifndef MINITETRIS_HPP
#define MINITETRIS_HPP

#include <SFML/Graphics.hpp>
#include "Omega/Graphics/Sprite.h"
#include "Omega/Graphics/Rectangle.h"
#include "Omega/Math/RandomFunctions.h"
#include "Omega/Vector/VectorFunctions.h"
#include "Omega/Data/triplet.h"
#include "Omega/Math/Matrix.h"
#include "Piece.hpp"

class MiniTetris
{

public:
    MiniTetris(sf::RenderWindow* fen);

    void start();

    void setPosition(float x, float y);
    void setWindowSize(float x, float y);

    void setTileSize(int nbCol, int nbLine);

    void event(sf::Event e);
    void update();
    void render();


    void addPiece(int x, int y, PIECE p, sf::Color coul, int rotation);

    bool checkCollision(sf::Vector2i futurePos);

    bool defeat() const;

    sf::Vector2f getWindowSize();

    int getScore();

    void setSpeed(sf::Time updateSpeed);

private:

    void updateMoves();
    void updateGameDisplay();
    void updateGameCollide();


    void rotateLeft();
    void rotateRight();

    void generateRdm();

    bool checkDefeat();

    void checkLines();


    std::pair<int, int> getPieceSize(PIECE p, int rotation);

    sf::RenderWindow* m_fen;

    O::graphics::Rectangle m_background;

    
    sf::Vector2i m_actualPiecePos;
    std::vector<std::vector<bool>> m_piece;
    sf::Color m_pieceColor;
    std::vector<std::vector<O::graphics::Sprite>> m_allcase;
    std::vector<std::vector<bool>> m_caseArray;
    std::vector<std::vector<sf::Color>> m_caseColor;
    PIECE pieceId;
    int pieceRotation;

    int m_nbCol = 10;
    int m_nbLine = 10;
    double padding = 5;

    int m_score = 0;

    


    sf::Clock m_timerDown;
    sf::Time m_timeDown = sf::seconds(0.2);
    sf::Time m_timeDownNormal = sf::seconds(0.2);
    sf::Time m_timeDownFast = sf::seconds(0.05);
    sf::Clock m_timerMove;
    sf::Time m_timeMove = sf::seconds(0.1);

    bool m_running = false;
    bool m_defeat = false;

    bool m_leftPressed = false;
    bool m_rightPressed = false;



    const sf::Color NULL_COLOR = sf::Color::Transparent;
    
    
};

#endif


