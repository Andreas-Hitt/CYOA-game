/*
Author: Andreas Hitt & Gemini
Class: RandomEvent
Description: Implementation of randomized attrition events.
*/
#include "RandomEvent.h"

RandomEvent::RandomEvent() {
    srand(static_cast<unsigned int>(time(0)));
}

/*
Algorithm: Weighted Random Chance (Attrition Engine)
Description: Uses a random roll modified by player stats to trigger events.
*/
void RandomEvent::trigger(Player& player) {
    int roll = rand() % 100;
    int luckMod = player.getLuck() / 2; 

    if (roll < 25) { 
        int dmg = (rand() % 15 + 10) - luckMod;
        if (dmg < 10) dmg = 10;
        std::cout << ">> [EVENT] A swarm of bats attacks! -" << dmg << " HP." << std::endl;
        player.adjustHealth(-dmg);
    } else if (roll > 75) { 
        int find = rand() % 25 + 5;
        std::cout << ">> [EVENT] You found a loose pouch of " << find << " gold!" << std::endl;
        player.adjustGold(find); 
    } else if (roll > 45 && roll < 55) { 
        std::cout << ">> [EVENT] You found a lucky charm! +2 Luck." << std::endl;
        player.addLuck(2);
    }
}