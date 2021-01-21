//
// Created by Andrea on 20/01/2021.
//

#ifndef UNTITLEDCARGAME_SPAWNER_H
#define UNTITLEDCARGAME_SPAWNER_H


#include "EntityManager.h"
#include <random>

class Spawner {
public:
    Spawner(EntityManager& em, entity_type type);
    void update();
    void setSeed(unsigned int seed);

protected:
    Entity* spawn(COORD position);
    virtual COORD computePosition();

    const entity_type type;
    unsigned int seed;
    float rate;

private:
    EntityManager& em;
    std::mt19937 randGen;
};


#endif //UNTITLEDCARGAME_SPAWNER_H
