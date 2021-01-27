//
// Created by Andrea on 25/01/2021.
//

#include "FuelEntity.h"
#include "CarEntity.h"

#define FUEL_SIZE {1, 1}

void FuelEntity::collision(AbstractEntity &other) {
    // dynamic_cast to a pointer type returns NULL if the cast fails
    // (dynamic_cast to a reference type would throw an exception on failure)
    if (auto player = dynamic_cast<PlayerEntity*>(&other)) {
        // handle fuel-player collision
        expired = true;
    } else {
        if (other.getOldPosition().X < this->position.X) {
            this->position.X++;
        }
        else if (other.getOldPosition().X > this->position.X) {
            this->position.X--;
        }
    }

}

FuelEntity::FuelEntity(const COORD &position, unsigned int id)
    : NpcEntity(position, FUEL_SIZE, id) {
    value = 25;
}
