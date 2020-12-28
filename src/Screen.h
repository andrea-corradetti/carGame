//
// Created by Andrea on 19/12/2020.
//

#ifndef UNTITLEDCARGAME_SCREEN_H
#define UNTITLEDCARGAME_SCREEN_H

#include <cstdio>
#include <iostream>

#include "entities/Entity.h"

#define ESC "\x1b"
#define CSI "\x1b["

#define BUFSIZE 1000

class Screen {
private:
    HANDLE hStdout, hStdin;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    wchar_t screenBufA[BUFSIZE], screenBufB[BUFSIZE];
    wchar_t *currBuf, *nextBuf;
public:
    const CONSOLE_SCREEN_BUFFER_INFO &getCsbiInfo() const;

private:
    DWORD dwInMode, dwInMode_old, dwOutMode, dwOutMode_old;
    COORD coBufferSize;


public:
    Screen(HANDLE hStdin, HANDLE hStdout);
    void clear();
    void drawEntity(Entity &entity);
    void update();

};


#endif //UNTITLEDCARGAME_SCREEN_H
