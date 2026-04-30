#include "SaveSystem.h"
#include <fstream>
#include <sstream>

void SaveSystem::save(const Player& player, size_t roomIdx) {
    std::ofstream file(filename);
    if (file) {
        // Save base stats and current room
        file << player.getHealth() << " " << player.getMoney() << " " 
             << player.getLuck() << " " << roomIdx << std::endl;
        
        // Save detailed item data: Name, Rarity, Condition, BaseValue
        for (const auto& item : player.getInventory().getItems()) {
            file << item.name << " " << item.rarity << " " 
                 << item.condition << " " << item.baseValue << "\n";
        }
    }
}

bool SaveSystem::load(Player& player, size_t& roomIdx) {
    std::ifstream file(filename);
    if (!file) return false;

    int h, m, l;
    if (!(file >> h >> m >> l >> roomIdx)) return false;
    
    // Reset player stats to saved values
    player.adjustHealth(h - player.getHealth());
    player.adjustMoney(m - player.getMoney());
    player.addLuck(l - player.getLuck());

    std::string name, rarity;
    float condition;
    int baseVal;

    // Read the multi-part item data
    while (file >> name >> rarity >> condition >> baseVal) {
        player.addItem(Item(name, rarity, 1, 0, condition, baseVal));
    }

    return true;
}