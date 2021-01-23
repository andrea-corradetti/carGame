//
// Created by Andrea on 20/01/2021.
//

#ifndef UNTITLEDCARGAME_SPAWNER_H
#define UNTITLEDCARGAME_SPAWNER_H


#include "../EntityManager.h"
#include <random>

class Spawner {
public:
    Spawner(EntityManager& em, entity_type type);
    void setSeed(unsigned int seed);
    void tick();

protected:
    virtual Entity* spawn(COORD position) = 0;
    virtual COORD computePosition();

    const entity_type type;
    unsigned int seed;
    float rate;
    static int nextId;
public:
    float getRate() const;

    void setRate(float rate);

private:
    EntityManager& em;
    std::mt19937 randGen;

};


#endif //UNTITLEDCARGAME_SPAWNER_H
