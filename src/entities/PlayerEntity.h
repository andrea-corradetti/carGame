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
    int hp;
    double fuel;  //todo consider making private
    static std::wstring art[];

    void moveLeft() override;

    void moveRight() override;

    void moveUp() override;

    void moveDown() override;

    void die();

public:
    int getHp() const;

    double getFuel() const;

    int getScore() const;

    std::wstring *getArt() const override;

    static PlayerEntity *spawn();
    bool checkExpired() override;

private:
    int score;

};


#endif //UNTITLEDCARGAME_PLAYERENTITY_H
