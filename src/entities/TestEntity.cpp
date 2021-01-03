//
// Created by Andrea on 21/12/2020.
//

#include "TestEntity.h"

TestEntity::TestEntity(const COORD &position, const COORD &size, unsigned int id, int score)
: NpcEntity(position, size, id, score) {
    pArt = &art;
}

void TestEntity::collision(Entity &e) {
    e.setScore(e.getScore() + 5);
    expired = true;
}

void TestEntity::update() {

    moveDown();
    checkExpired();
}

