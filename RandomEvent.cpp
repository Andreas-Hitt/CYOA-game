#include "RandomEvent.h"

// Seed the random number generator when the RandomEvent system is created.
RandomEvent::RandomEvent() { srand(static_cast<unsigned int>(time(0))); }

// Trigger a random event that affects the player.
// The event outcome is determined by a random roll and the player's luck.
std::string RandomEvent::trigger(Player& player) {
    int roll = rand() % 100;
    int luckMod = player.getLuck() / 2;

    if (roll < 25) { // 25% chance Bad Event
        int dmg = (rand() % 15 + 10) - luckMod;
        if (dmg < 0) dmg = 0;
        player.adjustHealth(-dmg);
        return ">> [EVENT] A swarm of bats attacks! -" + std::to_string(dmg) + " HP.\n";
    } else if (roll > 75) { // 25% chance Good Event
        int find = rand() % 25 + 5;
        player.adjustMoney(find);
        return ">> [EVENT] You found a loose pouch of " + std::to_string(find) + " gold!\n";
    } else if (roll > 45 && roll < 55) { // 10% chance Luck Gain
        player.addLuck(2);
        return ">> [EVENT] You found a lucky charm! +2 Luck.\n";
    }
    return std::string();
}