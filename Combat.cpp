#include "Combat.h"
#include <iostream>

bool Combat::fight(Player& player, Enemy& enemy) {
    std::cout << "\n>> A " << enemy.name << " appears! (HP: " << enemy.health << ")" << std::endl;
    
    while (player.isAlive() && enemy.health > 0) {
        // Player attacks
        std::cout << ">> You strike for " << player.getDamage() << " damage!" << std::endl;
        enemy.health -= player.getDamage();
        
        if (enemy.health <= 0) {
            std::cout << ">> " << enemy.name << " defeated!" << std::endl;
            return true;
        }
        
        // Enemy attacks
        std::cout << ">> " << enemy.name << " hits you for " << enemy.damage << "!" << std::endl;
        player.adjustHealth(-enemy.damage);
    }
    return player.isAlive();
}