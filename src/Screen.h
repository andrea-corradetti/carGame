//
// Created by Andrea on 19/12/2020.
//

#ifndef UNTITLEDCARGAME_SCREEN_H
#define UNTITLEDCARGAME_SCREEN_H

#include <cstdio>
#include <iostream>
#include <map>
#include "GameState.h"
#include "entities/AbstractEntity.h"
#include "StatsBlock.h"

#define ESC "\x1b"
#define CSI "\x1b["


class Screen {
public:
    Screen(HANDLE hStdin, HANDLE hStdout);
    void clear();

    void eraseEntities(const std::vector<AbstractEntity *>& toErase);
    void drawAll(const std::map<unsigned int, AbstractEntity*>&);
    void refresh();
    void drawIntro();
    //void drawGame(gameState currGameState);
    void drawGame();
    void drawDead(int score);
    void drawStatSection(const StatsBlock &currentStats) ;

private:
    HANDLE hStdout, hStdin;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    DWORD dwInMode, dwInMode_old, dwOutMode, dwOutMode_old;
    COORD coBufferSize;
    void drawHorizontalLine(int size, bool isTop);
    void drawVerticalLine(int size);

    void drawEntity(AbstractEntity &entity);
    void eraseEntity(AbstractEntity &entity);
    void drawAreaBorder(SMALL_RECT area);


};


#endif //UNTITLEDCARGAME_SCREEN_H
