//
// Created by Andrea on 27/01/2021.
//

#ifndef UNTITLEDCARGAME_NAILSPAWNER_H
#define UNTITLEDCARGAME_NAILSPAWNER_H


#include <random>
#include "AbstractSpawner.h"
#include "../entities/NailEntity.h"
#include "../EntityManager.h"

class NailSpawner: public AbstractSpawner {
    NailSpawner(unsigned int seed);


protected:

    NailEntity *spawnAt(COORD position) override;

    COORD computePosition() override;

public:
    void updateRateMultiplier(unsigned int currentLevelNo) override;

protected:
    float computeSpawnRate() override;

    static const float baseRate;
};


#endif //UNTITLEDCARGAME_NAILSPAWNER_H
