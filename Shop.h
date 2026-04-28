#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include <string>
#include <iostream>
#include "Item.h"
#include "Player.h"

// Shop represents a simple game shop where the player can buy and sell items.
class Shop {
private:
    // Items currently available for sale in the shop.
    std::vector<Item> items;

public:
    // Add an item to the shop's inventory.
    void addItem(Item item);

    // Display the shop's available items to the player.
    void displayItems() const;

    // Attempt to buy an item from the shop for the player.
    // Returns true when the purchase succeeds.
    bool buyItem(const std::string& name, Player& player);

    // Attempt to sell an item from the player back to the shop.
    // Returns true when the sale succeeds.
    bool sellItem(const std::string& name, Player& player);
};

#endif