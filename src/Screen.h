//
// Created by Andrea on 19/12/2020.
//

#ifndef UNTITLEDCARGAME_SCREEN_H
#define UNTITLEDCARGAME_SCREEN_H

#ifndef WINDOWS_H
#define WINDOWS_H

#include <windows.h>

#endif //WINDOWS_H

#include <cstdio>
#include <iostream>

#include "entities/Entity.h"

#define ESC "\x1b"
#define CSI "\x1b["

class Screen {
private:
    HANDLE hStdout, hStdin;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    WCHAR screenBuffer[1000];
public:
    const CONSOLE_SCREEN_BUFFER_INFO &getCsbiInfo() const;

private:
    DWORD dwInMode, dwInMode_old, dwOutMode, dwOutMode_old;
    wchar_t gameBuffer[100][100];
    COORD coBufferSize;


public:
    Screen(HANDLE hStdin, HANDLE hStdout);
    void clear();
    void drawEntity(Entity &entity);

};


#endif //UNTITLEDCARGAME_SCREEN_H
