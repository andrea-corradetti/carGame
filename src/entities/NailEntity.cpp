//
// Created by Andrea on 27/01/2021.
//

#include "NailEntity.h"


#define NAIL_SIZE {1, 1}

void NailEntity::collision(AbstractEntity &other) {
    expired = true;
}

NailEntity::NailEntity(const COORD &position, unsigned int id) : NpcEntity(position, NAIL_SIZE, id) {}
