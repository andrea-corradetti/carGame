//
// Created by Andrea on 20/01/2021.
//

#include "LevelManager.h"

Spawner* LevelManager::createSpawner(EntityManager &em, entity_type type) {
    return new Spawner(em, type);
}

LevelManager::LevelManager() {

}
