//
// Created by Andrea on 27/01/2021.
//

#include "NailSpawner.h"
#include "../entities/NailEntity.h"

const float NailSpawner::baseRate = 0.25;

void NailSpawner::updateRateMultiplier(unsigned int currentLevelNo) {
    rateMultiplier = 1;
}

float NailSpawner::computeSpawnRate() {
    return 0;
}

NailEntity *NailSpawner::spawnAt(COORD position) {
    return new NailEntity(position, nextId++);
}

COORD NailSpawner::computePosition() {
    return COORD();
}

NailSpawner::NailSpawner(unsigned int seed) : AbstractSpawner(nail, seed){
    coolDown = duration(2);
}
