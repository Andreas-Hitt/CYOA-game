#ifndef RANDOMEVENT_H
#define RANDOMEVENT_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"

// RandomEvent manages chance-based encounters and modifies player stats.
class RandomEvent {
public:
    RandomEvent();

    // Trigger a random event that may damage, reward, or buff the player.
    void trigger(Player& player);
};

#endif