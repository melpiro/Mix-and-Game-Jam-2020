//
// Created by etien on 13/11/2020.
//

#include <Omega/Graphics/RessourceManager.h>
#include <EnemyManager.h>
#include "EnemyCharacter.h"
#include "PlayerCharacter.h"


EnemyCharacter::EnemyCharacter(sf::RenderWindow *fen, PlayerCharacter* pc) : Character(fen), miniTetris(fen) {
    player = pc;

    miniTetris.setPosition(pos.x, pos.y);
    miniTetris.setWindowSize(60*1.5f,140*1.5f);
    miniTetris.setTileSize(5,13);
}

void EnemyCharacter::init() {
    sprite = sf::Sprite(O::graphics::ressourceManager.getTexture("et_tilemap"));
    sprite.setScale(4, 4);

    frameSize = 16;
    sprite.setOrigin(frameSize*0.5f, frameSize*0.5f);

    nbrFrames = 3;

    animY = 3*frameSize*nbrFrames;

    setAnim();
    playAnim = false;

    speed = 100;

    miniTetris.setSpeed(sf::seconds(0.5));

}

void EnemyCharacter::update(float deltatime) {
    Character::update(deltatime);
    miniTetris.setPosition(pos.x, pos.y -(sprite.getLocalBounds().height*0.5f * sprite.getScale().y + miniTetris.getWindowSize().y*0.5f) - getRect().height*0.1f);


    // Pour que l'enemie agro le joueur
    if(O::math::getDistanceCarre(pos, player->getPos()) < agroDist*agroDist && !isAttacking) {

        player->addEnemyAgro(this);
        isAttacking = true;
        miniTetris.start();

    }

    

    else if(isAttacking) {

        if (!m_havePath)
        {
            computPath();

            m_pathUpdater.restart();
        }
        else if (m_pathUpdater.getElapsedTime() > m_pathUpdateDelay)
        {
            m_pathUpdater.restart();
            comeFromPoint = m_path.front();
            computPath();
        }

        

        sf::Vector2f pointPathNext;
        if (m_path.size() == 0)
        {
            pointPathNext = player->getPos();
        }
        else
        {
            pointPathNext = (sf::Vector2f)m_graphNodePos->at(m_path.front()) * 64.f + sf::Vector2f(32.f, 32.f);
            double distToPoint = O::math::getDistance(pointPathNext, pos);

            if (O::math::getDistance(player->getPos(), pos) < distToPoint)
            {
                pointPathNext = player->getPos();
            }
        }
        

        vel = O::math::normalise(pointPathNext - pos) * speed;


        if(miniTetris.getScore() > 0) {
            miniTetris.setScore(miniTetris.getScore()-1);
            applyDamage(1);
            if(dead) {
                player->removeEnemyAgro(this);
                isAttacking = false;
                EnemyManager::killEnemy(id);
                m_havePath = false;
            }
        }

        else if(miniTetris.defeat()) {
            player->applyDamage(1);
            miniTetris.start();
        }


        else if(O::math::getDistanceCarre(pos, player->getPos()) > loseAgroDist*loseAgroDist) {
            player->removeEnemyAgro(this);
            isAttacking = false;
            m_havePath = false;
        }


    }

}

void EnemyCharacter::draw() {
    Character::draw();

    for (size_t i = 0; i < m_debugPath.size(); i++)
    {
        m_debugPath[i].draw();
    }
    
}

void EnemyCharacter::event(sf::Event &e) {
    Character::event(e);
}

MiniTetris* EnemyCharacter::getMiniTetris() {
    return &miniTetris;
}

int EnemyCharacter::operator==(const EnemyCharacter &other) const {
    return id == other.id;
}

int EnemyCharacter::operator!=(const EnemyCharacter &other) const {
    return id != other.id;
}

