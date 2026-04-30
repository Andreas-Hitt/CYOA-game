#include "Item.h"

Item::Item(std::string n, std::string rar, int w, int p, float cond, int val) 
    : name(n), rarity(rar), weight(w), price(p), condition(cond), baseValue(val) {}

int Item::getCalculatedValue() const {
    float rarityMult = 1.0f;
    if (rarity == "Uncommon") rarityMult = 1.5f;
    else if (rarity == "Rare") rarityMult = 2.5f;
    else if (rarity == "Epic") rarityMult = 4.0f;
    else if (rarity == "Legendary") rarityMult = 7.0f;
    
    // Final Value = Base * Rarity Multiplier * Quality Modifier
    return static_cast<int>((baseValue * rarityMult) * condition);
}