//
// Created by Andrea on 05/03/2021.
//

#ifndef UNTITLEDCARGAME_POINTSENTITY_H
#define UNTITLEDCARGAME_POINTSENTITY_H


#include "NpcEntity.h"

class PointsEntity : public NpcEntity {
public:
    PointsEntity(const COORD &position, unsigned int id);

    void collisionWith(AbstractEntity &other) override;

    std::wstring *getArt() const override;
private:
    static std::wstring art[];
};


#endif //UNTITLEDCARGAME_POINTSENTITY_H
