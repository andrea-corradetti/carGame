//
// Created by Andrea on 24/12/2020.
//

#ifndef UNTITLEDCARGAME_NPCENTITY_H
#define UNTITLEDCARGAME_NPCENTITY_H


#include "Entity.h"
#include "PlayerEntity.h"

class NpcEntity : public Entity{
public:
    NpcEntity(const COORD &position, const COORD &size, int score);

private:
    virtual void collision(PlayerEntity &e) = 0;  //todo make true abstract
};


#endif //UNTITLEDCARGAME_NPCENTITY_H
