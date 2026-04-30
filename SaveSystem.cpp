#include "SaveSystem.h"
#include <fstream>

void SaveSystem::save(const Player& player, size_t roomIdx) {
    std::ofstream file(filename);
    if (file) {
        file << player.getHealth() << " " << player.getMoney() << " " 
             << player.getLuck() << " " << roomIdx << std::endl;
    }
}

bool SaveSystem::load(Player& player, size_t& roomIdx) {
    std::ifstream file(filename);
    if (!file) return false;
    int h, m, l;
    file >> h >> m >> l >> roomIdx;
    player.adjustHealth(h - player.getHealth());
    player.adjustMoney(m - player.getMoney());
    // Luck adjustment would go here
    return true;
}