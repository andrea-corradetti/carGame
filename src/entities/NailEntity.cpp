//
// Created by Andrea on 27/01/2021.
//

#include "NailEntity.h"


#define NAIL_SIZE {1, 1}


std::wstring NailEntity::art[] = {L"^"};

void NailEntity::collisionWith(AbstractEntity &other) {
    expired = true;
}

NailEntity::NailEntity(const COORD &position, unsigned int id)
: NpcEntity(position, id, NAIL_SIZE, duration(1)) {}

std::wstring *NailEntity::getArt() const {
    return art;
}
