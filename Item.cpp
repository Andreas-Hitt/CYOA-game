#include "Item.h"

// Construct an item with a full set of properties.
Item::Item(std::string n, int val, float cond, std::string rar) 
    : name(n), baseValue(val), condition(cond), rarity(rar) {}

// Calculate the item's effective value.
// Rarity increases the multiplier, then condition scales down the final price.
int Item::getCalculatedValue() const {
    float rarityMult = 1.0f;
    if (rarity == "Rare") rarityMult = 2.0f;
    else if (rarity == "Legendary") rarityMult = 5.0f;
    
    return static_cast<int>(baseValue * rarityMult * condition);
}
