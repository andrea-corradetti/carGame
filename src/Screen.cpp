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

void Screen::drawAll(const std::map<unsigned int, Entity*>& eMap) {
    for (std::map<int, Entity*>::value_type e : eMap) {
        drawEntity(*e.second);
    }
}

void Screen::drawInterface() {
    wprintf(CSI L"%d;%df", 3, 3); //set cursor position (y, x)
    drawHorizontalLine(5, true);
    wprintf(CSI L"%d;%df", 4, 3);
    drawVerticalLine(5);



}

void Screen::drawHorizontalLine(int size, bool isTop) {
    wprintf(ESC L"(0"); //enter drawing mode
    wprintf(isTop? L"l" : L"m");
    for (int i = 1; i < size - 1; i++){
        printf("q");
    }
    wprintf(isTop? L"k" : L"j");
    //printf(CSI "0m"); // restore color
    wprintf(ESC L"(B"); // exit line drawing mode
}

void Screen::drawVerticalLine(int size) {
    wprintf(ESC L"(0"); //enter drawing mode
    for (int i = 0; i < size; i++){
        wprintf(L"x");
        wprintf(CSI L"%dB", 1); //cursor down by one
        wprintf(CSI L"%dD", 1); //cursor back by one
    }
    wprintf(ESC L"(B"); // exit line drawing mode
}

void Screen::drawAreaBorder(SMALL_RECT area) {
    wprintf(CSI L"%d;%df", area.Top-1, area.Left-1); //top border
    drawHorizontalLine(area.Right - area.Left + 3, true);
    wprintf(CSI L"%d;%df", area.Top, area.Left-1);  //left border
    drawVerticalLine(area.Bottom - area.Top + 1);
    wprintf(CSI L"%d;%df", area.Bottom+1, area.Left-1); //bottom border
    drawHorizontalLine(area.Right - area.Left + 3, false);
    wprintf(CSI L"%d;%df", area.Top, area.Right + 1); //right border
    drawVerticalLine(area.Bottom - area.Top + 1);

}

