//
// Created by Andrea on 27/01/2021.
//

#include "NailSpawner.h"
#include "../entities/NailEntity.h"

NailSpawner::NailSpawner(unsigned int seed, float baseRate) : AbstractSpawner(nail, seed, baseRate) {
    coolDown = duration(3);
}


void NailSpawner::updateRateMultiplier(unsigned int currentLevelNo) {
    if (currentLevelNo <= 5) {
        rateMultiplier = 0.4;
    } else if (currentLevelNo <= 10) {
        rateMultiplier = 0.5;
    } else if (currentLevelNo <= 15) {
        rateMultiplier = 0.8;
    } else {
        rateMultiplier = 1;
    }
}


NailEntity *NailSpawner::spawnAt(COORD position) {
    return new NailEntity(position, nextId++);
}



