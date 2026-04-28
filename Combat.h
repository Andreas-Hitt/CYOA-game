#ifndef COMBAT_H
#define COMBAT_H

#include "Player.h"
#include "Enemy.h"

// Combat handles turn-based fights between the player and a single enemy.
class Combat {
public:
    // Conduct a fight until either the player or enemy is defeated.
    // Returns true when the player wins.
    bool fight(Player& player, Enemy& enemy);
};

#endif