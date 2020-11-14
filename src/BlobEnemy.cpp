//
// Created by etien on 14/11/2020.
//

#include "BlobEnemy.h"

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
}
