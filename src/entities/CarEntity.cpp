//
// Created by Andrea on 22/01/2021.
//

#include "CarEntity.h"
#include "NpcEntity.h"
#include "FuelEntity.h"
#include "AbstractEntity.h"

#define CAR_SIZE {2, 3}

std::wstring CarEntity::art[] = {L"00", L"II", L"00"};

CarEntity::CarEntity(const COORD &position, unsigned int id)
: NpcEntity(position, id, CAR_SIZE, duration(1)), hp(2) {
    value = -25;
}


void CarEntity::act() {
    auto player = CarEntity::aliveEntities.at(1);
    moveDown();
    if (position.X < player->getPosition().X) {
        moveRight();
    }
    else if (position.X > player->getPosition().X){
        moveLeft();
    }
}

void CarEntity::collisionWith(AbstractEntity &other) {
    if (auto player = dynamic_cast<PlayerEntity*>(&other)) {
        if (--hp <= 0) {
            expired = true;
        }

        if (hitbox.Bottom <= other.getHitbox().Top) {
            moveUp();

        } else if (hitbox.Top >= other.getHitbox().Bottom) {
            moveDown();
        }

        if (player->getOldPosition().X < this->getOldPosition().X) {
            moveRight();
        } else if (player->getOldPosition().X > this->position.X) {
            moveLeft();
        }
        timeElapsed = duration(0);
    } else if (auto fuel = dynamic_cast<FuelEntity*>(&other)) {

    }
}

std::wstring *CarEntity::getArt() const {
    return art;
}

