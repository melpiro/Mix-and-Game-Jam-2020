//
// Created by etien on 13/11/2020.
//

#include <Omega/Graphics/RessourceManager.h>
#include "PlayerCharacter.h"

void PlayerCharacter::init() {
    sprite = sf::Sprite(O::graphics::ressourceManager.getTexture("et_tilemap"));
    sprite.setScale(4, 4);

    frameSize = 16;
    sprite.setOrigin(frameSize*0.5f, frameSize*0.5f);

    nbrFrames = 3;

    animY = 0*frameSize*nbrFrames;

    setAnim();
    playAnim = false;
}

void PlayerCharacter::update(float deltatime) {
    Character::update(deltatime);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        vel.y = std::min(-speed, vel.y);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        vel.y = std::max(speed, vel.y);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        vel.x = std::min(-speed, vel.x);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        vel.x = std::max(speed, vel.x);
    }


}

void PlayerCharacter::event(sf::Event &e) {
    Character::event(e);

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


    }

}

PlayerCharacter::PlayerCharacter(sf::RenderWindow *fen) : Character(fen) {}

EnemyCharacter *PlayerCharacter::getEnemyAgro() const {
    return enemyAgro;
}

void PlayerCharacter::setEnemyAgro(EnemyCharacter *enemyAgro) {
    PlayerCharacter::enemyAgro = enemyAgro;
    attacked = enemyAgro != nullptr;
}

bool PlayerCharacter::isAttacked() const {
    return attacked;
}
