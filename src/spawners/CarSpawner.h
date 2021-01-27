//
// Created by Andrea on 22/01/2021.
//

#ifndef UNTITLEDCARGAME_CARSPAWNER_H
#define UNTITLEDCARGAME_CARSPAWNER_H


#include "AbstractSpawner.h"
#include "../entities/CarEntity.h"


class CarSpawner : public AbstractSpawner{
public:
    CarSpawner(unsigned int seed);

private:
    CarEntity* spawn(COORD position) override;
    COORD computePosition() override;
};


#endif //UNTITLEDCARGAME_CARSPAWNER_H
