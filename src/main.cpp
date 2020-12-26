#include <iostream>
#include <windows.h>
#include <array>
#include <unistd.h>

#include "entities/Entity.h"
#include "Screen.h"
#include "entities/PlayerEntity.h"
#include "entities/TestEntity.h"
#include "Controls.h"
#include "globals.h"

int minPositionX = 0;
int minPositionY = 0;
int maxPositionX = 10;
int maxPositionY = 10;

int main() {
    PlayerEntity e({5, 5}, {2, 3}, 0);
    TestEntity t({8, 8}, {1, 1}, 0);

    Screen s(GetStdHandle(STD_INPUT_HANDLE), GetStdHandle(STD_OUTPUT_HANDLE));
    Controls c(GetStdHandle(STD_INPUT_HANDLE));

    while(true) {
        s.clear();
        s.drawEntity(e);
        s.drawEntity(t);
        c.handleInput(e);
    }


    s.clear();
    getchar();
}
