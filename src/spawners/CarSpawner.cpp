//
// Created by Andrea on 22/01/2021.
//

#include "CarSpawner.h"

const float CarSpawner::baseRate = 0.2;

CarSpawner::CarSpawner(unsigned int seed) :  AbstractSpawner(car, seed) {
    coolDown = duration(5);
}

CarEntity* CarSpawner::spawnAt(COORD position) {
    return new CarEntity(position, nextId++);
}



COORD CarSpawner::computePosition() {
    PlayerEntity* player = dynamic_cast<PlayerEntity *>(CarEntity::aliveEntities.at(1));
    auto X = player->getPosition().X;
    auto Y = gameArea.Top;
    return {X, Y}; //todo implement correct position
}

void CarSpawner::updateRateMultiplier(unsigned int currentLevelNo) {
//    if (currentLevelNo <= 3) {
//        rateMultiplier = 0.1;
//    } else if (currentLevelNo <= 5) {
//        rateMultiplier = 0.5;
//    } else if (currentLevelNo <= 10) {
//        rateMultiplier = 1;
//    } else {
//        rateMultiplier = 1.3;
//    }
    rateMultiplier = 1;
}

float CarSpawner::computeSpawnRate() {
    return baseRate * rateMultiplier;
}

