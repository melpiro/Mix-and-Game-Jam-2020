//
// Created by etien on 13/11/2020.
//

#include <Omega/Graphics/RessourceManager.h>
#include <EnemyManager.h>
#include "EnemyCharacter.h"
#include "PlayerCharacter.h"


EnemyCharacter::EnemyCharacter(sf::RenderWindow *fen, PlayerCharacter* pc) : Character(fen), miniTetris(fen) {
    player = pc;

    miniTetris.setPosition(pos.x, pos.y);
    miniTetris.setWindowSize(60*1.5f,140*1.5f);
    miniTetris.setTileSize(5,13);
}

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

    miniTetris.setSpeed(sf::seconds(0.5));

}

void EnemyCharacter::update(float deltatime) {
    Character::update(deltatime);
    miniTetris.setPosition(pos.x, pos.y -(sprite.getLocalBounds().height*0.5f * sprite.getScale().y + miniTetris.getWindowSize().y*0.5f) - getRect().height*0.1f);


    // Pour que l'enemie agro le joueur
    if(O::math::getDistanceCarre(pos, player->getPos()) < agroDist*agroDist && !isAttacking) {

        player->addEnemyAgro(this);
        isAttacking = true;
        miniTetris.start();

    }

    else if(isAttacking) {

        vel = O::math::normalise(player->getPos() - pos) * speed;

        if(miniTetris.getScore() > 0) {
            miniTetris.setScore(miniTetris.getScore()-1);
            applyDamage(1);
            if(dead) {
                player->removeEnemyAgro(this);
                isAttacking = false;
                EnemyManager::killEnemy(id);
            }
        }

        else if(miniTetris.defeat()) {
            player->applyDamage(1);
            miniTetris.start();
        }


        else if(O::math::getDistanceCarre(pos, player->getPos()) > loseAgroDist*loseAgroDist) {
            player->removeEnemyAgro(this);
            isAttacking = false;
        }


    }

}

void EnemyCharacter::draw() {
    Character::draw();
}

void EnemyCharacter::event(sf::Event &e) {
    Character::event(e);
}

MiniTetris* EnemyCharacter::getMiniTetris() {
    return &miniTetris;
}

int EnemyCharacter::operator==(const EnemyCharacter &other) const {
    return id == other.id;
}

int EnemyCharacter::operator!=(const EnemyCharacter &other) const {
    return id != other.id;
}
