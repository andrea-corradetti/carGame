//
// Created by Andrea on 21/12/2020.
//

#ifndef UNTITLEDCARGAME_ENTITY_H
#define UNTITLEDCARGAME_ENTITY_H

#include <windows.h>
#include <string>

#include "../globals.h"

class Entity {
public:
    Entity(const COORD &position, const COORD &size, int score);
    virtual void moveLeft();
    virtual void moveRight() ;
    virtual void moveUp();
    virtual void moveDown();

    const COORD &getPosition() const;
    const COORD &getSize() const;
    std::wstring *getPArt() const;
    const SMALL_RECT &getSrHitbox() const;
protected:
    void updateSrHitbox();
    COORD size;
    COORD position;
    SMALL_RECT srHitbox;

protected:
    int score;
    std::wstring *pArt;


};


#endif //UNTITLEDCARGAME_ENTITY_H
