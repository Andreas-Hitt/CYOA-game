#include "Room.h"

// Create a new room with the provided metadata, items, and enemies.
Room::Room(std::string n, std::string d, std::vector<std::string> a, std::vector<Item> i, std::vector<Enemy> e) 
    : name(n), description(d), actions(a), items(i), enemies(e), searched(false) {}

// Return a text description of the room for display purposes.
std::string Room::toString() const {
    return "Location: " + name + "\n" + description + "\n";
}