//
// Created by Andrea on 21/12/2020.
//

#include "TestEntity.h"
#include "NpcEntity.h"


TestEntity::TestEntity(const COORD &position, unsigned int id)
: NpcEntity(position, id, {1, 1}, duration(1)) {
    //pArt = &art;
    value = 10;
    coolDown = std::chrono::duration<int, std::milli>(500);
}

void TestEntity::collisionWith(AbstractEntity &other) {
    //other.setScore(other.getScore() + this->value);
    expired = true;
}



void TestEntity::act() {
    moveDown();
}

