//
// Created by Andrea on 27/01/2021.
//

#include "FuelSpawner.h"
#include "../entities/FuelEntity.h"

const float FuelSpawner::baseRate = 0.5;

FuelEntity *FuelSpawner::spawnAt(COORD position) {
    return new FuelEntity(position, nextId++);
}

void FuelSpawner::updateRateMultiplier(unsigned int currentLevelNo) {   //todo add correct multiplier
/*    if (currentLevelNo <= 3) {
        rateMultiplier = 5;
    } else if (currentLevelNo <= 5) {
        rateMultiplier = 0.5;
    } else if (currentLevelNo <= 10) {
        rateMultiplier = 1;
    } else {
        rateMultiplier = 1.3;
    }*/
    rateMultiplier = 2;
}

float FuelSpawner::computeSpawnRate() {
    return baseRate * rateMultiplier;
}


FuelSpawner::FuelSpawner(unsigned int seed) : AbstractSpawner(fuel, seed) {
    coolDown = duration(5);
}
