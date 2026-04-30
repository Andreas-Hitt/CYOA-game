#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include <string>
#include "Item.h"
#include "Player.h"

class Shop {
private:
    std::vector<Item> items;
public:
    void addItem(Item item);
    void displayItems() const;
    bool buyItem(const std::string& name, Player& player);
    bool sellItem(const std::string& name, Player& player);
};

#endif