#ifndef SAVESYSTEM_H
#define SAVESYSTEM_H

#include "Player.h"
#include <string>

// SaveSystem handles writing and restoring the player's game state.
// It stores health, money, luck, current room, and inventory contents.
class SaveSystem {
public:
    // Save the player's state and the current room index to a file.
    void save(const Player& player, size_t currentRoomIndex);

    // Load saved player state and current room index from a file.
    // Returns true if the load succeeds.
    bool load(Player& player, size_t& currentRoomIndex);
private:
    // File path used for saving and loading game state.
    std::string filename = "save.txt";
};

#endif