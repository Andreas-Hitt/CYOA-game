#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <iostream>
#include "Item.h"

class Player {
private:
    int health;
    int gold;
    int luck;
    std::vector<Item> inventory;

public:
    Player();

    void adjustHealth(int amount);
    void adjustGold(int amount);
    void addLuck(int amount);
    void addItem(Item item);
    void sortInventoryByValue();
    int findItemIndex(int targetValue);
    void removeItem(int index);
    int getTotalInventoryValue() const;

    int getHealth() const;
    int getLuck() const;
    int getInvSize() const;
    bool isAlive() const;
    
    void displayStatus() const;
};

#endif