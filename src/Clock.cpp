//
// Created by Andrea on 08/03/2021.
//

#include "Clock.h"

Clock::Clock(const duration &totalTime, const duration &dt, const timePoint &start, const timePoint& end,
             const duration &accumulator)
             : totalTime(totalTime), dt(dt), start(start), end(end), accumulator(accumulator) {}

void Clock::setStartToNow() {
    start = std::chrono::steady_clock::now();
}

void Clock::setEndtoNow() {
    end = std::chrono::steady_clock::now();
}

void Clock::updateClockValues() {
    frameTime = end - start;
    accumulator += frameTime;
    start = end;
}


void Clock::accountForElapsedTime() {
    accumulator -= dt;
    totalTime += dt;
}

bool Clock::enoughTimeIsElapsed() {
    return accumulator >= dt;
}

const duration &Clock::getDt() const {
    return dt;
};

Clock::Clock() = default;
