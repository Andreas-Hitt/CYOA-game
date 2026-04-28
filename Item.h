#ifndef ITEM_H
#define ITEM_H

#include <string>

// Item represents a lootable object with rarity and condition modifiers.
// It stores the item properties and can calculate a dynamic value.
class Item {
public:
    std::string name;      // The display name of the item.
    std::string rarity;    // Rarity tier such as Common, Rare, Legendary.
    int weight;            // How heavy the item is for inventory logic.
    int baseValue;         // The base value before modifiers are applied.
    float condition;       // Represents item condition between 0 and 1.

    // Default constructor creates an empty item placeholder.
    Item(std::string n = "None", std::string r = "Common", int w = 1) 
        : name(n), rarity(r), weight(w), baseValue(0), condition(1.0f) {}

    // Full constructor initializes all item properties.
    Item(std::string n, int val, float cond, std::string rar);

    // Returns the final value after rarity and condition modifiers.
    int getCalculatedValue() const;
};

#endif