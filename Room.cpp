#include "Room.h"

// Initialize a room with its name, description, action list, and contained item.
Room::Room(std::string n, std::string d, std::vector<std::string> a, Item i) 
    : name(n), description(d), actions(a), item(i), searched(false) {}

// Return a formatted string suitable for presenting the room to the player.
std::string Room::toString() const {
    return "Location: " + name + "\n" + description + "\n";
}