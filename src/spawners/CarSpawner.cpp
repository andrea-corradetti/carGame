//
// Created by Andrea on 22/01/2021.
//

#include "CarSpawner.h"

CarEntity* CarSpawner::spawn(COORD position) {
    return new CarEntity(position, nextId++);
}

COORD CarSpawner::computePosition() {
    return {5 ,5}; //todo implement correct position
}

CarSpawner::CarSpawner(EntityManager &em, entity_type type) : Spawner(em, type) {
    rate = .2;
}
