//
// Created by Andrea on 23/12/2020.
//

#include <iostream>
#include <windows.h>
#include "Controls.h"

Controls::Controls(HANDLE hStdin) {
    this->hStdin = hStdin;
    GetConsoleMode(hStdin, &fdwOldMode);
}

void Controls::handleInput(Entity &e) {
    //GetConsoleMode(hStdin, &fdwOldMode);
    //SetConsoleMode(hStdin, fdwOldMode | fdwMode);
    GetNumberOfConsoleInputEvents(hStdin, &cNumToRead);
    if (cNumToRead > 0) {
        ReadConsoleInput(hStdin, irInBuf, 128, &cNumRead);

        for (i = 0; i < cNumRead; i++) {
            switch (irInBuf[i].EventType) {
                case KEY_EVENT:
                    procKeyEvent(irInBuf[i].Event.KeyEvent, e);
                    break;
                //todo add input events here
            }
        }
    }
    //SetConsoleMode(hStdin, fdwOldMode);
}

void Controls::procKeyEvent(KEY_EVENT_RECORD er, Entity &e) {
    switch (er.wVirtualKeyCode) {
        case VK_LEFT:
            e.moveLeft();
            break;
        case VK_RIGHT:
            e.moveRight();
            break;
        case VK_UP:
            e.moveUp();
            break;
        case VK_DOWN:
            e.moveDown();
            break;
        case VK_ESCAPE:
            //todo add menu function
            std::cout << "escape" << std::endl;
            break;

    }
}
