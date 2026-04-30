#include "SaveSystem.h"
#include <fstream>
#include <sstream>

void SaveSystem::save(const Player& player, size_t roomIdx) {
    std::ofstream file(filename);
    if (file) {
        file << player.getHealth() << " " << player.getMoney() << " " 
             << player.getLuck() << " " << roomIdx << std::endl;
        
        // This now calls the const version of getInventory()
        for (const auto& item : player.getInventory().getItems()) {
            file << item.name << " ";
        }
    }
}

bool SaveSystem::load(Player& player, size_t& roomIdx) {
    std::ifstream file(filename);
    if (!file) return false;

    int h, m, l;
    file >> h >> m >> l >> roomIdx;
    
    player.adjustHealth(h - player.getHealth());
    player.adjustMoney(m - player.getMoney());
    player.addLuck(l - player.getLuck());

    std::string itemName;
    while (file >> itemName) {
        player.addItem(Item(itemName));
    }

    return true;
}