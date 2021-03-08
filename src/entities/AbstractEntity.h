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

enum entity_type {
    player,
    test,
    fuel,
    car,
    nail,
    points
};

class AbstractEntity {
public:
    AbstractEntity(const COORD &position, const COORD &size, unsigned int id);
    ~AbstractEntity();

    virtual void update(duration dt) = 0;
    virtual void collisionWith(AbstractEntity &other) = 0;  //todo maybe it should work only for pcs

    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void moveUp() = 0;
    virtual void moveDown() = 0;

    static void deleteExpiredEntities();
    static void updateExpiredEntities();
    static void updateAliveEntities(duration dt);
    static void handleCollisionsWith(AbstractEntity& other);

    bool intersect(AbstractEntity &other) const;
    virtual bool checkExpired();


    /*getters and setters*/
    const COORD &getPosition() const;
    const COORD &getOldPosition() const;
    const COORD &getSize() const;
    virtual std::wstring *getArt() const = 0;
    const SMALL_RECT &getHitbox() const;
    unsigned int getId() const;
    bool isExpired() const;


    static std::vector<AbstractEntity*> expiredEntities;
    static std::map<unsigned int, AbstractEntity*> aliveEntities;



protected:
    void updateHitbox();

    unsigned int id;
    bool expired;
    COORD size;
    COORD position, oldPosition;
    SMALL_RECT hitbox;
    duration timeElapsed;

private:
    static void deleteEntities(std::vector<AbstractEntity *> toDelete);
    static std::vector<AbstractEntity *> getExpiredEntities();

};


#endif //UNTITLEDCARGAME_ABSTRACTENTITY_H
