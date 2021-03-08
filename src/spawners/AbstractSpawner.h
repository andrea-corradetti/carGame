//
// Created by Andrea on 20/01/2021.
//

#ifndef UNTITLEDCARGAME_ABSTRACTSPAWNER_H
#define UNTITLEDCARGAME_ABSTRACTSPAWNER_H


#include <random>
#include <functional>
#include "../entities/AbstractEntity.h"
#include "../entities/CarEntity.h"

class AbstractSpawner {
public:
    static AbstractSpawner* factoryMethod(entity_type type, unsigned int seed);
    void update(duration dt);
    virtual void updateRateMultiplier(unsigned int currentLevelNo) = 0;
    void setSeed(unsigned int seed);

    void reset();

protected:
    AbstractSpawner(entity_type type, unsigned int seed, float baseRate);
    virtual AbstractEntity* spawnAt(COORD position) = 0;
    virtual float computeSpawnRate();
    virtual COORD computePosition();

    std::mt19937 randGen;
    const entity_type type;
    unsigned int seed;
    static int nextId;  //id of next Entity to be spawned

    duration coolDown;
    float rateMultiplier;
    float spawnRate;

    const float baseRate;



private:
    static std::map<entity_type, std::function<AbstractSpawner *(unsigned int)>> spawnerTypeDict;
    duration timeElapsed;

};


#endif //UNTITLEDCARGAME_ABSTRACTSPAWNER_H
