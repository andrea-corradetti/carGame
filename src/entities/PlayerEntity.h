//
// Created by Andrea on 22/12/2020.
//

#ifndef UNTITLEDCARGAME_PLAYERENTITY_H
#define UNTITLEDCARGAME_PLAYERENTITY_H


#include "AbstractEntity.h"

class PlayerEntity : public AbstractEntity {
public:
    PlayerEntity(const COORD &position, unsigned int id);
    void collisionWith(AbstractEntity &other) override;
    void update(duration dt) override;
    unsigned int hp;
    unsigned int fuel;
    static std::wstring art[];

    void moveLeft() override;

    void moveRight() override;

    void moveUp() override;

    void moveDown() override;

private:
    int score;
public:
    int getScore() const;
};


#endif //UNTITLEDCARGAME_PLAYERENTITY_H
