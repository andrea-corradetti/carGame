//
// Created by Andrea on 01/02/2021.
//

#include "LevelFactory.h"

LevelFactory::LevelFactory() {
    std::random_device rd;
    randGen = std::mt19937 (rd());
    generatedLevels = std::vector<Level*>();
    currentLevelNo = 0;
}

Level *LevelFactory::nextLevel() {
    currentLevelNo++;
    Level* l;
    if (currentLevelNo <= generatedLevels.size()) {
       l = generatedLevels.at(currentLevelNo);

    } else {
       l = createLevel(randGen());
    }
    return l;
}

Level *LevelFactory::previousLevel() {
    if (currentLevelNo > 1) {
        currentLevelNo--;
    }
    Level* l = generatedLevels.at(currentLevelNo);
    return l;
}

Level *LevelFactory::createLevel(const unsigned int seed) {
    auto* l = new Level(seed, currentLevelNo);
    //for (AbstractSpawner* as : l->)

    generatedLevels.push_back(l);
    return l;
}
