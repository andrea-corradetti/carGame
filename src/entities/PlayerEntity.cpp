//
// Created by Andrea on 22/12/2020.
//

#include "PlayerEntity.h"
#include "CarEntity.h"
#include "FuelEntity.h"
#include "NailEntity.h"
#include "NpcEntity.h"

#define PLAYER_SIZE {2, 3}

std::wstring PlayerEntity::art[] = {L"aa", L"bb", L"cc"};

PlayerEntity::PlayerEntity(const COORD &position, unsigned int id)
    : AbstractEntity(position, PLAYER_SIZE, id) {
    score = 0;
    pArt = art;
    fuel = 100;
    hp = 5;

}

void PlayerEntity::collision(AbstractEntity &other) {
    // dynamic_cast to a pointer type returns NULL if the cast fails
    // (dynamic_cast to a reference type would throw an exception on failure)
    if (auto car = dynamic_cast<CarEntity*>(&other)) {
        if (other.getOldPosition().X < this->position.X) {
            this->position.X++;
        } else if (other.getOldPosition().X > this->position.X) {
            this->position.X--;
        }
        this->score -= car->getValue();
        this->hp -= 1;
    } else if (auto fuel = dynamic_cast<FuelEntity*>(&other)) {
        this->score -= fuel->getValue();
        this->fuel += fuel->getValue();
    } else if (auto nail = dynamic_cast<NailEntity*>(&other)) {
        this->score -= nail->getValue();
        this->hp -= 1;
    } else {

    }
}

void PlayerEntity::update() {

}
