//
// Created by Andrea on 19/12/2020.
//

#ifndef UNTITLEDCARGAME_SCREEN_H
#define UNTITLEDCARGAME_SCREEN_H

#include <cstdio>
#include <iostream>
#include <map>

#include "entities/AbstractEntity.h"

#define ESC "\x1b"
#define CSI "\x1b["


class Screen {
public:
    Screen(HANDLE hStdin, HANDLE hStdout);
    void clear();
    void drawInterface();
    void drawEntity(AbstractEntity &entity);
    void eraseEntity(AbstractEntity &entity);
    void eraseEntities(std::vector<AbstractEntity *> toErase);
    void drawAll(const std::map<unsigned int, AbstractEntity*>&);
    void refresh();
    const CONSOLE_SCREEN_BUFFER_INFO &getCsbiInfo() const;
    void drawAreaBorder(SMALL_RECT area);

private:
    HANDLE hStdout, hStdin;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    DWORD dwInMode, dwInMode_old, dwOutMode, dwOutMode_old;
    COORD coBufferSize;
    void drawHorizontalLine(int size, bool isTop);
    void drawVerticalLine(int size);
    void drawStatSection();


};


#endif //UNTITLEDCARGAME_SCREEN_H
