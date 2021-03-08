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
    CarSpawner(unsigned int seed, float baseRate = 0.5);

private:
    CarEntity* spawnAt(COORD position) override;
    COORD computePosition() override;

protected:

    void updateRateMultiplier(unsigned int currentLevelNo) override;


};


#endif //UNTITLEDCARGAME_CARSPAWNER_H
