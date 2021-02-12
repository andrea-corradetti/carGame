//
// Created by Andrea on 25/01/2021.
//

#include "FuelEntity.h"
#include "CarEntity.h"

#define FUEL_SIZE {1, 1}

std::wstring FuelEntity::art[] = {L"F"};

void FuelEntity::collisionWith(AbstractEntity &other) {
    // dynamic_cast to a pointer type returns NULL if the cast fails
    // (dynamic_cast to a reference type would throw an exception on failure)
    if (auto player = dynamic_cast<PlayerEntity*>(&other)) {
        // handle fuel-player collision
        player->fuel += value;
        expired = true;
    } else {
        if (other.getOldPosition().X < this->position.X) {
            moveRight();
        } else if (other.getOldPosition().X > this->position.X) {
            moveLeft();
        }
    }

}


FuelEntity::FuelEntity(const COORD &position, unsigned int id)
    : NpcEntity(position, FUEL_SIZE, id, duration()) {
    pArt = art;
    coolDown = duration(.3);
    value = 25;
}
