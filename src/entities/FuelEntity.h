//
// Created by Andrea on 25/01/2021.
//

#ifndef UNTITLEDCARGAME_FUELENTITY_H
#define UNTITLEDCARGAME_FUELENTITY_H


#include "NpcEntity.h"

class FuelEntity : public NpcEntity {

public:
    FuelEntity(const COORD &position, unsigned int id);

private:

    void collision(AbstractEntity &other) override;
    void collision(PlayerEntity &e);


};


#endif //UNTITLEDCARGAME_FUELENTITY_H
