#include "Accessory.h"
#include <algorithm>
#include <iostream>

// Create a hat with attributes based on its type
Accessory::Accessory(Type type)
    : type(type), protection(0), luckBonus(0), value(0) {
    switch (type) {
        case Type::Fedora:
            name = "Fedora";
            protection = 2;
            luckBonus = 1;
            value = 25;
            break;
        case Type::Cowboy:
            name = "Cowboy Hat";
            protection = 3;
            luckBonus = 0;
            value = 30;
            break;
        case Type::Beanie:
            name = "Beanie";
            protection = 1;
            luckBonus = 2;
            value = 20;
            break;
    }
}

std::string Accessory::getName() const {
    return name;
}

int Accessory::getProtection() const {
    return protection;
}

int Accessory::getLuckBonus() const {
    return luckBonus;
}

int Accessory::getValue() const {
    return value;
}

// Populate the hat list with the available accessory options.
AccessoryManager::AccessoryManager() {
    hats.emplace_back(Accessory::Type::Fedora);
    hats.emplace_back(Accessory::Type::Cowboy);
    hats.emplace_back(Accessory::Type::Beanie);
}

// Print the available hat choices to the player.
void AccessoryManager::displayHatOptions() const {
    std::cout << "\nChoose a hat for your adventure:\n";
    for (size_t i = 0; i < hats.size(); i++) {
        std::cout << " " << (i + 1) << ". " << hats[i].getName()
                  << " (Protection: " << hats[i].getProtection()
                  << ", Luck: " << hats[i].getLuckBonus()
                  << ", Value: " << hats[i].getValue() << ")\n";
    }
}

// Return pointer to the chosen hat, or nullptr when the choice is invalid.
const Accessory* AccessoryManager::chooseHat(int choice) const {
    if (choice < 1 || choice > (int)hats.size()) return nullptr;
    return &hats[choice - 1];
}

// Sort hats by value using a simple selection sort.
void AccessoryManager::sortHatsByValue() {
    for (size_t i = 0; i < hats.size(); i++) {
        size_t maxIdx = i;
        for (size_t j = i + 1; j < hats.size(); j++) {
            if (hats[j].getValue() > hats[maxIdx].getValue()) {
                maxIdx = j;
            }
        }
        std::swap(hats[i], hats[maxIdx]);
    }
}

// Binary search the sorted hat list by value.
int AccessoryManager::findHatIndex(int targetValue) const {
    int low = 0;
    int high = (int)hats.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int midValue = hats[mid].getValue();

        if (midValue == targetValue) return mid;
        if (midValue < targetValue) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}
