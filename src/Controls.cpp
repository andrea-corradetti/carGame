//
// Created by Andrea on 23/12/2020.
//

#include <iostream>
#include <windows.h>
#include "Controls.h"
#include "entities/PlayerEntity.h"

Controls::Controls(HANDLE hStdin) {
    this->hStdin = hStdin;
    GetConsoleMode(hStdin, &fdwOldMode);
}

void Controls::playerInput() {
    GetConsoleMode(hStdin, &fdwOldMode);
    SetConsoleMode(hStdin, fdwOldMode | fdwMode);
    GetNumberOfConsoleInputEvents(hStdin, &cNumToRead);
    auto player = AbstractEntity::aliveEntities.at(1);
    if (cNumToRead > 0) {
        ReadConsoleInput(hStdin, irInBuf, 128, &cNumRead);

        for (i = 0; i < cNumRead; i++) {
            switch (irInBuf[i].EventType) {
                case KEY_EVENT:
                    procKeyEvent(irInBuf[i].Event.KeyEvent, *player);
                    break;
                //todo add input events here
            }
        }
    }
    SetConsoleMode(hStdin, fdwOldMode);
}

void Controls::introInput() {
    if (cNumToRead > 0) {
        ReadConsoleInput(hStdin, irInBuf, 128, &cNumRead);

        for (i = 0; i < cNumRead; i++) {
            switch (irInBuf[i].EventType) {
                case KEY_EVENT:
                    currGameState = gameState::running;
                    break;
            }
        }
    }
}

void Controls::procKeyEvent(KEY_EVENT_RECORD er, AbstractEntity &e) {
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

void Controls::handleInput(gameState currGameState) {
    GetConsoleMode(hStdin, &fdwOldMode);
    SetConsoleMode(hStdin, fdwOldMode | fdwMode);
    GetNumberOfConsoleInputEvents(hStdin, &cNumToRead);
    switch (currGameState) {
        case gameState::intro:
            introInput();
            break;
        case gameState::menu:
            //menuInput();
            break;
        case gameState::running:
            playerInput();
            break;
    }
    SetConsoleMode(hStdin, fdwOldMode);
}
