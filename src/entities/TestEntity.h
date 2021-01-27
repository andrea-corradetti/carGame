//
// Created by Andrea on 21/12/2020.
//

#ifndef UNTITLEDCARGAME_TESTENTITY_H
#define UNTITLEDCARGAME_TESTENTITY_H


#include "AbstractEntity.h"
#include "NpcEntity.h"

class TestEntity : public NpcEntity {
public:
    TestEntity(const COORD &position, unsigned int id);
    void collision(AbstractEntity &other);
    void act() override;
private:
    std::wstring art = L"?";
};


#endif //UNTITLEDCARGAME_TESTENTITY_H
