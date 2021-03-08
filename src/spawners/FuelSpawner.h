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
    FuelSpawner(unsigned int seed, float baseRate = 0.7);

    void updateRateMultiplier(unsigned int currentLevelNo) override;

protected:

    FuelEntity *spawnAt(COORD position) override;
    static const float baseRate;
};


#endif //UNTITLEDCARGAME_FUELSPAWNER_H
