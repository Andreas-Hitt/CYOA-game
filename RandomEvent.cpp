#include "RandomEvent.h"

RandomEvent::RandomEvent() {
    srand(static_cast<unsigned int>(time(0)));
}

// Algorithm: Weighted Random Chance (Attrition Engine)
// This uses player Luck to mitigate damage, satisfying your feature requirements.
std::string RandomEvent::trigger(Player& player) {
    int roll = rand() % 100;
    int luckMod = player.getLuck() / 2; 

    if (roll < 25) { // 25% Chance: Bad Event
        int dmg = (rand() % 15 + 10) - luckMod;
        if (dmg < 5) dmg = 5; // Minimum damage floor
        player.adjustHealth(-dmg);
        return ">> [EVENT] A swarm of bats attacks! -" + std::to_string(dmg) + " HP.";
    } 
    else if (roll > 75) { // 25% Chance: Good Event
        int find = rand() % 25 + 5;
        player.adjustMoney(find);
        return ">> [EVENT] You found a loose pouch of " + std::to_string(find) + " gold!";
    } 
    else if (roll > 45 && roll < 55) { // 10% Chance: Luck gain
        player.addLuck(2);
        return ">> [EVENT] You found a lucky charm! +2 Luck.";
    }
    
    return ""; // No event triggered
}