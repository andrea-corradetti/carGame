//
// Created by Andrea on 24/12/2020.
//

#ifndef UNTITLEDCARGAME_NPCENTITY_H
#define UNTITLEDCARGAME_NPCENTITY_H


#include <chrono>
#include <windows.h>
#include <string>
#include <map>
#include <vector>
#include "AbstractEntity.h"
#include "PlayerEntity.h"
#include "../globals.h"

class NpcEntity : public AbstractEntity{
public:
    NpcEntity(const COORD &position, const COORD& size, unsigned int id);
    virtual void act();
    void update() override;


protected:
    std::chrono::duration<int, std::milli> coolDown;
    std::chrono::steady_clock::time_point start;

    int value;
public:
    int getValue() const;

    void setValue(int value);
};


#endif //UNTITLEDCARGAME_NPCENTITY_H
