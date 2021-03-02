//
// Created by Andrea on 27/01/2021.
//

#ifndef UNTITLEDCARGAME_NAILSPAWNER_H
#define UNTITLEDCARGAME_NAILSPAWNER_H


#include <random>
#include "AbstractSpawner.h"
#include "../entities/NailEntity.h"

class NailSpawner: public AbstractSpawner {

public:
    void updateRateMultiplier(unsigned int currentLevelNo) override;

    NailSpawner(unsigned int seed);

protected:

    NailEntity *spawnAt(COORD position) override;
    float computeSpawnRate() override;
    static const float baseRate;
};


#endif //UNTITLEDCARGAME_NAILSPAWNER_H
