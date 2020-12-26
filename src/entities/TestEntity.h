//
// Created by Andrea on 21/12/2020.
//

#ifndef UNTITLEDCARGAME_TESTENTITY_H
#define UNTITLEDCARGAME_TESTENTITY_H

#include "Entity.h"
#include "NpcEntity.h"

class TestEntity : public NpcEntity {
public:
    TestEntity(const COORD &position, const COORD &size, int score);
    void collision(PlayerEntity &e);
private:
    std::wstring art = L"?";
};


#endif //UNTITLEDCARGAME_TESTENTITY_H
