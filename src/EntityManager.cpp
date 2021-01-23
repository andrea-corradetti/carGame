//
// Created by Andrea on 28/12/2020.
//


#include <vector>
#include "EntityManager.h"


std::map<entity_type, std::function<Entity*(COORD, int)>> EntityManager::entityDict =  {
        {player, [](COORD position, int nextId) -> PlayerEntity* {return new PlayerEntity(position, nextId);}},
        {test, [](COORD position, int nextId) -> TestEntity* {return new TestEntity(position, nextId);}},
       // {car, [](COORD position, int nextId) -> PlayerEntity* {return new CarEntity(position, nextId);}},
};



/*Entity * EntityManager::spawnEntity(const entity_type type, COORD position) {
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
    this->liveEntitiesMap.insert(std::pair<const unsigned int, Entity*> (e->getId(), e));
    return e;
}*/

Entity * EntityManager::spawnEntity(const entity_type type, COORD position) {
    Entity* e = entityDict[type].operator()(position, nextId);
    nextId++;
    this->liveEntitiesMap.insert(std::pair<const unsigned int, Entity*> (e->getId(), e));
    return e;
}

const std::map<unsigned int, Entity *> &EntityManager::getLiveEntities() const {
    return liveEntitiesMap;
}

EntityManager::EntityManager() {
    nextId = 1;
}



void EntityManager::handleCollisions(Entity& p) {
    for (std::map<int, Entity*>::value_type e : liveEntitiesMap) {
        if(e.second != &p && e.second->intersect(p)) {
            e.second->collision(p);
        }
    }
}

void EntityManager::update() {
    for (std::map<int, Entity*>::value_type e : liveEntitiesMap) {
        e.second->update();
    }
}

std::vector<Entity*> EntityManager::getExpiredEntities() {
    std::vector<Entity*> toReturn;
    for (std::map<int, Entity*>::value_type e : liveEntitiesMap) {
        if(e.second->isExpired()) {
            toReturn.push_back(e.second);
        }
    }
    return toReturn;
}


void EntityManager::deleteEntities(std::vector<Entity *> toDelete) {
    for(Entity* e : toDelete) {
        liveEntitiesMap.erase(e->getId());
        delete e;
    }
}