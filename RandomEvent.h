#ifndef RANDOMEVENT_H
#define RANDOMEVENT_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Player.h"

class RandomEvent {
public:
    RandomEvent();
    // Algorithm: Weighted Random Chance (Andreas)
    // Returns a string so main.cpp can handle the display logic
    std::string trigger(Player& player);
};

#endif