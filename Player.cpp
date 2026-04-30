#include "Player.h"
#include <algorithm>
#include <iomanip> // For formatting decimals

Player::Player() : health(100), money(50), luck(5), damage(10) {}

void Player::adjustHealth(int amount) { health += amount; }
void Player::adjustMoney(int amount) { money += amount; }
void Player::addLuck(int amount) { luck += amount; }
void Player::addItem(Item item) { inventory.add(item); }

int Player::getInvSize() const { return inventory.getSize(); }

void Player::sortInventoryByValue() {
    std::vector<Item>& items = const_cast<std::vector<Item>&>(inventory.getItems());
    for (size_t i = 0; i < items.size(); i++) {
        size_t maxIdx = i;
        for (size_t j = i + 1; j < items.size(); j++) {
            if (items[j].getCalculatedValue() > items[maxIdx].getCalculatedValue()) {
                maxIdx = j;
            }
        }
        std::swap(items[i], items[maxIdx]);
    }
}

int Player::findItemIndex(int targetValue) {
    const std::vector<Item>& items = inventory.getItems();
    int low = 0, high = (int)items.size() - 1;
    while (low <= high) {
        int mid = (high + low) / 2;
        int midVal = items[mid].getCalculatedValue();
        if (midVal == targetValue) return mid;
        if (midVal < targetValue) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

void Player::displayStatus() const {
    std::string conditionStr = (health < 30) ? "WOUNDED" : "HEALTHY";
    
    std::cout << "\n========================================" << std::endl;
    std::cout << " STATUS: " << conditionStr << " | HP: " << health 
              << " | Gold: " << money << " | Luck: " << luck << std::endl;
    std::cout << " INVENTORY:" << std::endl;
    
    if(inventory.getSize() == 0) {
        std::cout << "  [Empty]" << std::endl;
    } else {
        for (const auto& item : inventory.getItems()) {
            std::cout << "  - " << item.name 
                      << " [" << item.rarity << "]"
                      << " | Quality: " << (int)(item.condition * 100) << "%"
                      << " | Value: " << item.getCalculatedValue() << "g" << std::endl;
        }
    }
    std::cout << "========================================" << std::endl;
}