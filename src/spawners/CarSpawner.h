//
// Created by Andrea on 22/01/2021.
//

#ifndef UNTITLEDCARGAME_CARSPAWNER_H
#define UNTITLEDCARGAME_CARSPAWNER_H


#include "Spawner.h"
#include "../entities/CarEntity.h"


class CarSpawner : public Spawner{
public:
    CarSpawner(EntityManager &em, entity_type type);

private:
    CarEntity* spawn(COORD position) override;
    COORD computePosition() override;
};


#endif //UNTITLEDCARGAME_CARSPAWNER_H
