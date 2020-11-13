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
    nbrFrames = 3;

    animY = 3*frameSize*nbrFrames;

    setAnim();
    playAnim = false;

    speed = 100;
}

void EnemyCharacter::update(float deltatime) {
    Character::update(deltatime);

    // Pour que l'enemie agro le joueur
    if(O::math::getDistanceCarre(pos, player->getPos()) < agroDist*agroDist && !player->isAttacked()) {

        player->setEnemyAgro(this);
        isAttacking = true;

    }

    if(isAttacking) {

        vel = O::math::normalise(player->getPos() - pos) * speed;


    }

}

EnemyCharacter::EnemyCharacter(sf::RenderWindow *fen, PlayerCharacter* pc) : Character(fen) {
    player = pc;
}
