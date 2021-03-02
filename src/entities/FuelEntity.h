//
// Created by Andrea on 25/01/2021.
//

#ifndef UNTITLEDCARGAME_FUELENTITY_H
#define UNTITLEDCARGAME_FUELENTITY_H


#include "NpcEntity.h"

class FuelEntity : public NpcEntity {

public:
    FuelEntity(const COORD &position, unsigned int id);
    std::wstring *getArt() const override;

private:
    void collisionWith(AbstractEntity &other) override;

    static std::wstring art[];
};


#endif //UNTITLEDCARGAME_FUELENTITY_H
