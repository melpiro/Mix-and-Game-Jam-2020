//
// Created by etien on 14/11/2020.
//

#include "EnemyManager.h"
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

    speed = 250;

    initHealthBar();
}

void SpitterEnemy::update(float deltatime) {
    EnemyCharacter::update(deltatime);


    if(O::math::getDistanceCarre(player->getPos(), pos) <= shootDistance*shootDistance) {
        vel = {0, 0};
    }

    if(isAttacking) {
        fireRateTime += deltatime;
        if(fireRateTime >= fireRate) {
            Projectile proj(fen, sf::Vector2f(pos), O::math::normalise(player->getPos() - pos) * 5.f);
            proj.dmg = 0.5f;
            EnemyManager::addProjectile(proj);
            fireRateTime = 0;
        }
    }

}
