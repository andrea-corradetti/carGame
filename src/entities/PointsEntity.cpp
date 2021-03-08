//
// Created by Andrea on 05/03/2021.
//

#include "PointsEntity.h"
#define POINTS_SIZE {1, 1}

std::wstring PointsEntity::art[] = {L"*"};

void PointsEntity::collisionWith(AbstractEntity &other) {
    expired = true;
}

std::wstring *PointsEntity::getArt() const {
    return art;
}

PointsEntity::PointsEntity(const COORD &position, unsigned int id)
        : NpcEntity(position, id, POINTS_SIZE, duration(0.8)) {
    value = 25;
}
