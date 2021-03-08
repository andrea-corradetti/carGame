#include <windows.h>

#include "entities/AbstractEntity.h"
#include "Screen.h"
#include "Controls.h"
#include "globals.h"
#include "Level.h"
#include "LevelFactory.h"
#include "StatsBlock.h"
#include "entities/PlayerEntity.h"
#include "Clock.h"


int main() {
    /*Setup*/
    bool quit = false;
    Screen screen(GetStdHandle(STD_INPUT_HANDLE), GetStdHandle(STD_OUTPUT_HANDLE));
    Controls controls(GetStdHandle(STD_INPUT_HANDLE));
    LevelFactory levelFactory;
    StatsBlock currentStats;

    levelFactory.nextLevel();
    auto *player = PlayerEntity::spawn();

    Clock clock;
    clock.setStartToNow();

    /*Main Game Loop*/
    while(!quit) {
        clock.setEndtoNow();
        clock.updateClockValues();

        /*Game Logic*/
        while (clock.enoughTimeIsElapsed()) {
            switch (gameState.getCurrent()) {
                case states::running:
                    AbstractEntity::deleteExpiredEntities();
                    levelFactory.currentLevel->runSpawners(clock.getDt());
                    AbstractEntity::updateAliveEntities(clock.getDt());
                    controls.playerInput();
                    AbstractEntity::handleCollisionsWith(*player);
                    AbstractEntity::updateExpiredEntities();
                    currentStats.setScore(player->getScore())
                        ->setLevel(levelFactory.getCurrentLevelNo())
                        ->setHp(player->getHp())
                        ->setFuel(player->getFuel());
                    levelFactory.updateLevel(currentStats.getScore());
                    break;

                case states::intro:
                    controls.introInput();
                    break;

                case states::dead:
                    controls.deadInput();
                    break;

                case states::quit:
                    quit = true;
                    break;

                case states::reset:
                    AbstractEntity::updateExpiredEntities();
                    AbstractEntity::deleteExpiredEntities();
                    levelFactory.resetLevels();
                    levelFactory.nextLevel();
                    currentStats.reset();
                    player = PlayerEntity::spawn();
                    gameState.changeStateTo(states::running);
                    break;

                default:
                    //handling unused states. For future implementations
                    break;
            }
            clock.accountForElapsedTime();
        }


        /*Draw the screen*/
        if (gameState.isChanged()) {
            screen.clear();
            gameState.setChanged(false);
        }
        switch (gameState.getCurrent()) {
            case states::running:
                screen.drawGame();
                screen.drawStatSection(currentStats);
                break;

            case states::intro:
                screen.drawIntro();
                break;

            case states::dead:
                screen.drawDead(currentStats.getScore());
                break;

            default:
                //handling unused states. For future implementations
                break;
        }
        screen.refresh();
    }

}
