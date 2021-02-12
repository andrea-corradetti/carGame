//
// Created by Andrea on 01/02/2021.
//

#ifndef UNTITLEDCARGAME_LEVEL_H
#define UNTITLEDCARGAME_LEVEL_H


#include <vector>
#include "spawners/AbstractSpawner.h"

class Level {
public:
    Level(unsigned int seed, unsigned int levelNo);
    const int levelNo;
    void runSpawners(duration dt);

private:
    void updateSpawnRates();

    const unsigned int seed;
    std::vector<AbstractSpawner*> activeSpawners;
    std::mt19937 randGen;
};


#endif //UNTITLEDCARGAME_LEVEL_H
