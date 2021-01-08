//
// Created by Andrea on 24/12/2020.
//

#ifndef UNTITLEDCARGAME_NPCENTITY_H
#define UNTITLEDCARGAME_NPCENTITY_H


#include "Entity.h"
#include "PlayerEntity.h"

class NpcEntity : public Entity{
public:
    NpcEntity(const COORD &position, const COORD&size, unsigned int id);

protected:
    std::chrono::duration<int, std::milli> coolDown;
    std::chrono::steady_clock::time_point start;

};


#endif //UNTITLEDCARGAME_NPCENTITY_H
