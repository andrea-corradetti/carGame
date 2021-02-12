//
// Created by Andrea on 28/12/2020.
//

#ifndef UNTITLEDCARGAME_ENTITYMANAGER_H
#define UNTITLEDCARGAME_ENTITYMANAGER_H

#include <map>
#include <list>
#include <functional>
#include "entities/AbstractEntity.h"
#include "entities/NpcEntity.h"
#include "entities/TestEntity.h"
#include "entities/PlayerEntity.h"


class EntityManager {
private:
    std::map<unsigned int, AbstractEntity*> aliveMap;
    unsigned int nextId = 1;
    static std::map<entity_type, std::function<AbstractEntity*(COORD, int)>> entityDict;

public:
    EntityManager();
    AbstractEntity *spawnEntity(entity_type type, COORD position);


    void deleteEntities(std::vector<AbstractEntity *> toDelete);
};


#endif //UNTITLEDCARGAME_ENTITYMANAGER_H
