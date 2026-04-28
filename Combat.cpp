#include "Combat.h"
#include <iostream>

// Run a turn-based fight between the player and a single enemy.
// The player attacks first, then the enemy attacks, until one is defeated.
bool Combat::fight(Player& player, Enemy& enemy) {
    std::cout << "\n>> A " << enemy.name << " appears! Health: " << enemy.health << std::endl;
    
    while (player.isAlive() && enemy.health > 0) {
        // Player turn
        std::cout << ">> You attack the " << enemy.name << " for " << player.getDamage() << " damage!" << std::endl;
        enemy.health -= player.getDamage();
        
        if (enemy.health <= 0) {
            std::cout << ">> You defeated the " << enemy.name << "!" << std::endl;
            return true;
        }
        
        // Enemy turn
        std::cout << ">> The " << enemy.name << " attacks you for " << enemy.damage << " damage!" << std::endl;
        player.adjustHealth(-enemy.damage);
        
        if (!player.isAlive()) {
            std::cout << ">> You were defeated by the " << enemy.name << "!" << std::endl;
            return false;
        }
    }
    return false;
}