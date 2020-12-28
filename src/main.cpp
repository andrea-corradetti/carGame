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
int maxPositionX = 20;
int maxPositionY = 20;


int main() {


    PlayerEntity e({5, 5}, 0);
    TestEntity t({8, 8}, {1, 1}, 0);

    Screen s(GetStdHandle(STD_INPUT_HANDLE), GetStdHandle(STD_OUTPUT_HANDLE));
    Controls c(GetStdHandle(STD_INPUT_HANDLE));

    while(true) {

            s.drawEntity(t);
            s.drawEntity(e);
            c.handleInput(e);
            //s.clear();
            s.update();
            usleep(25000);
    }

}
