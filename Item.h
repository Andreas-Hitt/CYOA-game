#ifndef ITEM_H
#define ITEM_H

#include <string>

// Item represents an object that the player can own, buy, or sell.
// Each item has a name, rarity, weight, and price.
class Item {
public:
    std::string name;
    std::string rarity;
    int weight;
    int price;

    // Create an item with optional values and default common values.
    Item(std::string n = "None", std::string r = "Common", int w = 1, int p = 0);
};

#endif