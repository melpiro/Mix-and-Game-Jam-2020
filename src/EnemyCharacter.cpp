//
// Created by etien on 13/11/2020.
//

#include <Omega/Graphics/RessourceManager.h>
#include "EnemyCharacter.h"
#include "PlayerCharacter.h"

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
}

void EnemyCharacter::update(float deltatime) {
    Character::update(deltatime);
    miniTetris.update();
    miniTetris.setPosition(pos.x, pos.y -(sprite.getLocalBounds().height*0.5f * sprite.getScale().y + miniTetris.getWindowSize().y*0.5f));


    // Pour que l'enemie agro le joueur
    if(O::math::getDistanceCarre(pos, player->getPos()) < agroDist*agroDist && !player->isAttacked()) {

        player->setEnemyAgro(this);
        isAttacking = true;
        miniTetris.start();

    }

    if(isAttacking) {

        vel = O::math::normalise(player->getPos() - pos) * speed;

        if(miniTetris.defeat()) {
            player->setEnemyAgro(nullptr);
            isAttacking = false;
        }

    }

}

EnemyCharacter::EnemyCharacter(sf::RenderWindow *fen, PlayerCharacter* pc) : Character(fen), miniTetris(fen) {
    player = pc;

    miniTetris.setPosition(pos.x, pos.y);
    miniTetris.setWindowSize(50,130);
    miniTetris.setTileSize(5,13);
}

void EnemyCharacter::draw() {
    Character::draw();
    miniTetris.render();
}

void EnemyCharacter::event(sf::Event &e) {
    Character::event(e);
    miniTetris.event(e);
}
