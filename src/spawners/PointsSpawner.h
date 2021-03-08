//
// Created by Andrea on 05/03/2021.
//

#ifndef UNTITLEDCARGAME_POINTSSPAWNER_H
#define UNTITLEDCARGAME_POINTSSPAWNER_H


#include "AbstractSpawner.h"
#include "../entities/PointsEntity.h"

class PointsSpawner : public AbstractSpawner {
public:
    PointsSpawner(unsigned int seed, float baseRate = 0.5);

    void updateRateMultiplier(unsigned int currentLevelNo) override;

protected:
    PointsEntity * spawnAt(COORD position) override;
};


#endif //UNTITLEDCARGAME_POINTSSPAWNER_H
