#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <iostream>
#include "Item.h"
#include "Inventory.h" 

class Player {
private:
    int health;
    int money;  
    int luck;
    int damage;   
    Inventory inventory; 

public:
    Player();
    void adjustHealth(int amount);
    void adjustMoney(int amount); 
    void addLuck(int amount);
    void addItem(Item item);
    
    int getHealth() const { return health; }
    int getMoney() const { return money; }
    int getLuck() const { return luck; }
    int getDamage() const { return damage; }
    int getInvSize() const;
    bool isAlive() const { return health > 0; }
    
    void displayStatus() const;
    
    // Non-const version (for when you want to modify items)
    Inventory& getInventory() { return inventory; }
    
    // Const version (FIX: This allows read-only access for SaveSystem)
    const Inventory& getInventory() const { return inventory; }
    
    void sortInventoryByValue(); 
    int findItemIndex(int targetValue);
};

#endif