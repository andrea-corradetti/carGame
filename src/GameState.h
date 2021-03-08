//
// Created by Andrea on 30/01/2021.
//

#ifndef UNTITLEDCARGAME_GAMESTATE_H
#define UNTITLEDCARGAME_GAMESTATE_H

enum states {
    intro,
    menu,
    running,
    dead,
    quit, reset
};

class GameState {
public:

    GameState(states current = intro, bool changed = false);

    void changeStateTo(states nextState);
    bool isChanged() const;
    void setChanged(bool changed);
    states getCurrent() const;

private:
    bool changed;
    states current;



};

#endif //UNTITLEDCARGAME_GAMESTATE_H
