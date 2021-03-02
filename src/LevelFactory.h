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
    void reset();
    void updateLevel(int score);
    Level* currentLevel;

    unsigned int getCurrentLevelNo() const;
private:
    Level* createLevel(unsigned int seed);
    int currentLevelNo;
    std::mt19937 randGen;   //pseudo random generator
    std::random_device randDev;  //generates random numbers based on hardware state
    std::vector<Level*> generatedLevels;

};


#endif //UNTITLEDCARGAME_LEVELFACTORY_H