void EnemyCharacter::computPath()
{
    m_path.clear();

    double minDist = 100000000;
    int indexBestForPlayer;
    for (auto node:*m_graphNodePos)
    {
        double d = O::math::getDistanceCarre((sf::Vector2f)(node.second) * 64.f + sf::Vector2f(32.f, 32.f), player->getPos());

        if (d < minDist)
        {

            minDist = d;
            indexBestForPlayer = node.first;
        }
    }
    minDist = 100000000;
    int indexBestForEnemy;
    for (auto node:*m_graphNodePos)
    {
        double d = O::math::getDistanceCarre((sf::Vector2f)(node.second) * 64.f + sf::Vector2f(32.f, 32.f), this->getPos());

        if (d < minDist)
        {
            minDist = d;
            indexBestForEnemy = node.first;
        }
    }

    m_path = m_mapGraph->dijkstra(indexBestForEnemy, indexBestForPlayer);

    m_havePath = true;

    m_debugPath.clear();

    //std::cout <<  <<std::endl;

    if (m_path.size() >= 2 &&
        O::math::getDistance(
            this->pos,
            (sf::Vector2f) m_graphNodePos->at(m_path[1]) * 64.f + sf::Vector2f(32.f, 32.f)) 
        <=
        O::math::getDistance(
            (sf::Vector2f) m_graphNodePos->at(m_path.front()) * 64.f + sf::Vector2f(32.f, 32.f),
            (sf::Vector2f) m_graphNodePos->at(m_path[1]) * 64.f + sf::Vector2f(32.f, 32.f)) + 32.f
        &&
        O::math::getDistance(
            this->pos,
            (sf::Vector2f) m_graphNodePos->at(m_path.front()) * 64.f + sf::Vector2f(32.f, 32.f)) - 32.f
        <=
        O::math::getDistance(
            (sf::Vector2f) m_graphNodePos->at(m_path.front()) * 64.f + sf::Vector2f(32.f, 32.f),
            (sf::Vector2f) m_graphNodePos->at(m_path[1]) * 64.f + sf::Vector2f(32.f, 32.f))
        ) m_path.erase(m_path.begin());

    if (m_path.size() >= 2)
    {
        if (
            O::math::getDistance(
                player->getPos(),
                (sf::Vector2f) m_graphNodePos->at(m_path[m_path.size() - 2]) * 64.f + sf::Vector2f(32.f, 32.f)) 
            <=
            O::math::getDistance(
                (sf::Vector2f) m_graphNodePos->at(m_path.back()) * 64.f + sf::Vector2f(32.f, 32.f),
                (sf::Vector2f) m_graphNodePos->at(m_path[m_path.size() - 2]) * 64.f + sf::Vector2f(32.f, 32.f))
        ) m_path.pop_back();
    } 

    if (m_path.size() == 1)
    {
        if (
        O::math::getDistance(
            pos,
            (sf::Vector2f) m_graphNodePos->at(m_path[0]) * 64.f + sf::Vector2f(32.f, 32.f)) <= 64.f
            ) 
            m_path.clear();
        
    }

    if (m_path.size()> 0) 
    {
        
    
        m_debugPath.push_back(O::graphics::Line(
            fen, this->pos, (sf::Vector2f) m_graphNodePos->at(m_path.front()) * 64.f + sf::Vector2f(32.f, 32.f), 2
        ));
        m_debugPath.back().setFillColor(sf::Color::Green);
        for (int i = 0; i < (int)(m_path.size()) - 1; i++)
        {
            m_debugPath.push_back(O::graphics::Line(
                fen, (sf::Vector2f) m_graphNodePos->at(m_path[i]) * 64.f + sf::Vector2f(32.f, 32.f), (sf::Vector2f) m_graphNodePos->at(m_path[i + 1]) * 64.f + sf::Vector2f(32.f, 32.f), 2
            ));
            m_debugPath.back().setFillColor(sf::Color::Green);
        }

        m_debugPath.push_back(O::graphics::Line(
            fen, player->getPos(), (sf::Vector2f) m_graphNodePos->at(m_path.back()) * 64.f + sf::Vector2f(32.f, 32.f), 2
        ));
        m_debugPath.back().setFillColor(sf::Color::Green);
    
    }


}

