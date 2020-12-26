//
// Created by Andrea on 22/12/2020.
//

#ifndef UNTITLEDCARGAME_PLAYERENTITY_H
#define UNTITLEDCARGAME_PLAYERENTITY_H


#include "Entity.h"

class PlayerEntity : public Entity {
public:
    PlayerEntity(const COORD &position, const COORD &size, int score);

    static std::wstring art[];

};


#endif //UNTITLEDCARGAME_PLAYERENTITY_H