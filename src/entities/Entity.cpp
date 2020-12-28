//
// Created by Andrea on 21/12/2020.
//

#include "Entity.h"


Entity::Entity(const COORD &position, const COORD &size, int score) : size(size), position(position), score(score), oldPosition(position) {
    updateSrHitbox();
}


const COORD &Entity::getPosition() const {
    return position;
}

const COORD &Entity::getSize() const {
    return size;
}

std::wstring *Entity::getPArt() const {
    return pArt;
}

void Entity::moveRight() {
    if (getSrHitbox().Right < maxPositionX) {
        position.X++;
        updateSrHitbox();
    }
}

void Entity::moveLeft() {
    if (getSrHitbox().Left > minPositionX) {
        position.X--;
        updateSrHitbox();
    }
}

void Entity::moveUp() {
    if (getSrHitbox().Top > minPositionY) {
        position.Y--;
        updateSrHitbox();
    }
}

void Entity::moveDown() {
    if (getSrHitbox().Bottom < maxPositionY) {
        position.Y++;
        updateSrHitbox();
    }
}

void Entity::updateSrHitbox() {
    srHitbox.Top = position.Y;
    srHitbox.Bottom = position.Y + size.Y;
    srHitbox.Left = position.X;
    srHitbox.Right = position.X + size.X;
}

const SMALL_RECT &Entity::getSrHitbox() const {
    return srHitbox;
}

const COORD &Entity::getOldPosition() const {
    return oldPosition;
}

void Entity::setOldPosition(const COORD &oldPosition) {
    Entity::oldPosition = oldPosition;
}









