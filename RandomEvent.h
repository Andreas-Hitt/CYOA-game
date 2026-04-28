#ifndef RANDOMEVENT_H
#define RANDOMEVENT_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"

class RandomEvent {
public:
    RandomEvent();
    void trigger(Player& player);
};

#endif