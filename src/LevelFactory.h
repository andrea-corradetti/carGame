//
// Created by Andrea on 01/02/2021.
//

#ifndef UNTITLEDCARGAME_LEVELFACTORY_H
#define UNTITLEDCARGAME_LEVELFACTORY_H


#include <random>
#include "Level.h"

class LevelFactory {
public:
    LevelFactory();
    Level* previousLevel();
    Level* nextLevel();

private:
    Level* createLevel(unsigned int seed);
    unsigned int currentLevelNo;
    std::mt19937 randGen;
    std::vector<Level*> generatedLevels;
};


#endif //UNTITLEDCARGAME_LEVELFACTORY_H
