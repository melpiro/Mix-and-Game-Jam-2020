//
// Created by etien on 14/11/2020.
//

#include "Enemies/SpitterEnemy.h"

SpitterEnemy::SpitterEnemy(sf::RenderWindow *fen, PlayerCharacter *pc) : EnemyCharacter(fen, pc) {}

void SpitterEnemy::init() {
    sprite = sf::Sprite(O::graphics::ressourceManager.getTexture("spitter_enemy"));
    sprite.setScale(4, 4);

    frameSize = 16;
    sprite.setOrigin(frameSize*0.5f, frameSize*0.5f);

    nbrFrames = 8;

    animY = 0;
    animSpeed = 0.05f;

    setAnim();
    playAnim = false;

    speed = 200;
}
