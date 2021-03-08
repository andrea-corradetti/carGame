//
// Created by Andrea on 01/03/2021.
//

#include "StatsBlock.h"

int StatsBlock::getScore() const {
    return score;
}

StatsBlock *StatsBlock::setScore(int score) {
    StatsBlock::score = score;
    return this;
}

int StatsBlock::getHp() const {
    return hp;
}

StatsBlock *StatsBlock::setHp(int hp) {
    StatsBlock::hp = hp;
    return this;
}

int StatsBlock::getFuel() const {
    return fuel;
}

StatsBlock *StatsBlock::setFuel(int fuel) {
    StatsBlock::fuel = fuel;
    return this;
}

int StatsBlock::getLevel() const {
    return level;
}

StatsBlock *StatsBlock::setLevel(int level) {
    StatsBlock::level = level;
    return this;
}

StatsBlock::StatsBlock() : hp(0), fuel(0), score(0), level(0) {}


void StatsBlock::reset() {
    hp = 0;
    fuel = 0;
    score = 0;
    level = 0;
}