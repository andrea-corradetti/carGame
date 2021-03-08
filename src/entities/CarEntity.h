//
// Created by Andrea on 22/01/2021.
//

#ifndef UNTITLEDCARGAME_CARENTITY_H
#define UNTITLEDCARGAME_CARENTITY_H


#include "NpcEntity.h"

class CarEntity : public NpcEntity {
    void act() override;
    int hp;

public:
    CarEntity(const COORD &position, unsigned int id);
    void collisionWith(AbstractEntity &other) override;

    std::wstring *getArt() const override;

    static std::wstring art[];

};


#endif //UNTITLEDCARGAME_CARENTITY_H
