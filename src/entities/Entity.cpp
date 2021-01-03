//
// Created by Andrea on 21/12/2020.
//

#include "Entity.h"


Entity::Entity(const COORD &position, const COORD &size, unsigned const int id, int score)
    : size(size), position(position), score(score), oldPosition(position), id(id) {
    updateSrHitbox();
    expired = false;
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
    if (getSrHitbox().Right < gameArea.Right) {
        position.X++;
        updateSrHitbox();
    }
}

void Entity::moveLeft() {
    if (getSrHitbox().Left > gameArea.Left) {
        position.X--;
        updateSrHitbox();
    }
}

void Entity::moveUp() {
    if (getSrHitbox().Top > gameArea.Top) {
        position.Y--;
        updateSrHitbox();
    }
}

void Entity::moveDown() {
    if (getSrHitbox().Bottom < gameArea.Bottom) {
        position.Y++;
        updateSrHitbox();
    }
}

void Entity::updateSrHitbox() {
    srHitbox.Top = position.Y;
    srHitbox.Bottom = position.Y + size.Y - 1;
    srHitbox.Left = position.X;
    srHitbox.Right = position.X + size.X - 1;
}

bool Entity::intersect(Entity &e) {
    SMALL_RECT a = this->getSrHitbox(), b = e.getSrHitbox();
    return (a.Left <= b.Right && a.Right >= b.Left && a.Top <= b.Bottom && a.Bottom >= b.Top);
}

const SMALL_RECT &Entity::getSrHitbox() const {
    return srHitbox;
}

const COORD &Entity::getOldPosition() const {
    return oldPosition;
}

void Entity::setOldPosition(const COORD &oldPosition) {
    this->oldPosition = oldPosition;
}

unsigned int Entity::getId() const {
    return id;
}

bool Entity::isExpired() const {
    return expired;
}

int Entity::getScore() const {
    return score;
}

void Entity::setScore(int score) {
    Entity::score = score;
}

void Entity::checkExpired() {
    if(! (srHitbox.Bottom >= gameArea.Top && srHitbox.Top <= gameArea.Bottom
    && srHitbox.Left <= gameArea.Right && srHitbox.Right >= gameArea.Left)) {
        expired = true;
    }
}













