#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    std::string name;
    std::string rarity;
    int weight;
    int price;
    float condition; // Represents quality (0.0 to 1.0)
    int baseValue;

    Item(std::string n = "None", std::string rar = "Common", int w = 1, int p = 0, float cond = 1.0, int val = 20);
    
    int getCalculatedValue() const;
};

#endif