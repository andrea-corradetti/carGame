//
// Created by Andrea on 22/01/2021.
//

#include "CarSpawner.h"



CarSpawner::CarSpawner(unsigned int seed, float baseRate) : AbstractSpawner(car, seed, baseRate) {
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
    if (currentLevelNo <= 5) {
        rateMultiplier = 0.5;
    } else if (currentLevelNo <= 10) {
        rateMultiplier = 0.8;
    } else if (currentLevelNo <= 15) {
        rateMultiplier = 1;
    } else {
        rateMultiplier = 1;
    }
}

