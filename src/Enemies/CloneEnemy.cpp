//
// Created by etien on 15/11/2020.
//
#include "PlayerCharacter.h"
#include "Enemies/CloneEnemy.h"

CloneEnemy::CloneEnemy(sf::RenderWindow *fen, PlayerCharacter *pc) : EnemyCharacter(fen, pc) {

}

void CloneEnemy::init() {
    sprite = sf::Sprite(O::graphics::ressourceManager.getTexture("clone_enemy"));
    sprite.setScale(4, 4);

    frameSize = 16;
    sprite.setOrigin(frameSize*0.5f, frameSize*0.5f);

    nbrFrames = 3;
    animSpeed = 0.06f;

    animY = 0;

    setAnim();
    playAnim = false;

    speed = 350;

    health = 8;

    initHealthBar();
}

void CloneEnemy::onCollide(Character *other) {
    Character::onCollide(other);

    if(other->getType() == Player) {
        other->applyDamage(1);
        other->setVel(O::math::normalise(other->getPos() - pos) * 1500.f);

        phase = Flee;
        speed = 650;

        sf::Vector2i nextTarget = m_graphNodePos->at(O::math::rdm::randInt(0, m_graphNodePos->size()) );
        targetPoint = new sf::Vector2f(nextTarget);
        *targetPoint *= 64.f;
        m_havePath = false;

    }
}

Character::Type CloneEnemy::getType() {
    return Clone;
}

void CloneEnemy::update(float deltatime) {
    EnemyCharacter::update(deltatime);

    switch (phase) {

        case Attack:
            // RAS
            break;

        case Flee:
            isAttacking = true;
            if(O::math::getDistanceCarre(pos, *targetPoint) < 50*50) {
                targetPoint = &player->getPos();
                speed = 350;
                phase = Attack;
                isAttacking = false;
            }
            break;
    }
}
