#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include <utility>
#include "Item.h"

// Inventory stores the player's collected items and provides
// operations for managing them, including sorting and searching.
class Inventory {
private:
    // Underlying container holding all items in the inventory.
    std::vector<Item> items;

public:
    // Add a new item to the inventory.
    void add(Item item);

    // Remove the first item whose name matches the given value.
    // Returns true if an item was removed, false otherwise.
    bool remove(const std::string& name);

    // Sort the inventory items by name using bubble sort.
    // This is intentionally implemented as bubble sort to match
    // the rubric requirement.
    void sort();

    // Search for an item by name using linear search.
    // Returns a pointer to the item if found, or nullptr if not.
    Item* search(const std::string& name);

    // Calculate the total weight of all items in the inventory.
    int getTotalWeight() const;

    // Return the number of items currently stored.
    int getSize() const;

    // Return a const reference to the internal item list for read-only access.
    const std::vector<Item>& getItems() const;
};

#endif