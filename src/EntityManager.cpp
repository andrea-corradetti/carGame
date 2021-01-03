//
// Created by Andrea on 28/12/2020.
//


#include "EntityManager.h"


Entity* EntityManager::spawnEntity(const entity_type type, COORD position, int score) {
    Entity* e;
    switch (type) {
        case player:
            e = new PlayerEntity(position, nextId, score);
            break;
        case test:
            e = new TestEntity(position, {1, 1} , nextId, 0);
            break;
        default:
            e = new TestEntity(position, {1, 1} , nextId, 0);
            break;
    }
    nextId++;
    this->eMap.insert(std::pair<const unsigned int, Entity*> (e->getId(), e));
    return e;
}

const std::map<unsigned int, Entity *> &EntityManager::getEMap() const {
    return eMap;
}

EntityManager::EntityManager() {
    nextId = 1;
}

void EntityManager::deleteExpired() {
    std::list<Entity*> toDelete;
    for (std::map<int, Entity*>::value_type e : eMap) {
        if(e.second->isExpired()) {
            toDelete.insert(toDelete.end(), e.second);
        }
    }
    for(Entity* e : toDelete) {
        eMap.erase(e->getId());
        delete e;
    }
}

void EntityManager::handleCollisions(Entity& p) {
    for (std::map<int, Entity*>::value_type e : eMap) {
        if(e.second != &p && e.second->intersect(p)) {
            e.second->collision(p);
        }
    }
}

void EntityManager::update() {
    for (std::map<int, Entity*>::value_type e : eMap) {
        e.second->update();
    }
}
