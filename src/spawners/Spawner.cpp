//
// Created by Andrea on 20/01/2021.
//

#include "Spawner.h"
int Spawner::nextId = 1;

Spawner::Spawner(EntityManager& em, entity_type type) : em(em), type(type) {
    //std::random_device rd;
    //unsigned int seed = rd();
    randGen = std::mt19937(seed);
}

Entity* Spawner::spawn(COORD position) {
    return em.spawnEntity(type, position);
}

void Spawner::setSeed(unsigned int seed) {
    Spawner::seed = seed;
}

void Spawner::tick() {
    int n = randGen();
    if ( n%100 <= rate * 100 ) {
        COORD pos = computePosition();
        spawn(pos);
    }
}

float Spawner::getRate() const {
    return rate;
}

void Spawner::setRate(float rate) {
    Spawner::rate = rate;
}
