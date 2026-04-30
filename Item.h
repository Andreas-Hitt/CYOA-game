#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    std::string name;
    std::string rarity;
    int weight;
    int price;
    float condition;
    int baseValue;

    // The arguments are ordered to match the main.cpp calls: Name, Rarity, Weight, Price
    Item(std::string n = "None", std::string rar = "Common", int w = 1, int p = 0, float cond = 1.0, int val = 20);
    
    // Your calculation algorithm
    int getCalculatedValue() const;
};

#endif