//
// Created by Andrea on 08/03/2021.
//

#include "Clock.h"

Clock::Clock(const duration &totalTime, const duration &dt, const timePoint &start, const timePoint& end,
             const duration &accumulator) : totalTime(totalTime), dt(dt), start(start), end(end),
                                            accumulator(accumulator) {}
