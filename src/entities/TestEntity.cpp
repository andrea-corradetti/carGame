//
// Created by Andrea on 21/12/2020.
//

#include "TestEntity.h"



TestEntity::TestEntity(const COORD &position, unsigned int id)
: NpcEntity(position, {1, 1}, id) {
    pArt = &art;
    setScore(10);
    coolDown = std::chrono::duration<int, std::milli>(500);
    start = std::chrono::steady_clock::now();

}

void TestEntity::collision(Entity &e) {
    e.setScore(e.getScore() + this->score);
    expired = true;
}

void TestEntity::update() {
    using namespace std::chrono;
    auto end = std::chrono::steady_clock::now();
    auto timeDiff = std::chrono::duration_cast<duration<int, std::milli>>(end - start);
    if(timeDiff > coolDown){
        moveDown();
        start = end;
    }
    checkExpired();
}

