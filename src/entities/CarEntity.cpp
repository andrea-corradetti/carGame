//
// Created by Andrea on 22/01/2021.
//

#include "CarEntity.h"
#include "NpcEntity.h"

#define CAR_SIZE {2, 3}

std::wstring CarEntity::art[] = {L"00", L"II", L"00"};

CarEntity::CarEntity(const COORD &position, unsigned int id) : NpcEntity(position, CAR_SIZE, id) {
    pArt = art;
    coolDown = std::chrono::duration<int, std::milli>(300);
    value = -20;
}


void CarEntity::act() {
    moveDown();
    //if (this->position.Y <= pl)
}

void CarEntity::collision(AbstractEntity &other) {
    if (auto player = dynamic_cast<PlayerEntity*>(&other)) {
        if (other.getOldPosition().X < this->position.X) {
            this->position.X++;
        }
        else if (other.getOldPosition().X > this->position.X) {
            this->position.X--;
        }
    } else {

    }
}

