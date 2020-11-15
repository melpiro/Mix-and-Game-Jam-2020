//
// Created by Alarm on 14/11/2020.
//

#include "Object.h"

void Object::init() {

}

void Object::draw() {

}

void Object::update(float deltatime) {

}

void Object::event(sf::Event &e) {

}

void Object::setPosition(sf::Vector2f pos) {
    m_pos = pos;
}

void Object::setFen(sf::RenderWindow *f) {
    m_fen = f;
}
