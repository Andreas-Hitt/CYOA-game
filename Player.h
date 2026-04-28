#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
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
    int getHealth() const { return health; }
    int getGold() const { return gold; }
    int getLuck() const { return luck; }
    int getInvSize() const { return (int)inventory.size(); }
    bool isAlive() const { return health > 0; }
    void sortInventoryByValue();
    int findItemIndex(int targetValue);
    void removeItem(int index);
    int getTotalInventoryValue() const;
    void displayStatus() const;
};

#endif