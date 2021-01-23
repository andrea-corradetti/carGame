//
// Created by Andrea on 21/12/2020.
//

#include "TestEntity.h"



TestEntity::TestEntity(const COORD &position, unsigned int id)
: NpcEntity(position, {1, 1}, id) {
    pArt = &art;
    setScore(10);
    coolDown = std::chrono::duration<int, std::milli>(500);
}

void TestEntity::collision(Entity &e) {
    e.setScore(e.getScore() + this->score);
    expired = true;
}



void TestEntity::act() {
    moveDown();
}

