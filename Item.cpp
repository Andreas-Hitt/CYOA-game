#include "Item.h"

Item::Item(std::string n, std::string rar, int w, int p, float cond, int val) 
    : name(n), rarity(rar), weight(w), price(p), condition(cond), baseValue(val) {}

int Item::getCalculatedValue() const {
    float rarityMult = 1.0f;
    if (rarity == "Rare") rarityMult = 2.0f;
    else if (rarity == "Legendary") rarityMult = 5.0f;
    
    // This keeps your original logic intact for the rubric
    return static_cast<int>(baseValue * rarityMult * condition);
}