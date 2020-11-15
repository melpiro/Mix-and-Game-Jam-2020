//
// Created by etien on 13/11/2020.
//

#ifndef MIXGAMEJAM2020_CHARACTER_H
#define MIXGAMEJAM2020_CHARACTER_H

#include <SFML/Graphics.hpp>
#include <Omega/Graphics/ChargingBar.h>
#include "Tilemap.h"
#include "Omega/Math/MathFunctions.h"

class Character {

    static int nextID;

protected:

    static Character* player;


    int id;

    enum Direction {
        Left = 4,
        Down = 3,
        Up = 2,
        Right = 1
    };

    sf::RenderWindow* fen;

    sf::Vector2f pos;
    sf::Vector2f vel;

    float friction = 0.9f;
    float speed = 200.0f;

    float dash = 0;

    sf::Sprite sprite;
    // Sprite anim
    int nbrFrames, frameSize;
    Direction direction = Down;
    int animStage = 0;
    int animY = 0;
    float animSpeed = 0.1; // s
    float currentAnimTime = 0;
    bool playAnim = true;

    float dashCoolDown = 0.7f; // s
    float currentDashTime = 0;

    float life = 1;
    bool dead = false;
    O::graphics::ChargingBar m_healthBar;


    explicit Character(sf::RenderWindow* fen);


    Tilemap* m_map = NULL;

    void initHealthBar();

    // -- graph

    std::map<int, sf::Vector2i>* m_graphNodePos;
    O::math::Graph<int>* m_mapGraph;

public:

    void setTileMap(Tilemap* map);

    virtual void init();
    virtual void draw();
    virtual void update(float deltatime);
    virtual void event(sf::Event &e);
    virtual void onCollide(Character* other);

    void setAnim();
    void setPos(const sf::Vector2f &pos);
    void setVel(const sf::Vector2f &vel);
    void setSpeed(float speed);
    void setCurrentAnim(Direction currentAnim);
    void setPlayAnim(bool playAnim);


    float getLife() const;

    sf::Vector2f &getPos();
    sf::FloatRect getRect() const;
    sf::FloatRect getHitbox() const;

    virtual void applyDamage(float dmg);
    void kill();

    bool isDead() const;
    int getId() const;


    enum Type {
        Player,
        NoType,
        Spitter,
        Blob,
        Clone
    };

    virtual Type getType() {
        return NoType;
    }

};


#endif //MIXGAMEJAM2020_CHARACTER_H
