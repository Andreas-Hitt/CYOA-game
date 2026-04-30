#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include <iostream>
#include "Item.h"

class Inventory {
private:
    std::vector<Item> items; // Data Structure 1: Vector

public:
    void add(Item item);
    bool remove(const std::string& name);
    
    void bubbleSortByName(); 
    Item* linearSearchByName(const std::string& name);

    int getTotalWeight() const;
    int getSize() const;
    
    // Read-only access for saving and displaying
    const std::vector<Item>& getItems() const { return items; }
    
    // NEW: Mutable access so the Player can sort the items
    std::vector<Item>& getItemsMutable() { return items; }
};

#endif