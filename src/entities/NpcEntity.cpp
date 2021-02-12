//
// Created by Andrea on 24/12/2020.
//

#include "NpcEntity.h"

NpcEntity::NpcEntity(const COORD &position, const COORD &size, unsigned int id, duration coolDown)
    : AbstractEntity(position, size, id) {
    //start = std::chrono::steady_clock::now();
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
    checkExpired();
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

