#include "Flashlight.h"
#include <algorithm>
#include <iostream>

// Create a flashlight with stats based on its tier.
Flashlight::Flashlight(Tier tier)
    : tier(tier), brightness(0), durability(0), value(0) {
    switch (tier) {
        case Tier::Basic:
            name = "Basic Flashlight";
            brightness = 30;
            durability = 50;
            value = 15;
            break;
        case Tier::Standard:
            name = "Standard Flashlight";
            brightness = 60;
            durability = 70;
            value = 35;
            break;
        case Tier::Premium:
            name = "Premium Flashlight";
            brightness = 90;
            durability = 90;
            value = 60;
            break;
    }
}

std::string Flashlight::getName() const {
    return name;
}

int Flashlight::getBrightness() const {
    return brightness;
}

int Flashlight::getDurability() const {
    return durability;
}

int Flashlight::getValue() const {
    return value;
}

// Set up the available flashlight options.
FlashlightManager::FlashlightManager() {
    flashlights.emplace_back(Flashlight::Tier::Basic);
    flashlights.emplace_back(Flashlight::Tier::Standard);
    flashlights.emplace_back(Flashlight::Tier::Premium);
}

// Show options to the player with their current stats.
void FlashlightManager::displayFlashlightOptions() const {
    std::cout << "\nChoose a flashlight:\n";
    for (size_t i = 0; i < flashlights.size(); i++) {
        const Flashlight& flash = flashlights[i];
        std::cout << " " << (i + 1) << ". " << flash.getName()
                  << " (Brightness: " << flash.getBrightness()
                  << ", Durability: " << flash.getDurability()
                  << ", Value: " << flash.getValue() << ")\n";
    }
}

// Select a flashlight by menu choice, returning nullptr if invalid.
const Flashlight* FlashlightManager::chooseFlashlight(int choice) const {
    if (choice < 1 || choice > (int)flashlights.size()) {
        return nullptr;
    }
    return &flashlights[choice - 1];
}

// Sorts flashlights by brightness with selection sort.
void FlashlightManager::sortFlashlightsByBrightness() {
    for (size_t i = 0; i < flashlights.size(); i++) {
        size_t maxIdx = i;
        for (size_t j = i + 1; j < flashlights.size(); j++) {
            if (flashlights[j].getBrightness() > flashlights[maxIdx].getBrightness()) {
                maxIdx = j;
            }
        }
        std::swap(flashlights[i], flashlights[maxIdx]);
    }
}

// Binary search by brightness value in a sorted flashlight list.
int FlashlightManager::findFlashlightIndex(int targetBrightness) const {
    int low = 0;
    int high = (int)flashlights.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int midValue = flashlights[mid].getBrightness();
        if (midValue == targetBrightness) {
            return mid;
        }
        if (midValue < targetBrightness) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}
