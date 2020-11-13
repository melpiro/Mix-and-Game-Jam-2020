//
// Created by etien on 13/11/2020.
//

#include <Omega/Graphics/RessourceManager.h>
#include "Character.h"

Character::Character(sf::RenderWindow* fen) : fen(fen) {}

void Character::init() {
    sprite = sf::Sprite(O::graphics::ressourceManager.getTexture("et_tilemap"));
    sprite.setScale(4, 4);

    frameSize = 16;
    nbrFrames = 3;

    setAnim();
    playAnim = false;
}

void Character::draw() {

    setAnim();
    fen->draw(sprite);

}

void Character::setAnim() {
    if(playAnim) {
        sprite.setTextureRect(sf::Rect<int>(sprite.getTexture()->getSize().x - direction * frameSize,
                                             animY + frameSize * animStage,
                                            frameSize,
                                            frameSize));
    }
}

void Character::update(float deltatime) {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        vel.y = std::min(-speed, vel.y);
        playAnim = true;
        direction = Up;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        vel.y = std::max(speed, vel.y);
        playAnim = true;
        direction = Down;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        vel.x = std::min(-speed, vel.x);
        playAnim = true;
        direction = Left;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        vel.x = std::max(speed, vel.x);
        playAnim = true;
        direction = Right;
    }


    if(playAnim) {
        currentAnimTime += deltatime;
        if(currentAnimTime > animSpeed) {
            animStage = (animStage + 1)%nbrFrames;
            currentAnimTime -= animSpeed;
        }
    }

    pos += vel * deltatime;
    sprite.setPosition(pos);


    vel *= dash +1;
    dash *= friction;

    vel *= friction;

    currentDashTime += deltatime;
}

void Character::setPos(const sf::Vector2f &pos) {
    Character::pos = pos;
}

void Character::setVel(const sf::Vector2f &vel) {
    Character::vel = vel;
}

void Character::setSpeed(float speed) {
    Character::speed = speed;
}

void Character::setCurrentAnim(Character::Direction currentAnim) {
    Character::direction = currentAnim;
}

void Character::setPlayAnim(bool playAnim) {
    Character::playAnim = playAnim;
}

void Character::event(sf::Event &e) {

    switch (e.type) {

        case sf::Event::KeyPressed:
            switch (e.key.code) {

                case sf::Keyboard::Key::LShift:

                    if(currentDashTime >= dashCoolDown) {
                        dash = 0.5f;
                        currentDashTime = 0;
                    }


                    break;
            }
        break;

        case sf::Event::KeyReleased:
            switch (e.key.code) {

                case sf::Keyboard::Key::Z:
                case sf::Keyboard::Key::S:
                case sf::Keyboard::Key::Q:
                case sf::Keyboard::Key::D:
                    playAnim = false;
                    break;
            }
            break;


    }

}

const sf::Vector2f &Character::getPos() const {
    return pos;
}
