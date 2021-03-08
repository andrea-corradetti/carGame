//
// Created by Andrea on 08/03/2021.
//

#ifndef UNTITLEDCARGAME_CLOCK_H
#define UNTITLEDCARGAME_CLOCK_H


#include <chrono>

typedef std::chrono::duration<double> duration;
typedef std::chrono::time_point<std::chrono::steady_clock> timePoint;

class Clock {
public:
    Clock();
    Clock(const duration &totalTime, const duration &dt, const timePoint &start, const timePoint &end,
          const duration &accumulator);

    void setStartToNow();

    void setEndtoNow();

    void updateClockValues();

    bool enoughTimeIsElapsed();

    void accountForElapsedTime();

public:
    const duration &getDt() const;

private:
    const duration dt = duration(1/60.);
    duration totalTime = duration(0);
    timePoint start = std::chrono::steady_clock::now();
    timePoint end = std::chrono::steady_clock::now();
    duration accumulator = duration(0);
    duration frameTime = duration(0);


};


#endif //UNTITLEDCARGAME_CLOCK_H
