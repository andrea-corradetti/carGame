//
// Created by Andrea on 28/12/2020.
//


#include <vector>
#include "EntityManager.h"



Entity * EntityManager::spawnEntity(const entity_type type, COORD position) {
    Entity* e;
    switch (type) {
        case player:
            e = new PlayerEntity(position, nextId);
            break;
        case test:
            e = new TestEntity(position, nextId);
            break;
        default:
            e = new TestEntity(position, nextId);
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

std::vector<Entity*> EntityManager::getExpiredEntities() {
    std::vector<Entity*> toReturn;
    for (std::map<int, Entity*>::value_type e : eMap) {
        if(e.second->isExpired()) {
            toReturn.push_back(e.second);
        }
    }
    return toReturn;
}


void EntityManager::deleteEntities(std::vector<Entity *> toDelete) {
    for(Entity* e : toDelete) {
        eMap.erase(e->getId());
        delete e;
    }
}