#pragma once
#ifndef MINITETRIS_HPP
#define MINITETRIS_HPP

#include <SFML/Graphics.hpp>
#include "Omega/Graphics/Rectangle.h"
#include "Omega/Math/RandomFunctions.h"
#include "Omega/Vector/VectorFunctions.h"
#include "Omega/Data/triplet.h"
#include "Omega/Math/Matrix.h"

enum PIECE{
    T = 0
};


class MinitTetris
{

public:
    MinitTetris(sf::RenderWindow* fen);

    void start();

    void setPosition(float x, float y);
    void setWindowSize(float x, float y);

    void setTileSize(int nbCol, int nbLine);

    void event(sf::Event e);
    void update();
    void render();


    void addPiece(int x, int y, PIECE p, sf::Color coul, int rotation);

    bool checkCollision(sf::Vector2i futurePos);

private:


    void rotateLeft();
    void rotateRight();

    void generateRdm();

    bool checkDefeat();


    std::pair<int, int> getPieceSize(PIECE p, int rotation);

    sf::RenderWindow* m_fen;

    O::graphics::Rectangle m_background;

    
    sf::Vector2i m_actualPiecePos;
    std::vector<std::vector<bool>> m_piece;
    sf::Color m_pieceColor;
    std::vector<std::vector<O::graphics::Rectangle>> m_allcase;
    std::vector<std::vector<bool>> m_caseArray;
    std::vector<std::vector<sf::Color>> m_caseColor;
    PIECE pieceId;
    int pieceRotation;

    int m_nbCol = 10;
    int m_nbLine = 10;
    double padding = 5;


    const std::vector<sf::Color> COLORS = {
        sf::Color::Red,
        sf::Color::Green,
        sf::Color::Blue
    };

    sf::CircleShape m_debug;

    sf::Clock m_timerDown;
    sf::Time m_timeDown = sf::seconds(0.2);

    bool m_running = false;
    bool m_defeat = false;



    const sf::Color NULL_COLOR = sf::Color::White;
    
    const std::vector<std::vector<std::vector<std::vector<bool>>>> allPiece = {
        {
            {
                {0,1,0},
                {1,1,1}
            },
            {
                {0,1},
                {1,1},
                {0,1}
            },
            {
                {1,1,1},
                {0,1,0}
            },
            {
                {1,0},
                {1,1},
                {1,0},
            }
            
        },
        {
            {
                {0,1,0},
                {1,1,1},
                {0,1,0}
            },
            {
                {0,1,0},
                {1,1,1},
                {0,1,0}
            },
            {
                {0,1,0},
                {1,1,1},
                {0,1,0}
            },
            {
                {0,1,0},
                {1,1,1},
                {0,1,0}
            }
            
        },
        {
            {
                {1,0},
                {1,1},
                {0,1}
            },
            {
                {1,1,0},
                {0,1,1}
            },
            {
                {0,1},
                {1,1},
                {1,0}
            },
            {
                {0,1,1},
                {1,1,0}
            }
        }
    };
};

#endif


