#include <windows.h>
#include <chrono>
#include <unistd.h>
#include <vector>

#include "entities/AbstractEntity.h"
#include "Screen.h"
#include "Controls.h"
#include "EntityManager.h"
#include "globals.h"


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



int main() {
    bool quit = false;
    Screen s(GetStdHandle(STD_INPUT_HANDLE), GetStdHandle(STD_OUTPUT_HANDLE));
    Controls c(GetStdHandle(STD_INPUT_HANDLE));
    EntityManager em;

    std::vector<AbstractEntity*> expiredEntities;
    AbstractEntity *p = em.spawnEntity(player, {3, 10});
    em.spawnEntity(test, {7, gameArea.Top});
    em.spawnEntity(test, {9, gameArea.Top});
    em.spawnEntity(car, {8, gameArea.Top});

    std::chrono::duration<double> t(0);
    const auto dt = std::chrono::duration<double>(1./60);
    auto start = std::chrono::steady_clock::now();
    std::chrono::duration<double> accumulator(0);

    while(!quit) {
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> frameTime = end - start;
        accumulator += frameTime;

        while (accumulator >= dt) {
            c.handleInput(*p);
            AbstractEntity::updateAll();        //TODO use dt
            AbstractEntity::handleCollisionsWith(*p);
            expiredEntities = AbstractEntity::getExpiredEntities();
            s.eraseEntities(expiredEntities);
            AbstractEntity::deleteEntities(expiredEntities);
            accumulator -= dt;
            t += dt;
        }
        s.drawAreaBorder(gameArea);
        s.drawAreaBorder(statsArea);
        s.drawAll(AbstractEntity::aliveMap);
        s.refresh();
    }

}
