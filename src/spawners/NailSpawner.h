//
// Created by Andrea on 27/01/2021.
//

#ifndef UNTITLEDCARGAME_NAILSPAWNER_H
#define UNTITLEDCARGAME_NAILSPAWNER_H


#include "AbstractSpawner.h"
#include "../entities/NailEntity.h"

class NailSpawner: public AbstractSpawner {
protected:
    NailEntity *spawn(COORD position) override;

    COORD computePosition() override;
};


#endif //UNTITLEDCARGAME_NAILSPAWNER_H
