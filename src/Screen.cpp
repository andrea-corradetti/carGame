//
// Created by Andrea on 19/12/2020.
//


#include "Screen.h"

Screen::Screen(HANDLE hStdin, HANDLE hStdout) : hStdin(hStdin), hStdout(hStdout){
    GetConsoleScreenBufferInfo(hStdout, &csbiInfo);

    GetConsoleMode(hStdin, &dwInMode_old);
    DWORD dwRequestedInModes = ENABLE_VIRTUAL_TERMINAL_INPUT | ENABLE_EXTENDED_FLAGS;
    DWORD dwUndesiredInModes = ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT | ENABLE_INSERT_MODE;
    dwInMode = (dwInMode_old | dwRequestedInModes) & ~dwUndesiredInModes;
    if (!SetConsoleMode(hStdin, dwInMode)) {
        std::cout << "error hstdin\n" ;
    }

    GetConsoleMode(hStdout, &dwOutMode_old);
    DWORD dwRequestedOutModes = ENABLE_VIRTUAL_TERMINAL_PROCESSING | DISABLE_NEWLINE_AUTO_RETURN;
    DWORD dwUndesiredOutModes = ENABLE_WRAP_AT_EOL_OUTPUT | ENABLE_PROCESSED_OUTPUT;
    dwOutMode = dwOutMode_old | dwRequestedOutModes & ~(dwUndesiredOutModes);
    if (!SetConsoleMode(hStdout, dwOutMode)) {
        std::cout << "error hstdout\n";
    }

    currBuf = screenBufA;
    nextBuf = screenBufB;

    wprintf(L"%s?25l", CSI);    //hide cursor
    fflush(stdout);


}

void Screen::drawEntity(Entity &entity) {
    short posX = entity.getPosition().X;
    short posY = entity.getPosition().Y;
    short posX_old = entity.getOldPosition().X;
    short posY_old = entity.getOldPosition().Y;
    short sizeX = entity.getSize().X;
    short sizeY = entity.getSize().Y;

    /*if the position has changed, erase the hold drawing*/
    if (posX_old != posX || posY_old != posY) {
        wprintf(CSI L"%d;%df", posY_old, posX_old); //set cursor
        for (int y = 0; y < sizeY; y++) {
            for (int i = 0; i < sizeX; i ++) putwchar(L' ');
//            wprintf(CSI L"%dX", sizeX); //erase sizeX chars
            wprintf(CSI L"%dB", 1); // cursor down by one
            wprintf(CSI L"%dD", sizeX); //cursor back by sizeX
        }
    }

    /*draw at the new position*/
    wprintf(CSI L"%d;%df", posY, posX);
    for (int y = 0; y < sizeY; y++) {
        std::wstring sequence = entity.getPArt()[y];
        wprintf(L"%ls", sequence.c_str());
        wprintf(CSI L"%dB", 1);
        wprintf(CSI L"%dD", sizeX);
    }

    entity.setOldPosition(entity.getPosition());
}

void Screen::update() {
//    std::swap(nextBuf, currBuf);
//    memset(nextBuf, '\000', BUFSIZE);
//    wprintf(L"%ls", currBuf);
    fflush(stdout);
}

void Screen::clear() {
    wprintf(L"%s2J", CSI);  //clear the screen
}

const CONSOLE_SCREEN_BUFFER_INFO &Screen::getCsbiInfo() const {
    return csbiInfo;
}

