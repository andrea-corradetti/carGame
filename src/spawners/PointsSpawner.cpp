//
// Created by Andrea on 05/03/2021.
//

#include "PointsSpawner.h"


void PointsSpawner::updateRateMultiplier(unsigned int currentLevelNo) {
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

PointsEntity *PointsSpawner::spawnAt(COORD position) {
    return new PointsEntity(position, nextId++);
}

PointsSpawner::PointsSpawner(unsigned int seed, float baseRate)
: AbstractSpawner(points, seed, baseRate) {
    coolDown = duration(3);
}
