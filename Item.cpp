#include "Item.h"

// Create an item with optional values and default common values.
Item::Item(std::string n, std::string r, int w, int p)
    : name(n), rarity(r), weight(w), price(p) {}
