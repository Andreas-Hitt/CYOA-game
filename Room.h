#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "Item.h"

// Room encapsulates a location in the adventure, its actions, and a possible item.
class Room {
private:
    std::string name;                  // Room name or location title.
    std::string description;           // Room description for display.
    std::vector<std::string> actions;  // Available actions for the player.
    Item item;                         // Item contained in this room.
    bool searched;                     // Whether the room has already been searched.

public:
    Room(std::string n, std::string d, std::vector<std::string> a, Item i);

    void setSearched(bool s) { searched = s; }
    bool isSearched() const { return searched; }
    Item getItem() const { return item; }
    void clearItem() { item = Item("None"); }
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    std::vector<std::string> getActions() const { return actions; }

    // Convert room info into a textual display string.
    std::string toString() const;
};

#endif