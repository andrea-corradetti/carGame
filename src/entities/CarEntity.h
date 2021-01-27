//
// Created by Andrea on 22/01/2021.
//

#ifndef UNTITLEDCARGAME_CARENTITY_H
#define UNTITLEDCARGAME_CARENTITY_H


#include "NpcEntity.h"

class CarEntity : public NpcEntity {
    void act() override;

public:
    CarEntity(const COORD &position, unsigned int id);
    void collision(AbstractEntity &other) override;

    static std::wstring art[];

};


#endif //UNTITLEDCARGAME_CARENTITY_H
