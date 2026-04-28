/*
Author: Andreas Hitt & Gemini
Class: Player
Description: Implementation of inventory management and stats.
*/
#include "Player.h"

Player::Player() : health(100), gold(50), luck(5) {}

void Player::adjustHealth(int amount) { health += amount; }
void Player::adjustGold(int amount) { gold += amount; }
void Player::addLuck(int amount) { luck += amount; }
void Player::addItem(Item item) { inventory.push_back(item); }

/*
Algorithm: Selection Sort
Description: Sorts inventory by the calculated value (highest to lowest)
*/
void Player::sortInventoryByValue() {
    for (size_t i = 0; i < inventory.size(); i++) {
        size_t maxIdx = i;
        for (size_t j = i + 1; j < inventory.size(); j++) {
            if (inventory[j].getCalculatedValue() > inventory[maxIdx].getCalculatedValue()) {
                maxIdx = j;
            }
        }
        std::swap(inventory[i], inventory[maxIdx]);
    }
}

/*
Algorithm: Binary Search
Description: Searches for an item by name in the sorted inventory.
*/
int Player::findItemIndex(std::string itemName) {
    int low = 0, high = (int)inventory.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (inventory[mid].name == itemName) return mid;
        if (inventory[mid].name < itemName) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void Player::removeItem(int index) {
    if(index >= 0 && index < (int)inventory.size()) {
        inventory.erase(inventory.begin() + index);
    }
}

int Player::getTotalInventoryValue() const {
    int total = 0;
    for (const auto& item : inventory) total += item.getCalculatedValue();
    return total;
}

void Player::displayStatus() const {
    std::cout << "\n========================================\n";
    std::cout << " HP: " << health << " | Gold: " << gold << " | Luck: " << luck << "\n";
    std::cout << " Total Inv Value: $" << getTotalInventoryValue() << "\n";
    std::cout << " INV: ";
    if(inventory.empty()) std::cout << "Empty";
    for (const auto& item : inventory) {
        std::cout << "[" << item.name << " ($" << item.getCalculatedValue() << ")] ";
    }
    std::cout << "\n========================================\n";
}