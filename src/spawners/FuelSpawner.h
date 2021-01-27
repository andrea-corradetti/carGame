//
// Created by Andrea on 27/01/2021.
//

#ifndef UNTITLEDCARGAME_FUELSPAWNER_H
#define UNTITLEDCARGAME_FUELSPAWNER_H


#include "AbstractSpawner.h"
#include "../entities/FuelEntity.h"

class FuelSpawner: public AbstractSpawner {
protected:
    FuelEntity *spawn(COORD position) override;

    COORD computePosition() override;
};


#endif //UNTITLEDCARGAME_FUELSPAWNER_H
