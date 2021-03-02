//
// Created by Andrea on 27/01/2021.
//

#include "NailSpawner.h"
#include "../entities/NailEntity.h"

const float NailSpawner::baseRate = 1;

void NailSpawner::updateRateMultiplier(unsigned int currentLevelNo) {
    if (currentLevelNo <= 3) {
        rateMultiplier = 0.1;
    } else if (currentLevelNo <= 5) {
        rateMultiplier = 0.5;
    } else if (currentLevelNo <= 10) {
        rateMultiplier = 1;
    } else {
        rateMultiplier = 1.3;
    }
}

float NailSpawner::computeSpawnRate() {
    return baseRate * rateMultiplier;
}

NailEntity *NailSpawner::spawnAt(COORD position) {
    return new NailEntity(position, nextId++);
}


NailSpawner::NailSpawner(unsigned int seed) : AbstractSpawner(nail, seed){
    coolDown = duration(1);
}

