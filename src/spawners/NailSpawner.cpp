//
// Created by Andrea on 27/01/2021.
//

#include "NailSpawner.h"
#include "../entities/NailEntity.h"

NailEntity *NailSpawner::spawn(COORD position) {
    return new NailEntity(position, nextId++);
}

COORD NailSpawner::computePosition() {
    return COORD();
}
