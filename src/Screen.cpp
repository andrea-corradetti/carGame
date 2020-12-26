//
// Created by Andrea on 19/12/2020.
//


#include "Screen.h"

Screen::Screen(HANDLE hStdin, HANDLE hStdout) : hStdin(hStdin), hStdout(hStdout){
    GetConsoleScreenBufferInfo(hStdout, &csbiInfo);

    GetConsoleMode(hStdin, &dwInMode_old);
    DWORD dwRequestedInModes = ENABLE_VIRTUAL_TERMINAL_INPUT;
    DWORD dwUndesiredInModes = ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT |ENABLE_INSERT_MODE;
    dwInMode = (dwInMode_old | dwRequestedInModes) & ~dwUndesiredInModes;
    if (!SetConsoleMode(hStdin, dwInMode)) {
        std::cout << "error hstdin\n" ;
    }

    GetConsoleMode(hStdout, &dwOutMode_old);
    DWORD dwRequestedOutModes = ENABLE_VIRTUAL_TERMINAL_PROCESSING | DISABLE_NEWLINE_AUTO_RETURN;
    dwOutMode = dwOutMode_old | dwRequestedOutModes;
    if (!SetConsoleMode(hStdout, dwOutMode)) {
        std::cout << "error hstdout\n";
    }
    wprintf(L"%s?25l", CSI);    //hide cursor


}

void Screen::drawEntity(Entity &entity) {
    short posX = entity.getPosition().X;
    short posY = entity.getPosition().Y;
    wprintf(L"%s%d;%dH", CSI, posY, posX); //set cursor position

    short sizeX = entity.getSize().X;
    short sizeY = entity.getSize().Y;

    for (int y = 0; y < sizeY; y++) {
        std::wstring sequence = entity.getPArt()[y];
        const wchar_t *seqArr = sequence.c_str();
        wprintf(L"%s", seqArr);
        wprintf(L"%s%dB", CSI, 1); // move cursor down by 1
        wprintf(L"%s%dD", CSI, sizeX); //move cursor back by sizeX
    }
}


void Screen::clear() {
    wprintf(L"%s2J", CSI);  //clear the screen
}

const CONSOLE_SCREEN_BUFFER_INFO &Screen::getCsbiInfo() const {
    return csbiInfo;
}

