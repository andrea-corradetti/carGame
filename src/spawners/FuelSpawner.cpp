//
// Created by Andrea on 27/01/2021.
//

#include "FuelSpawner.h"

FuelSpawner::FuelSpawner(unsigned int seed, float baseRate) : AbstractSpawner(fuel, seed, baseRate) {
    coolDown = duration(10);
}


FuelEntity *FuelSpawner::spawnAt(COORD position) {
    return new FuelEntity(position, nextId++);
}

void FuelSpawner::updateRateMultiplier(unsigned int currentLevelNo) {   //todo add correct multiplier
    if (currentLevelNo <= 5) {
        rateMultiplier = 0.5;
    } else if (currentLevelNo <= 10) {
        rateMultiplier = 0.4;
    } else if (currentLevelNo <= 15) {
        rateMultiplier = 0.35;
    } else {
        rateMultiplier = 0.3;
    }
}

