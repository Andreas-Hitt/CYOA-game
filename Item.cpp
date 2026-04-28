/*
Author: Andreas Hitt & Gemini
Class: Item
Description: Implementation of Item value calculation logic.
*/
#include "Item.h"

Item::Item(std::string n, int val, float cond, std::string rar) 
    : name(n), baseValue(val), condition(cond), rarity(rar) {}

int Item::getCalculatedValue() const {
    float rarityMult = 1.0f;
    if (rarity == "Rare") rarityMult = 2.0f;
    else if (rarity == "Legendary") rarityMult = 5.0f;
    
    return static_cast<int>(baseValue * rarityMult * condition);
}