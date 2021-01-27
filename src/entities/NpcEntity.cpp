//
// Created by Andrea on 24/12/2020.
//

#include "NpcEntity.h"

NpcEntity::NpcEntity(const COORD &position, const COORD& size, unsigned int id)
    : AbstractEntity(position, size, id) {
    start = std::chrono::steady_clock::now();
}

void NpcEntity::update() {
    using std::chrono::steady_clock, std::chrono::duration_cast, std::chrono::duration;
    auto end = steady_clock::now();
    auto timeDiff = duration_cast<duration<int, std::milli>>(end - start);
    if(timeDiff > coolDown){
        act();
        start = end;
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

