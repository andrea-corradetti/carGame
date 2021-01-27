//
// Created by Andrea on 28/12/2020.
//


#include <vector>
#include "EntityManager.h"
#include "entities/CarEntity.h"


std::map<entity_type, std::function<AbstractEntity*(COORD, int)>> EntityManager::entityDict =  {
        {player, [](COORD position, int nextId) -> PlayerEntity* {return new PlayerEntity(position, nextId);}},
        {test, [](COORD position, int nextId) -> TestEntity* {return new TestEntity(position, nextId);}},
        {car, [](COORD position, int nextId) -> CarEntity* {return new CarEntity(position, nextId);}},
};



AbstractEntity * EntityManager::spawnEntity(const entity_type type, COORD position) {
    AbstractEntity* e = entityDict[type].operator()(position, nextId);
    nextId++;
    this->aliveMap.insert(std::pair<const unsigned int, AbstractEntity*> (e->getId(), e));
    return e;
}


EntityManager::EntityManager() {
    nextId = 1;
}

void EntityManager::deleteEntities(std::vector<AbstractEntity *> toDelete) {
    for(AbstractEntity* e : toDelete) {
        aliveMap.erase(e->getId());
        delete e;
    }
}