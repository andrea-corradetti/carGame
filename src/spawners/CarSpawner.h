//
// Created by Andrea on 22/01/2021.
//

#ifndef UNTITLEDCARGAME_CARSPAWNER_H
#define UNTITLEDCARGAME_CARSPAWNER_H


#include <random>
#include "AbstractSpawner.h"
#include "../entities/CarEntity.h"


class CarSpawner : public AbstractSpawner{
public:
    CarSpawner(unsigned int seed);

protected:
    static const float baseRate;

private:
    CarEntity* spawnAt(COORD position) override;
    COORD computePosition() override;

protected:
    //float updateSpawnRate(unsigned int currentLevel) override;

    void updateRateMultiplier(unsigned int currentLevelNo) override;

    float computeSpawnRate() override;


};


#endif //UNTITLEDCARGAME_CARSPAWNER_H
