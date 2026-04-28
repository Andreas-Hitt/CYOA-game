#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "Item.h"
#include "Enemy.h"

// Room models a location in the game world.
// It contains a name, description, possible actions, items, and enemies.
class Room {
private:
    std::string name;
    std::string description;
    std::vector<std::string> actions;
    std::vector<Item> items;
    std::vector<Enemy> enemies;
    bool searched;

public:
    // Create a room with a name, description, action list, items, and enemies.
    Room(std::string n, std::string d, std::vector<std::string> a, std::vector<Item> i, std::vector<Enemy> e);

    // Mark whether the room has already been searched by the player.
    void setSearched(bool s) { searched = s; }
    bool isSearched() const { return searched; }

    // Access the items currently present in the room.
    std::vector<Item>& getItems() { return items; }
    const std::vector<Item>& getItems() const { return items; }

    // Access the enemies currently present in the room.
    std::vector<Enemy>& getEnemies() { return enemies; }
    const std::vector<Enemy>& getEnemies() const { return enemies; }

    // Remove all items from the room.
    void clearItems() { items.clear(); }

    // Room metadata accessors.
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    std::vector<std::string> getActions() const { return actions; }

    // Generate a string representation of the room.
    std::string toString() const;
};

#endif