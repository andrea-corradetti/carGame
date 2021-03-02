//
// Created by Andrea on 22/12/2020.
//

#ifndef UNTITLEDCARGAME_PLAYERENTITY_H
#define UNTITLEDCARGAME_PLAYERENTITY_H


#include "AbstractEntity.h"
#include "../GameState.h"
#include "../globals.h"

class PlayerEntity : public AbstractEntity {
public:
    PlayerEntity(const COORD &position);
    void collisionWith(AbstractEntity &other) override;
    void update(duration dt) override;
    unsigned int hp;
    unsigned int fuel;  //todo consider making private
    static std::wstring art[];

    void moveLeft() override;

    void moveRight() override;

    void moveUp() override;

    void moveDown() override;

    void die();

public:
    unsigned int getHp() const;

    unsigned int getFuel() const;

    int getScore() const;

    std::wstring *getArt() const override;

    static PlayerEntity *spawn();

private:
    int score;
};


#endif //UNTITLEDCARGAME_PLAYERENTITY_H
