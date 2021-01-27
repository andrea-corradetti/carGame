//
// Created by Andrea on 27/01/2021.
//

#ifndef UNTITLEDCARGAME_NAILENTITY_H
#define UNTITLEDCARGAME_NAILENTITY_H


#include "NpcEntity.h"

class NailEntity : public NpcEntity {
public:
    NailEntity(const COORD &position, unsigned int id);

    void collision(AbstractEntity &other) override;
};


#endif //UNTITLEDCARGAME_NAILENTITY_H
