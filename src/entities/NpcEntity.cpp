//
// Created by Andrea on 24/12/2020.
//

#include "NpcEntity.h"

NpcEntity::NpcEntity(const COORD &position, unsigned int id, const COORD &size, duration coolDown)
    : AbstractEntity(position, size, id), coolDown(coolDown) {
    timeElapsed = duration(0);
}

void NpcEntity::update(duration dt) {
//    using std::chrono::steady_clock, std::chrono::duration_cast, std::chrono::duration;
//    auto end = steady_clock::now();
//    auto timeDiff = duration_cast<duration<int, std::milli>>(end - start);
    timeElapsed += dt;
    while (timeElapsed >= coolDown){
        act();
        //start = end;
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

