//
// Created by Andrea on 20/01/2021.
//

#ifndef UNTITLEDCARGAME_LEVELMANAGER_H
#define UNTITLEDCARGAME_LEVELMANAGER_H

#include <random>
#include "EntityManager.h"
#include "Spawner.h"

class LevelManager {
public:
    LevelManager();
    Spawner* createSpawner(EntityManager& em, entity_type type);

protected:
    std::vector<int> seeds;
    std::vector<Spawner*> spawners;

private:
    std::random_device rd;
    std::mt19937 randGen;




};


#endif //UNTITLEDCARGAME_LEVELMANAGER_H
