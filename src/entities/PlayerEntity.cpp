//
// Created by Andrea on 22/12/2020.
//

#include "PlayerEntity.h"
#include "CarEntity.h"
#include "FuelEntity.h"
#include "NailEntity.h"
#include "NpcEntity.h"
#include "../globals.h"
#include "PointsEntity.h"

const COORD spawnPosition {5, 10};
const COORD playerSize {2, 3};
const int playerId = 1;

std::wstring PlayerEntity::art[] = {L"aa", L"bb", L"cc"};

PlayerEntity::PlayerEntity(const COORD &position)
    : AbstractEntity(position, playerSize, playerId), score(0), fuel(100), hp(1) {}

PlayerEntity *PlayerEntity::spawn() {
    auto iter = aliveEntities.find(playerId);
    if(iter == aliveEntities.end()) {
        return new PlayerEntity(spawnPosition);
    }
    else {
        PlayerEntity *p = dynamic_cast<PlayerEntity *>(iter->second);
        return p;
    }
}


void PlayerEntity::collisionWith(AbstractEntity &other) {
    // dynamic_cast to a pointer type returns NULL if the cast fails
    // (dynamic_cast to a reference type would throw an exception on failure)
    if (auto car = dynamic_cast<CarEntity*>(&other)) {
        if (other.getOldPosition().X < this->getOldPosition().X) {
            moveRight();
        } else if (other.getOldPosition().X > this->getOldPosition().X) {
            moveLeft();
        }

        if (hitbox.Bottom <= car->getHitbox().Top) {
            moveUp();
        } else if (hitbox.Top >= car->getHitbox().Bottom) {
            moveDown();
        }
        this->score += car->getValue();
        this->hp -= 1;

    } else if (auto fuel = dynamic_cast<FuelEntity*>(&other)) {
        this->score += fuel->getValue();
        this->fuel += fuel->getValue();

    } else if (auto nail = dynamic_cast<NailEntity*>(&other)) {
        this->score -= nail->getValue();
        this->hp -= 1;

    } else if (auto points = dynamic_cast<PointsEntity*>(&other)){
        this->score += points->getValue();
    }

}

std::wstring *PlayerEntity::getArt() const {
    return art;
}

void PlayerEntity::update(duration dt) {
    oldPosition = position;
    fuel -= dt.count();

    if (hp <= 0 || fuel <= 0) {
        die();
    }
}

void PlayerEntity::moveRight() {
    if (getHitbox().Right < gameArea.Right) {
        position.X++;
        updateHitbox();
    }
}

void PlayerEntity::moveLeft() {
    if (getHitbox().Left > gameArea.Left) {
        position.X--;
        updateHitbox();
    }
}

void PlayerEntity::moveUp() {
    if (getHitbox().Top > gameArea.Top) {
        position.Y--;
        updateHitbox();
    }
}

void PlayerEntity::moveDown() {
    if (getHitbox().Bottom < gameArea.Bottom) {
        position.Y++;
        updateHitbox();
    }
}

int PlayerEntity::getScore() const {
    return score;
}

void PlayerEntity::die() {
    expired = true;
    gameState.changeStateTo(states::dead);
}

int PlayerEntity::getHp() const {
    return hp;
}

double PlayerEntity::getFuel() const {
    return fuel;
}

bool PlayerEntity::checkExpired() {
    return AbstractEntity::checkExpired();
}