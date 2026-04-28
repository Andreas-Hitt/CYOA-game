#include "Inventory.h"

// Add a new item to the inventory list.
// The item is copied into the internal vector.
void Inventory::add(Item item) {
    items.push_back(item);
}

// Remove the first item with a matching name.
// The method scans sequentially and erases the item if found.
// Returns true if removal was successful.
bool Inventory::remove(const std::string& name) {
    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i].name == name) {
            items.erase(items.begin() + i);
            return true;
        }
    }
    return false;
}

// Sort the inventory using bubble sort.
// This compares adjacent elements and swaps them when out of order,
// repeating passes until the full list is ordered by item name.
void Inventory::sort() {
    for (size_t i = 0; i < items.size(); ++i) {
        for (size_t j = 0; j < items.size() - 1 - i; ++j) {
            if (items[j].name > items[j + 1].name) {
                std::swap(items[j], items[j + 1]);
            }
        }
    }
}

// Search for an item by name using linear search.
// Each item is checked in order until a match is found.
// Return a pointer to the item, or nullptr when no item matches.
Item* Inventory::search(const std::string& name) {
    for (auto& item : items) {
        if (item.name == name) {
            return &item;
        }
    }
    return nullptr;
}

// Calculate the combined weight of all inventory items.
int Inventory::getTotalWeight() const {
    int total = 0;
    for (const auto& item : items) {
        total += item.weight;
    }
    return total;
}

// Return how many items are in the inventory.
int Inventory::getSize() const {
    return items.size();
}

// Provide read-only access to the internal list of items.
const std::vector<Item>& Inventory::getItems() const {
    return items;
}