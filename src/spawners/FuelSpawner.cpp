//
// Created by Andrea on 27/01/2021.
//

#include "FuelSpawner.h"
#include "../entities/FuelEntity.h"

FuelEntity *FuelSpawner::spawn(COORD position) {
    return new FuelEntity(position, nextId++);
}

COORD FuelSpawner::computePosition() {
    return COORD();
}
