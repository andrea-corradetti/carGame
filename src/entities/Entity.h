//
// Created by Andrea on 21/12/2020.
//

#ifndef UNTITLEDCARGAME_ENTITY_H
#define UNTITLEDCARGAME_ENTITY_H

#include <chrono>
#include <windows.h>
#include <string>

#include "../globals.h"

class Entity {
public:
    Entity(const COORD &position, const COORD &size, unsigned int id, int score);
    virtual void update() = 0;
    virtual void moveLeft();
    virtual void moveRight() ;
    virtual void moveUp();
    virtual void moveDown();
    bool intersect(Entity &e);
    virtual void collision(Entity &e) = 0;
    virtual void checkExpired();
    /*getters and setters*/
    const COORD &getPosition() const;
    const COORD &getOldPosition() const;
    const COORD &getSize() const;
    std::wstring *getPArt() const;
    const SMALL_RECT &getSrHitbox() const;
    unsigned int getId() const;
    bool isExpired() const;
    void setOldPosition(const COORD &oldPosition);

protected:

    void updateSrHitbox();
    int score;
public:
    int getScore() const;
    void setScore(int score);

protected:
    unsigned int id;
    bool expired;
    COORD size;
    COORD position, oldPosition;
    std::wstring *pArt;
    SMALL_RECT srHitbox;
    std::chrono::duration<int, std::milli> cooldown;

};


#endif //UNTITLEDCARGAME_ENTITY_H
