//
// Created by Andrea on 22/12/2020.
//

#include "PlayerEntity.h"

#define PLAYER_SIZE {2, 3}

std::wstring PlayerEntity::art[] = {L"aa", L"bb", L"cc"};

PlayerEntity::PlayerEntity(const COORD &position, unsigned int id, int score)
    : Entity(position, PLAYER_SIZE, id, score) {
    pArt = art;
}

void PlayerEntity::collision(Entity &e) {

}

void PlayerEntity::update() {

}
