//
// Created by Alarm on 14/11/2020.
//

#ifndef MIXGAMEJAM2020_OBJECT_H
#define MIXGAMEJAM2020_OBJECT_H


#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>

class Object {

protected:

    sf::Vector2f m_pos;
    sf::FloatRect m_collider;
    sf::Texture* m_texture;
    sf::RenderWindow* m_fen;

public:

    virtual void init();
    virtual void draw();
    virtual void update(float deltatime);
    virtual void event(sf::Event &e);

    void setPosition(sf::Vector2f pos);
    void setFen(sf::RenderWindow* f);

};


#endif //MIXGAMEJAM2020_OBJECT_H
