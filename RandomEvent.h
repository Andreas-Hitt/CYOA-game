#ifndef RANDOMEVENT_H
#define RANDOMEVENT_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"

// RandomEvent triggers chance-based events during gameplay.
// The event can affect the player's health, money, or luck depending
// on the random roll.
class RandomEvent {
public:
    // Initialize the random number generator seed.
    RandomEvent();

    // Trigger a random event that modifies the player's state.
    // Uses the player's luck to influence event outcomes.
    std::string trigger(Player& player);
};

#endif