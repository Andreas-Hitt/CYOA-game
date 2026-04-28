#include "SaveSystem.h"
#include <fstream>
#include <sstream>

// Save the player's state and current room index to a file.
void SaveSystem::save(const Player& player, size_t currentRoomIndex) {
    std::ofstream file(filename);
    if (!file) return;
    file << "health=" << player.getHealth() << std::endl;
    file << "money=" << player.getMoney() << std::endl;
    file << "luck=" << player.getLuck() << std::endl;
    file << "damage=" << player.getDamage() << std::endl;
    file << "currentRoom=" << currentRoomIndex << std::endl;
    file << "inventory=";
    auto items = player.getInventory().getItems();
    for (size_t i = 0; i < items.size(); ++i) {
        file << items[i].name;
        if (i < items.size() - 1) file << ",";
    }
    file << std::endl;
    file.close();
}

// Load saved player state and current room index from a file.
// Returns true when the load succeeds.
bool SaveSystem::load(Player& player, size_t& currentRoomIndex) {
    std::ifstream file(filename);
    if (!file) return false;
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string key, value;
        std::getline(ss, key, '=');
        std::getline(ss, value);
        if (key == "health") {
            int newHealth = std::stoi(value);
            player.adjustHealth(newHealth - player.getHealth());
        } else if (key == "money") {
            int newMoney = std::stoi(value);
            player.adjustMoney(newMoney - player.getMoney());
        } else if (key == "luck") {
            int newLuck = std::stoi(value);
            player.addLuck(newLuck - player.getLuck());
        } else if (key == "currentRoom") {
            currentRoomIndex = std::stoi(value);
        } else if (key == "inventory") {
            std::stringstream iss(value);
            std::string itemName;
            while (std::getline(iss, itemName, ',')) {
                if (!itemName.empty()) {
                    player.addItem(Item(itemName));
                }
            }
        }
    }
    file.close();
    return true;
}