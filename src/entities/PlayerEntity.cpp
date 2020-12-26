//
// Created by Andrea on 22/12/2020.
//

#include "PlayerEntity.h"


std::wstring PlayerEntity::art[] = {L"aa", L"aa", L"aa"};



PlayerEntity::PlayerEntity(const COORD &position, const COORD &size, int score) : Entity(position, size, score = 0) {
/*    art = new std::wstring[3];
    std::wstring temp[] = {L"aa", L"aa", L"aa"};
    std::copy(temp, temp+3, art);*/
    pArt = art;
}

/*
void PlayerEntity::collision(Entity &e) {

}*/
