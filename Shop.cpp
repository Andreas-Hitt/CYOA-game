#include "Shop.h"
#include <iostream>

void Shop::addItem(Item item) { items.push_back(item); }

void Shop::displayItems() const {
    if (items.empty()) {
        std::cout << "(The shop is sold out!)" << std::endl;
        return;
    }
    for (const auto& item : items) {
        std::cout << "- " << item.name 
                  << " (" << item.rarity << ")"
                  << " | Buy: " << item.price << "g" << std::endl;
    }
}

bool Shop::buyItem(const std::string& name, Player& player) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->name == name) {
            if (player.getMoney() >= it->price) {
                player.adjustMoney(-it->price);
                player.addItem(*it);
                std::cout << ">> Purchased " << name << "!" << std::endl;
                items.erase(it);
                return true;
            } else {
                std::cout << ">> You can't afford that!" << std::endl;
                return false;
            }
        }
    }
    std::cout << ">> Merchant: 'I don't carry that here.'" << std::endl;
    return false;
}

bool Shop::sellItem(const std::string& name, Player& player) {
    // We search the inventory for the item to get its value before removing it
    Item* itemPtr = player.getInventory().linearSearchByName(name);
    
    if (itemPtr) {
        int sellVal = itemPtr->getCalculatedValue();
        player.adjustMoney(sellVal);
        player.getInventory().remove(name);
        std::cout << ">> Sold " << name << " for " << sellVal << " gold." << std::endl;
        return true;
    }
    return false;
}