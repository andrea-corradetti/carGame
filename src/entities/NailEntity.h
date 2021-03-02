//
// Created by Andrea on 27/01/2021.
//

#ifndef UNTITLEDCARGAME_NAILENTITY_H
#define UNTITLEDCARGAME_NAILENTITY_H


#include "NpcEntity.h"

class NailEntity : public NpcEntity {
public:
    NailEntity(const COORD &position, unsigned int id);

    void collisionWith(AbstractEntity &other) override;

    std::wstring *getArt() const override;

private:
    static std::wstring art[];
};


#endif //UNTITLEDCARGAME_NAILENTITY_H
