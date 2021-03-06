//
// Created by Andrea on 24/12/2020.
//

#include "NpcEntity.h"
#include "AbstractEntity.h"

NpcEntity::NpcEntity(const COORD &position, unsigned int id, const COORD &size, duration coolDown)
    : AbstractEntity(position, size, id), coolDown(coolDown) {}

void NpcEntity::update(duration dt) {
    oldPosition = position;
    timeElapsed += dt;
    while (timeElapsed >= coolDown){
        act();
        timeElapsed -= coolDown;
    }
    expired = checkExpired();
}

void NpcEntity::act() {
    moveDown();
}

int NpcEntity::getValue() const {
    return value;
}

void NpcEntity::setValue(int value) {
    NpcEntity::value = value;
}

void NpcEntity::moveRight() {
    if (getHitbox().Right < gameArea.Right) {
        position.X++;
        updateHitbox();
    }
}

void NpcEntity::moveLeft() {
    if (getHitbox().Left > gameArea.Left) {
        position.X--;
        updateHitbox();
    }
}

void NpcEntity::moveUp() {
    if (getHitbox().Top > gameArea.Top) {
        position.Y--;
        updateHitbox();
    }
}


void NpcEntity::moveDown() {
    position.Y++;
    updateHitbox();
}

