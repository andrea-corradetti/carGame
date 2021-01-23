//
// Created by Andrea on 22/01/2021.
//

#include "CarEntity.h"

#define CAR_SIZE {2, 3}

std::wstring CarEntity::art[] = {L"00", L"II", L"00"};

void CarEntity::act() {
    moveDown();
    //if (this->position.Y <= pl)
}

void CarEntity::collision(Entity &e) {
    e.setScore(e.getScore() + this->score);
    expired = true;
}

CarEntity::CarEntity(const COORD &position, unsigned int id) : NpcEntity(position, CAR_SIZE, id) {
    pArt = art;
    setScore(-20);
    coolDown = std::chrono::duration<int, std::milli>(300);
}
