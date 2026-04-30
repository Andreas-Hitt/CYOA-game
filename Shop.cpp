#include "Shop.h"
#include <iostream>

void Shop::addItem(Item item) { items.push_back(item); }

void Shop::displayItems() const {
    std::cout << "\n--- CASTLE SHOP ---" << std::endl;
    for (const auto& item : items) {
        std::cout << "- " << item.name << " | Price: " << item.price << "g | Wt: " << item.weight << std::endl;
    }
}

bool Shop::buyItem(const std::string& name, Player& player) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->name == name && player.getMoney() >= it->price) {
            player.adjustMoney(-it->price);
            player.addItem(*it);
            items.erase(it);
            return true;
        }
    }
    return false;
}

bool Shop::sellItem(const std::string& name, Player& player) {
    // Simplified sell logic: items sell for 50% of base price
    if (player.getInventory().remove(name)) {
        player.adjustMoney(10); // Flat sell price for simplicity
        return true;
    }
    return false;
}