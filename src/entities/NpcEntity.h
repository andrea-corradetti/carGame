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
    NpcEntity(const COORD &position, unsigned int id, const COORD &size, duration coolDown);
    void update(duration dt) override;
    virtual void act();

    void moveLeft() override;

    void moveRight() override;

    void moveUp() override;

    void moveDown() override;

protected:
    duration coolDown;
    int value;
public:
    int getValue() const;

    void setValue(int value);

};


#endif //UNTITLEDCARGAME_NPCENTITY_H
