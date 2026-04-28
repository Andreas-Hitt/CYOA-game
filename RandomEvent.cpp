#include "RandomEvent.h"

// Seed the random number generator when the event system is created.
RandomEvent::RandomEvent() {
    srand(static_cast<unsigned int>(time(0)));
}

/*
Algorithm: Weighted Random Chance (Attrition Engine)
Description: Uses a random roll modified by player stats to trigger events.
*/
void RandomEvent::trigger(Player& player) {
    int roll = rand() % 100;                  // Base random roll.
    int luckMod = player.getLuck() / 2;       // Luck reduces damage on bad events.

    if (roll < 25) { 
        // Bad event: damage scaled by player luck.
        int dmg = (rand() % 15 + 10) - luckMod;
        if (dmg < 10) dmg = 10;
        std::cout << ">> [EVENT] A swarm of bats attacks! -" << dmg << " HP." << std::endl;
        player.adjustHealth(-dmg);
    } else if (roll > 75) { 
        // Good event: player finds gold.
        int find = rand() % 25 + 5;
        std::cout << ">> [EVENT] You found a loose pouch of " << find << " gold!" << std::endl;
        player.adjustGold(find); 
    } else if (roll > 45 && roll < 55) { 
        // Rare luck event.
        std::cout << ">> [EVENT] You found a lucky charm! +2 Luck." << std::endl;
        player.addLuck(2);
    }
}
