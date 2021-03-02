//
// Created by Andrea on 20/01/2021.
//

#include "AbstractSpawner.h"
#include "CarSpawner.h"
#include "FuelSpawner.h"
#include "NailSpawner.h"

int AbstractSpawner::nextId = 2;    //Player id is always 1

std::map<entity_type, std::function<AbstractSpawner*(unsigned int)>> AbstractSpawner::spawnerTypeDict =  {
        //{player, [](unsigned int seed) -> PlayerEntity* {return new PlayerEntity(seed);}},
        //{test, [](unsigned int seed) -> TestEntity* {return new TestEntity(position, nextId);}},
        {car, [](unsigned int seed) -> CarSpawner* {return new CarSpawner(seed);}},
        {nail, [](unsigned int seed) -> NailSpawner* {return new NailSpawner(seed);}},
        {fuel, [](unsigned int seed) -> FuelSpawner* {return new FuelSpawner(seed);}},
};

AbstractSpawner::AbstractSpawner(entity_type type, unsigned int seed) : type(type), seed(seed) {
    randGen = std::mt19937(seed);
}

void AbstractSpawner::setSeed(unsigned int seed) {
    AbstractSpawner::seed = seed;
}

void AbstractSpawner::update(duration dt) {
    timeElapsed += dt;

    while (timeElapsed >= coolDown) {
        int n = randGen() % 100 ;
        if ( n <= computeSpawnRate() * 100 ) {
            COORD pos = computePosition();
            spawnAt(pos);
        }
        timeElapsed -= coolDown;
    }
}

AbstractSpawner *AbstractSpawner::factoryMethod(entity_type type, unsigned int seed) {
    AbstractSpawner* s = spawnerTypeDict[type](seed);
    return s;
}

void AbstractSpawner::reset() {
    randGen.seed(this->seed);
}

COORD AbstractSpawner::computePosition() {
    auto rand = randGen() % (gameArea.Right - gameArea.Left) ;
    return {static_cast<short>(gameArea.Left + rand), gameArea.Top}; //todo implement correct position
}
