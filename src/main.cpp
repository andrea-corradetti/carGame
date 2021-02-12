#include <windows.h>
#include <chrono>

#include "entities/AbstractEntity.h"
#include "Screen.h"
#include "Controls.h"
#include "EntityManager.h"
#include "globals.h"
#include "Level.h"
#include "LevelFactory.h"


SMALL_RECT gameArea = {
        3,
        3,
        30,
        20,
};

SMALL_RECT statsArea = {
        33,
        3,
        53,
        20
};


unsigned int levelNo = 1;
gameState currGameState = gameState::running;


int main() {
    bool quit = false;
    Screen s(GetStdHandle(STD_INPUT_HANDLE), GetStdHandle(STD_OUTPUT_HANDLE));
    Controls c(GetStdHandle(STD_INPUT_HANDLE));
    EntityManager em;
    LevelFactory lf;
    Level* currentLevel = lf.nextLevel();

    AbstractEntity *p = em.spawnEntity(player, {3, 10});
/*    em.spawnEntity(test, {7, gameArea.Top});
    em.spawnEntity(test, {9, gameArea.Top});
    em.spawnEntity(car, {8, gameArea.Top});*/

    duration totalTime(0);
    const auto dt = duration(1. / 60);
    auto start = std::chrono::steady_clock::now();
    duration accumulator(0);

    while(!quit) {
        auto end = std::chrono::steady_clock::now();
        duration frameTime = end - start;
        accumulator += frameTime;
        start = end;

        while (accumulator >= dt) {
            currentLevel->runSpawners(dt);
            AbstractEntity::expiredEntities = AbstractEntity::getExpiredEntities();
            AbstractEntity::deleteEntities(AbstractEntity::expiredEntities);
            c.playerInput();
            AbstractEntity::updateAliveEntities(dt);        //TODO use dt
            AbstractEntity::handleCollisionsWith(*p);
            accumulator -= dt;
            totalTime += dt;
        }
        s.draw();
    }

}
