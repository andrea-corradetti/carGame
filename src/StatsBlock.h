//
// Created by Andrea on 01/03/2021.
//

#ifndef UNTITLEDCARGAME_STATSBLOCK_H
#define UNTITLEDCARGAME_STATSBLOCK_H


class StatsBlock {
private:
    int score;
    int hp;
    int fuel;
public:
    StatsBlock();

public:
    int getScore() const;

    StatsBlock *setScore(int score);

    int getHp() const;

    StatsBlock *setHp(int hp);

    int getFuel() const;

    StatsBlock *setFuel(int fuel);

    int getLevel() const;

    StatsBlock *setLevel(int level);

    void reset();
private:
    int level;

};


#endif //UNTITLEDCARGAME_STATSBLOCK_H
