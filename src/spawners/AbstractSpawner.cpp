//
// Created by Andrea on 20/01/2021.
//

#include "AbstractSpawner.h"
#include "CarSpawner.h"

int AbstractSpawner::nextId = 1;

std::map<entity_type, std::function<AbstractSpawner*(unsigned int)>> AbstractSpawner::spawnerTypeDict =  {
        //{player, [](unsigned int seed) -> PlayerEntity* {return new PlayerEntity(seed);}},
        //{test, [](unsigned int seed) -> TestEntity* {return new TestEntity(position, nextId);}},
        {car, [](unsigned int seed) -> CarSpawner* {return new CarSpawner(seed);}},
};

AbstractSpawner::AbstractSpawner(entity_type type, unsigned int seed) : type(type), seed(seed) {
    randGen = std::mt19937(seed);
}

void AbstractSpawner::setSeed(unsigned int seed) {
    AbstractSpawner::seed = seed;
}

void AbstractSpawner::tick() {
    int n = randGen();
    if ( n%100 <= baseRate * 100 ) {
        COORD pos = computePosition();
        spawn(pos);
    }
}

float AbstractSpawner::getRate() const {
    return baseRate;
}

void AbstractSpawner::setRate(float rate) {
    AbstractSpawner::baseRate = rate;
}

AbstractSpawner *AbstractSpawner::factoryMethod(entity_type type, unsigned int seed) {
    AbstractSpawner* s = spawnerTypeDict[type].operator()(seed);
    //this->aliveMap.insert(std::pair<const unsigned int, AbstractEntity*> (e->getId(), e));
    return s;
}
