#ifndef SAVESYSTEM_H
#define SAVESYSTEM_H

#include "Player.h"
#include <string>

class SaveSystem {
private:
    std::string filename = "save.txt";
public:
    void save(const Player& player, size_t roomIdx);
    bool load(Player& player, size_t& roomIdx);
};

#endif