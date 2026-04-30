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
    const std::vector<Item>& getItems() const;
};

#endif