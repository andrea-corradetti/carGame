//
// Created by Andrea on 23/12/2020.
//

#ifndef UNTITLEDCARGAME_CONTROLS_H
#define UNTITLEDCARGAME_CONTROLS_H

#include <windows.h>
#include "entities/AbstractEntity.h"

class Controls {
public:
    Controls(HANDLE hStdin);
    void handleInput(AbstractEntity &e);

private:
    HANDLE hStdin;
    DWORD fdwOldMode, cNumRead, cNumToRead, i;
    const DWORD fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    INPUT_RECORD irInBuf[128];

    void procKeyEvent(KEY_EVENT_RECORD er, AbstractEntity &e);

};



#endif //UNTITLEDCARGAME_CONTROLS_H
