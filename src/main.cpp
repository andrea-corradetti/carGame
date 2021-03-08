#include <windows.h>
#include <chrono>

#include "entities/AbstractEntity.h"
#include "Screen.h"
#include "Controls.h"
#include "globals.h"
#include "Level.h"
#include "LevelFactory.h"
#include "StatsBlock.h"
#include "entities/PlayerEntity.h"

//todo refactor global variables
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


GameState gameState;


int main() {
    /*Setup*/
    bool quit = false;
    Screen s(GetStdHandle(STD_INPUT_HANDLE), GetStdHandle(STD_OUTPUT_HANDLE));
    Controls c(GetStdHandle(STD_INPUT_HANDLE));
    LevelFactory lf;
    StatsBlock currentStats;

    lf.nextLevel();
    auto *player = PlayerEntity::spawn();

    duration totalTime(0);                  //todo group functionalities in an object
    const auto dt = duration(1. / 60);
    auto start = std::chrono::steady_clock::now();
    duration accumulator(0);

    while(!quit) {
        auto end = std::chrono::steady_clock::now();
        duration frameTime = end - start;
        accumulator += frameTime;
        start = end;
        /*Game Logic*/
        while (accumulator >= dt) {
            switch (gameState.getCurrent()) {
                case states::running:
                    AbstractEntity::deleteExpiredEntities();    //FIXME expired entities not fetched at the right time. Cars are not erased
                    lf.currentLevel->runSpawners(dt);
                    AbstractEntity::updateAliveEntities(dt);
                    c.playerInput();
                    AbstractEntity::handleCollisionsWith(*player);
                    AbstractEntity::updateExpiredEntities();    //todo add expire() method to automate removal from aliveEntity
                    currentStats.setScore(player->getScore())
                        ->setLevel(lf.getCurrentLevelNo())
                        ->setHp(player->getHp())
                        ->setFuel(player->getFuel());
                    lf.updateLevel(currentStats.getScore());
                    break;
                case states::menu:
                    //todo add menu input
                case states::intro:
                    c.introInput();
                    break;
                case states::dead:
                    c.deadInput();
                    break;

                case states::quit:
                    quit = true;
                    break;

                case states::reset:
                    AbstractEntity::updateExpiredEntities();
                    AbstractEntity::deleteExpiredEntities();
                    lf.reset();
                    lf.nextLevel();
                    currentStats.reset();
                    player = PlayerEntity::spawn();
                    gameState.changeStateTo(states::running);
                    break;
            }

            accumulator -= dt;
            totalTime += dt;
        }


        /*Draw the screen*/
        if (gameState.isChanged()) {
            s.clear();
            gameState.setChanged(false);
        }
        switch (gameState.getCurrent()) {
            case states::running:
                s.drawGame();
                s.drawStatSection(currentStats);
                break;
            case states::intro:
                s.drawIntro();
                break;
            case states::dead:
                s.drawDead(currentStats.getScore());
                break;
        }
        s.refresh();
    }

}
