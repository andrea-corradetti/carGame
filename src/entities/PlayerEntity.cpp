//
// Created by Andrea on 22/12/2020.
//

#include "PlayerEntity.h"


std::wstring PlayerEntity::art[] = {L"aa", L"bb", L"cc"};


PlayerEntity::PlayerEntity(const COORD &position, int score = 0) : Entity(position, {2, 3}, score) {
    pArt = art;
}

/*
void PlayerEntity::collision(Entity &e) {

}*/
