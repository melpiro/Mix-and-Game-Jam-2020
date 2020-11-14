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

    life = 10;
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

    if(isAttacked())
        enemiesAgro[targetedEnemy]->getMiniTetris()->update();
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

                case sf::Keyboard::Key::RControl:
                    if(isAttacked())
                        targetedEnemy = (targetedEnemy + 1)%enemiesAgro.size();
                    break;

            }
            break;


    }

    if(isAttacked())
        enemiesAgro[targetedEnemy]->getMiniTetris()->event(e);
}

PlayerCharacter::PlayerCharacter(sf::RenderWindow *fen) : Character(fen) {}

void PlayerCharacter::addEnemyAgro(EnemyCharacter *enemy) {
    PlayerCharacter::enemiesAgro.push_back(enemy);
}

bool PlayerCharacter::isAttacked() const {
    return !enemiesAgro.empty();
}

void PlayerCharacter::removeEnemyAgro(EnemyCharacter *enemy) {
    for(int i = 0; i < enemiesAgro.size(); i++)
        if(enemiesAgro[i] == enemy)
            enemiesAgro.erase(enemiesAgro.begin()+i);

    if(targetedEnemy >= enemiesAgro.size())
        targetedEnemy = 0;
}

void PlayerCharacter::draw() {
    Character::draw();

    if(isAttacked())
        enemiesAgro[targetedEnemy]->getMiniTetris()->render();

}

sf::Vector2f PlayerCharacter::getCameraPos() {
    if(isAttacked()) {
        return {(pos.x + enemiesAgro[targetedEnemy]->getPos().x)*0.5f, (pos.y + enemiesAgro[targetedEnemy]->getPos().y)*0.5f};
    }
    return pos;
}
