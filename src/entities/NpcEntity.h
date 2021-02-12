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
    NpcEntity(const COORD &position, const COORD &size, unsigned int id, duration coolDown);
    void update(duration dt) override;
    virtual void act();

    void moveLeft() override;

    void moveRight() override;

    void moveUp() override;

    void moveDown() override;

protected:
    duration timeElapsed;
    duration coolDown;
    //std::chrono::steady_clock::time_point start;



    int value;
public:
    int getValue() const;

    void setValue(int value);

};


#endif //UNTITLEDCARGAME_NPCENTITY_H
