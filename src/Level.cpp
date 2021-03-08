//
// Created by Andrea on 01/02/2021.
//

#include "Level.h"


Level::Level(const unsigned int seed, const unsigned int levelNo) : seed(seed), levelNo(levelNo){
    activeSpawners = std::vector<AbstractSpawner*>();
    randGen = std::mt19937(seed);
    activeSpawners.push_back(AbstractSpawner::factoryMethod(entity_type::points, randGen()));
    activeSpawners.push_back(AbstractSpawner::factoryMethod(entity_type::nail, randGen()));
    activeSpawners.push_back(AbstractSpawner::factoryMethod(entity_type::fuel, randGen()));
    activeSpawners.push_back(AbstractSpawner::factoryMethod(entity_type::car, randGen()));
    updateSpawnRates();
}

void Level::runSpawners(duration dt) {
    for (AbstractSpawner* s : activeSpawners) {
        s->update(dt);
    }
}

void Level::updateSpawnRates() {
    for(AbstractSpawner* s : activeSpawners) {
        s->updateRateMultiplier(levelNo);
    }
}

void Level::resetSpawners() {
    for(AbstractSpawner* s : activeSpawners) {
        s->reset();
    }
}



