#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <iostream>
#include "Item.h"
#include "Inventory.h"

// Player stores the current player's state, inventory, and helper methods.
class Player {
private:
    int health;
    int money;
    int luck;
    int damage;
    Inventory inventory;

public:
    // Initialize a new player with default stats.
    Player();

    // Modify the player's health by a positive or negative amount.
    void adjustHealth(int amount);
    // Modify the player's money by a positive or negative amount.
    void adjustMoney(int amount);
    // Increase the player's luck stat.
    void addLuck(int amount);
    // Add an item to the player's inventory.
    void addItem(Item item);

    // Accessor methods for player stats.
    int getHealth() const;
    int getMoney() const;
    int getLuck() const;
    int getDamage() const;
    int getInvSize() const;
    bool isAlive() const;
    
    // Display the player's current status and inventory contents.
    void displayStatus() const;

    // Provide mutable and const access to the player's inventory.
    Inventory& getInventory();
    const Inventory& getInventory() const;

    // Query whether the player has an item by name.
    bool hasItem(const std::string& name);
    // Remove an item by name from the player's inventory.
    void removeItem(const std::string& name);
};

#endif