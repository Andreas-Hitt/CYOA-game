#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <iostream>
#include "Item.h"

class Player {
private:
    int health;                      // Current player hit points.
    int gold;                        // Player currency.
    int luck;                        // Luck stat affecting events.
    std::vector<Item> inventory;     // Player inventory list.

public:
    Player();

    void adjustHealth(int amount);   // Add or subtract health.
    void adjustGold(int amount);     // Add or subtract gold.
    void addLuck(int amount);        // Increase luck stat.
    void addItem(Item item);         // Add an item to inventory.
    void sortInventoryByValue();     // Sort inventory highest to lowest value.
    int findItemIndex(int targetValue); // Binary search for item value.
    void removeItem(int index);      // Remove inventory item by index.
    int getTotalInventoryValue() const; // Sum of all item values.

    int getHealth() const;
    int getLuck() const;
    int getInvSize() const;
    bool isAlive() const;
    
    void displayStatus() const;      // Print current stats and inventory.
};

#endif