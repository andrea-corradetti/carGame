//
// Created by Andrea on 23/12/2020.
//

#ifndef UNTITLEDCARGAME_GLOBALS_H
#define UNTITLEDCARGAME_GLOBALS_H

#include <chrono>
#include <windows.h>
#include "GameState.h"

typedef std::chrono::duration<double> duration;

extern SMALL_RECT gameArea;
extern SMALL_RECT statsArea;
extern unsigned int levelNo;

extern GameState gameState ;




#endif //UNTITLEDCARGAME_GLOBALS_H
