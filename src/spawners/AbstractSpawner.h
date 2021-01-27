//
// Created by Andrea on 20/01/2021.
//

#ifndef UNTITLEDCARGAME_ABSTRACTSPAWNER_H
#define UNTITLEDCARGAME_ABSTRACTSPAWNER_H


#include "../EntityManager.h"
#include <random>

class AbstractSpawner {
public:
    AbstractSpawner(entity_type type, unsigned int seed);
    static AbstractSpawner* factoryMethod(entity_type type, unsigned int seed);
    void setSeed(unsigned int seed);
    void tick();

protected:
    virtual AbstractEntity* spawn(COORD position) = 0;
    virtual COORD computePosition() = 0;

    const entity_type type;
    unsigned int seed;
    float baseRate;
    static int nextId;
public:
    float getRate() const;
    void setRate(float rate);

    std::mt19937 randGen;

    static std::map<entity_type, std::function<AbstractSpawner *(unsigned int)>> spawnerTypeDict;
};


#endif //UNTITLEDCARGAME_ABSTRACTSPAWNER_H
