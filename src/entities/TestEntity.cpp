//
// Created by Andrea on 21/12/2020.
//

#include "TestEntity.h"

TestEntity::TestEntity(const COORD &position, const COORD &size, int score) : NpcEntity(position, size, score) {
    pArt = &art;
}

void TestEntity::collision(PlayerEntity &e) {

}

