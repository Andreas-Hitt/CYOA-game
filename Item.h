#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    std::string name;
    std::string rarity;
    int weight;
    int baseValue;
    float condition;

    Item(std::string n = "None", std::string r = "Common", int w = 1) 
        : name(n), rarity(r), weight(w), baseValue(0), condition(1.0f) {}
    Item(std::string n, int val, float cond, std::string rar);
    int getCalculatedValue() const;
};

#endif