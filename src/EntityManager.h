//
// Created by Andrea on 28/12/2020.
//

#ifndef UNTITLEDCARGAME_ENTITYMANAGER_H
#define UNTITLEDCARGAME_ENTITYMANAGER_H

#include <map>
#include <list>
#include "entities/Entity.h"
#include "entities/NpcEntity.h"
#include "entities/TestEntity.h"
#include "entities/PlayerEntity.h"

enum entity_type {
    player,
    test,
    points,
    car
};


class EntityManager {
private:
    std::map<unsigned int, Entity*> eMap;
    unsigned int nextId = 1;

public:
    EntityManager();

    Entity *spawnEntity(entity_type type, COORD position);
    void handleCollisions(Entity& p);
    void update();
    const std::map<unsigned int, Entity*> &getEMap() const;
    std::vector<Entity *> getExpiredEntities();

    void deleteEntities(std::vector<Entity *> toDelete);
};


#endif //UNTITLEDCARGAME_ENTITYMANAGER_H
