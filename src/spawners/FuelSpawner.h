//
// Created by Andrea on 27/01/2021.
//

#ifndef UNTITLEDCARGAME_FUELSPAWNER_H
#define UNTITLEDCARGAME_FUELSPAWNER_H


#include <random>
#include "AbstractSpawner.h"
#include "../entities/FuelEntity.h"

class FuelSpawner: public AbstractSpawner {

public:
    FuelSpawner(unsigned int seed);

    void updateRateMultiplier(unsigned int currentLevelNo) override;

protected:
    float computeSpawnRate() override;

    FuelEntity *spawnAt(COORD position) override;
    static const float baseRate;
};


#endif //UNTITLEDCARGAME_FUELSPAWNER_H
