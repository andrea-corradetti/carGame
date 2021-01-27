//
// Created by Andrea on 21/12/2020.
//

#include "AbstractEntity.h"

std::map<unsigned int, AbstractEntity*> AbstractEntity::aliveMap;

AbstractEntity::AbstractEntity(const COORD &position, const COORD &size, unsigned const int id)
    : position(position), size(size), id(id) {
    updateSrHitbox();
    oldPosition = position;
    expired = false;
    //coolDown = std::chrono::duration<int, std::milli>(500);
    //start = std::chrono::steady_clock::now();
    AbstractEntity::aliveMap.insert(std::pair<const unsigned int, AbstractEntity*> (id, this));
}

AbstractEntity::~AbstractEntity() {
    AbstractEntity::aliveMap.erase(this->getId());
}


const COORD &AbstractEntity::getPosition() const {
    return position;
}

const COORD &AbstractEntity::getSize() const {
    return size;
}

std::wstring *AbstractEntity::getPArt() const {
    return pArt;
}

void AbstractEntity::moveRight() {
    if (getSrHitbox().Right < gameArea.Right) {
        position.X++;
        updateSrHitbox();
    }
}

void AbstractEntity::moveLeft() {
    if (getSrHitbox().Left > gameArea.Left) {
        position.X--;
        updateSrHitbox();
    }
}

void AbstractEntity::moveUp() {
    if (getSrHitbox().Top > gameArea.Top) {
        position.Y--;
        updateSrHitbox();
    }
}

void AbstractEntity::moveDown() {
    if (getSrHitbox().Bottom < gameArea.Bottom) {
        position.Y++;
        updateSrHitbox();
    }
}

void AbstractEntity::updateSrHitbox() {
    srHitbox.Top = position.Y;
    srHitbox.Bottom = position.Y + size.Y - 1;
    srHitbox.Left = position.X;
    srHitbox.Right = position.X + size.X - 1;
}

bool AbstractEntity::intersect(AbstractEntity &other) const {
    SMALL_RECT a = this->getSrHitbox(), b = other.getSrHitbox();
    return (a.Left <= b.Right && a.Right >= b.Left && a.Top <= b.Bottom && a.Bottom >= b.Top);
}

const SMALL_RECT &AbstractEntity::getSrHitbox() const {
    return srHitbox;
}

const COORD &AbstractEntity::getOldPosition() const {
    return oldPosition;
}

void AbstractEntity::setOldPosition(const COORD &oldPosition) {
    this->oldPosition = oldPosition;
}

unsigned int AbstractEntity::getId() const {
    return id;
}

bool AbstractEntity::isExpired() const {
    return expired;
}

void AbstractEntity::checkExpired() {

    if(! (srHitbox.Bottom >= gameArea.Top && srHitbox.Top <= gameArea.Bottom
    && srHitbox.Left <= gameArea.Right && srHitbox.Right >= gameArea.Left)) {
        expired = true;
    }
}

void AbstractEntity::update() {

}

void AbstractEntity::updateAll() {
    for (std::map<int, AbstractEntity*>::value_type e : aliveMap) {
        e.second->update();
    }
}

std::vector<AbstractEntity*> AbstractEntity::getExpiredEntities() {
    std::vector<AbstractEntity*> toReturn;
    for (std::map<unsigned int, AbstractEntity*>::value_type e : aliveMap) {
        if(e.second->isExpired()) {
            toReturn.push_back(e.second);
        }
    }
    return toReturn;
}


void AbstractEntity::handleCollisionsWith(AbstractEntity& p) {
    for (std::map<int, AbstractEntity*>::value_type e : aliveMap) {
        if(e.second != &p && e.second->intersect(p)) {
            e.second->collision(p);
            p.collision(*e.second);
        }
    }
}

void AbstractEntity::deleteEntities(std::vector<AbstractEntity *> toDelete) {
    for(AbstractEntity* e : toDelete) {
        aliveMap.erase(e->getId());
        delete e;
    }
}





