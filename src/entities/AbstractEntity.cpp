//
// Created by Andrea on 21/12/2020.
//

#include "AbstractEntity.h"

std::map<unsigned int, AbstractEntity*> AbstractEntity::aliveEntities;
std::vector<AbstractEntity*> AbstractEntity::expiredEntities;

AbstractEntity::AbstractEntity(const COORD &position, const COORD &size, unsigned const int id)
    : position(position), size(size), id(id) {
    updateHitbox();
    oldPosition = position;
    expired = false;
    aliveEntities.insert(std::pair<const unsigned int, AbstractEntity*> (id, this));
}

AbstractEntity::~AbstractEntity() {
    aliveEntities.erase(this->getId());
}


const COORD &AbstractEntity::getPosition() const {
    return position;
}

const COORD &AbstractEntity::getSize() const {
    return size;
}

void AbstractEntity::updateHitbox() {
    hitbox.Top = position.Y;
    hitbox.Bottom = position.Y + size.Y - 1;
    hitbox.Left = position.X;
    hitbox.Right = position.X + size.X - 1;
}

bool AbstractEntity::intersect(AbstractEntity &other) const {
    SMALL_RECT a = this->getHitbox(), b = other.getHitbox();
    return (a.Left <= b.Right && a.Right >= b.Left && a.Top <= b.Bottom && a.Bottom >= b.Top);
}

const SMALL_RECT &AbstractEntity::getHitbox() const {
    return hitbox;
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

bool AbstractEntity::checkExpired() {
    if (expired){       //entity is already expired, no need to check
        return true;
    } else if (gameState.getCurrent() != states::running) {
        return true;
    } else if(! (hitbox.Bottom >= gameArea.Top && hitbox.Top <= gameArea.Bottom
          && hitbox.Left <= gameArea.Right && hitbox.Right >= gameArea.Left)) {
        return true;
    } else {
        return false;
    }
}

/*void AbstractEntity::update() {

}*/

void AbstractEntity::updateAliveEntities(duration dt) {
    for (std::map<int, AbstractEntity*>::value_type e : aliveEntities) {
        e.second->update(dt);
    }
}

std::vector<AbstractEntity*> AbstractEntity::getExpiredEntities() {
    std::vector<AbstractEntity*> toReturn;
    for (std::map<unsigned int, AbstractEntity*>::value_type e : aliveEntities) {
        //e.second->expired = e.second->checkExpired();
        if(e.second->checkExpired()) {
            toReturn.push_back(e.second);
        }
    }
    return toReturn;
}


void AbstractEntity::handleCollisionsWith(AbstractEntity& other) {
    for (std::map<int, AbstractEntity*>::value_type e : aliveEntities) {
        if(e.second != &other && e.second->intersect(other)) {
            e.second->collisionWith(other);
            other.collisionWith(*e.second);
        }
    }
}

void AbstractEntity::deleteEntities(std::vector<AbstractEntity *> toDelete) {
    for(AbstractEntity* e : toDelete) {
        aliveEntities.erase(e->getId());
        delete e;
    }
}


void AbstractEntity::deleteExpiredEntities() {
    deleteEntities(expiredEntities);
    expiredEntities.clear();
}

void AbstractEntity::updateExpiredEntities() {
    expiredEntities = getExpiredEntities();
}

void AbstractEntity::expire() {
    aliveEntities.erase(this->getId());
    expiredEntities.push_back(this);
}


