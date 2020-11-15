//
// Created by etien on 14/11/2020.
//

#include "Enemies/BlobEnemy.h"

BlobEnemy::BlobEnemy(sf::RenderWindow *fen, PlayerCharacter *pc) : EnemyCharacter(fen, pc) {}

void BlobEnemy::init() {
    sprite = sf::Sprite(O::graphics::ressourceManager.getTexture("blob_enemy"));
    sprite.setScale(4, 4);

    frameSize = 16;
    sprite.setOrigin(frameSize*0.5f, frameSize*0.5f);

    nbrFrames = 4;

    animY = 0;

    setAnim();
    playAnim = false;

    speed = 100;

    life = 4;

    initHealthBar();
}


void BlobEnemy::onCollide(Character *other) {
    Character::onCollide(other);

    if(other->getType() == Player) {
        other->applyDamage(1);
        other->setVel(O::math::normalise(other->getPos() - pos) * 1000.f);
    }
}

inline Character::Type BlobEnemy::getType() {
    return Blob;
}
