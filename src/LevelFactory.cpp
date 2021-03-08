//
// Created by Andrea on 01/02/2021.
//

#include "LevelFactory.h"

LevelFactory::LevelFactory() {
    randGen = std::mt19937 (randDev());
    generatedLevels = std::vector<Level*>();
    currentLevelNo = 0;
}

Level *LevelFactory::nextLevel() {
    currentLevelNo++;
    Level* l;
    if (currentLevelNo < generatedLevels.size()) {
       l = generatedLevels.at(currentLevelNo - 1);
       l->resetSpawners();
    } else {
       l = createLevel(randGen());
    }
    currentLevel = l;
    return l;
}

Level *LevelFactory::previousLevel() {
    if (currentLevelNo > 1) {
        currentLevelNo--;
        Level* l = generatedLevels.at(currentLevelNo - 1);  //kind of bad?
        l->resetSpawners();
        currentLevel = l;
    }
    return currentLevel;
}

Level *LevelFactory::createLevel(const unsigned int seed) {
    auto* l = new Level(seed, currentLevelNo);
    //for (AbstractSpawner* as : l->)

    generatedLevels.push_back(l);
    return l;
}

void LevelFactory::resetLevels() {
    this->currentLevelNo = 0;
    randGen.seed(randDev());
    generatedLevels.clear();
}

unsigned int LevelFactory::getCurrentLevelNo() const {
    return currentLevelNo;
}

void LevelFactory::updateLevel(int score) {
    if (score >= (currentLevelNo) * 100) {
        nextLevel();
    } else if ((score < (currentLevelNo - 1) * 100)) {
        previousLevel();
    }
}
