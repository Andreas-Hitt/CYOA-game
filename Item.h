#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    std::string name;
    int baseValue;
    float condition; 
    std::string rarity; 

    Item(std::string n = "None", int val = 0, float cond = 1.0, std::string rar = "Common");
    int getCalculatedValue() const;
};

#endif