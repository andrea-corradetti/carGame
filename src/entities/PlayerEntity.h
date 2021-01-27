//
// Created by Andrea on 22/12/2020.
//

#ifndef UNTITLEDCARGAME_PLAYERENTITY_H
#define UNTITLEDCARGAME_PLAYERENTITY_H


#include "AbstractEntity.h"

class PlayerEntity : public AbstractEntity {
public:
    PlayerEntity(const COORD &position, unsigned int id);
    void collision(AbstractEntity &other) override;
    void update() override;
    unsigned int hp;
    unsigned int fuel;
    static std::wstring art[];

private:
    int score;
};


#endif //UNTITLEDCARGAME_PLAYERENTITY_H
