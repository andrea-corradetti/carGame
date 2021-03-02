//
// Created by Andrea on 23/02/2021.
//

#include "GameState.h"


GameState::GameState(states current, bool changed) : current(current), changed(changed) {}

void GameState::changeStateTo(states nextState) {
    if (current != nextState) {
        current = nextState;
        changed = true;
    }
}

bool GameState::isChanged() const {
    return changed;
}

states GameState::getCurrent() const {
    return current;
}

void GameState::setChanged(bool changed) {
    GameState::changed = changed;
}
