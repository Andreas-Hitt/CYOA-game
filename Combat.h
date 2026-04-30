#ifndef COMBAT_H
#define COMBAT_H

#include "Player.h"
#include "Enemy.h"

class Combat {
public:
    bool fight(Player& player, Enemy& enemy);
};

#endif