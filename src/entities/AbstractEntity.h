//
// Created by Andrea on 21/12/2020.
//

#ifndef UNTITLEDCARGAME_ABSTRACTENTITY_H
#define UNTITLEDCARGAME_ABSTRACTENTITY_H

#include <chrono>
#include <windows.h>
#include <string>
#include <map>
#include <vector>

#include "../globals.h"


class AbstractEntity {
public:
    AbstractEntity(const COORD &position, const COORD &size, unsigned int id);
    ~AbstractEntity();

    virtual void update();
    virtual void collision(AbstractEntity &other) = 0;  //todo maybe it should work only for pcs

    static void handleCollisionsWith(AbstractEntity& p);
    static std::vector<AbstractEntity *> getExpiredEntities();
    static void updateAll();
    static void deleteEntities(std::vector<AbstractEntity *> toDelete);

    virtual void moveLeft();
    virtual void moveRight();
    virtual void moveUp();
    virtual void moveDown();

    bool intersect(AbstractEntity &other) const;
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

    static std::map<unsigned int, AbstractEntity*> aliveMap;

protected:

    void updateSrHitbox();

    unsigned int id;
    bool expired;
    COORD size;
    COORD position, oldPosition;
    std::wstring *pArt;
    SMALL_RECT srHitbox;


};


#endif //UNTITLEDCARGAME_ABSTRACTENTITY_H
